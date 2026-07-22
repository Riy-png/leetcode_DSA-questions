class ZMaxSegmentTree {
    int n;
    vector<int> tree_sum, tree_pref, tree_suff, tree_mx;

    void build(const string& s, int node, int l, int r) {
        if (l == r) {
            int val = (s[l] == '0') ? 1 : 0;
            tree_sum[node] = 1;
            tree_pref[node] = val;
            tree_suff[node] = val;
            tree_mx[node] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        int lc = 2 * node, rc = 2 * node + 1;
        build(s, lc, l, mid);
        build(s, rc, mid + 1, r);
        
        tree_sum[node] = tree_sum[lc] + tree_sum[rc];
        tree_pref[node] = tree_pref[lc] + (tree_pref[lc] == tree_sum[lc] ? tree_pref[rc] : 0);
        tree_suff[node] = tree_suff[rc] + (tree_suff[rc] == tree_sum[rc] ? tree_suff[lc] : 0);
        tree_mx[node] = max({tree_mx[lc], tree_mx[rc], tree_suff[lc] + tree_pref[rc]});
    }

    struct NodeResult {
        int sum, pref, suff, mx;
    };

    NodeResult query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return {tree_sum[node], tree_pref[node], tree_suff[node], tree_mx[node]};
        }
        int mid = l + (r - l) / 2;
        if (qr <= mid) return query(2 * node, l, mid, ql, qr);
        if (ql > mid) return query(2 * node + 1, mid + 1, r, ql, qr);

        NodeResult left_res = query(2 * node, l, mid, ql, qr);
        NodeResult right_res = query(2 * node + 1, mid + 1, r, ql, qr);

        NodeResult res;
        res.sum = left_res.sum + right_res.sum;
        res.pref = left_res.pref + (left_res.pref == left_res.sum ? right_res.pref : 0);
        res.suff = right_res.suff + (right_res.suff == right_res.sum ? left_res.suff : 0);
        res.mx = max({left_res.mx, right_res.mx, left_res.suff + right_res.pref});
        return res;
    }

public:
    ZMaxSegmentTree(const string& s) {
        n = s.length();
        tree_sum.resize(4 * n, 0);
        tree_pref.resize(4 * n, 0);
        tree_suff.resize(4 * n, 0);
        tree_mx.resize(4 * n, 0);
        if (n > 0) build(s, 1, 0, n - 1);
    }

    int queryMaxZeros(int ql, int qr) {
        if (ql > qr) return 0;
        return query(1, 0, n - 1, ql, qr).mx;
    }
};

// Generic RMQ Segment Tree for Min/Max Range Queries on arrays
class RMQ {
    int n;
    bool is_min;
    vector<int> tree;

    void build(const vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(arr, 2 * node, l, mid);
        build(arr, 2 * node + 1, mid + 1, r);
        if (is_min) {
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        } else {
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];
        int mid = l + (r - l) / 2;
        int res = is_min ? 1e9 : -1e9;
        if (ql <= mid) {
            int val = query(2 * node, l, mid, ql, qr);
            res = is_min ? min(res, val) : max(res, val);
        }
        if (qr > mid) {
            int val = query(2 * node + 1, mid + 1, r, ql, qr);
            res = is_min ? min(res, val) : max(res, val);
        }
        return res;
    }

public:
    RMQ(const vector<int>& arr, bool is_min_flag) : is_min(is_min_flag) {
        n = arr.size();
        tree.resize(4 * max(1, n), is_min ? 1e9 : -1e9);
        if (n > 0) build(arr, 1, 0, n - 1);
    }

    int query(int ql, int qr) {
        if (ql > qr || n == 0) return is_min ? 1e9 : -1e9;
        return query(1, 0, n - 1, ql, qr);
    }
};
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) if (c == '1') total_ones++;

        // 1. Identify all contiguous blocks of '1's
        vector<int> runs_S, runs_E;
        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                int start = i;
                while (i < n && s[i] == '1') i++;
                runs_S.push_back(start);
                runs_E.push_back(i - 1);
            } else {
                i++;
            }
        }

        int K = runs_S.size();
        vector<int> X(K);
        for (int i = 0; i < K; ++i) {
            X[i] = runs_E[i] - runs_S[i] + 1;
        }

        vector<int> gaps(max(0, K - 1));
        for (int i = 1; i < K; ++i) {
            gaps[i - 1] = runs_S[i] - runs_E[i - 1] - 1;
        }

        vector<int> sum_gaps(K, -1);
        for (int k = 1; k < K - 1; ++k) {
            sum_gaps[k] = gaps[k - 1] + gaps[k];
        }

        // 2. Prebuild data structures
        ZMaxSegmentTree z_tree(s);
        RMQ x_min_rmq(X, true);
        RMQ gap_max_rmq(sum_gaps, false);

        vector<int> ans;
        ans.reserve(queries.size());

        // 3. Process each query
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            if (K == 0) {
                ans.push_back(0);
                continue;
            }

            int j_first = upper_bound(runs_S.begin(), runs_S.end(), l) - runs_S.begin();
            int j_last = lower_bound(runs_E.begin(), runs_E.end(), r) - runs_E.begin() - 1;

            if (j_first > j_last) {
                ans.push_back(total_ones);
                continue;
            }

            int Z_max = z_tree.queryMaxZeros(l, r);
            int min_X = x_min_rmq.query(j_first, j_last);

            int max_merge = 0;
            if (j_first == j_last) {
                int P_j = (j_first > 0) ? runs_E[j_first - 1] + 1 : 0;
                int Q_j = (j_first < K - 1) ? runs_S[j_first + 1] - 1 : n - 1;
                int Z_left = runs_S[j_first] - max(l, P_j);
                int Z_right = min(r, Q_j) - runs_E[j_first];
                max_merge = Z_left + Z_right;
            } else {
                int P_j = (j_first > 0) ? runs_E[j_first - 1] + 1 : 0;
                int Z_left_first = runs_S[j_first] - max(l, P_j);
                int Z_right_first = gaps[j_first];
                max_merge = max(max_merge, Z_left_first + Z_right_first);

                int Q_j = (j_last < K - 1) ? runs_S[j_last + 1] - 1 : n - 1;
                int Z_left_last = gaps[j_last - 1];
                int Z_right_last = min(r, Q_j) - runs_E[j_last];
                max_merge = max(max_merge, Z_left_last + Z_right_last);

                if (j_first + 1 <= j_last - 1) {
                    max_merge = max(max_merge, gap_max_rmq.query(j_first + 1, j_last - 1));
                }
            }

            int gain = max(max_merge, Z_max - min_X);
            ans.push_back(total_ones + gain);
        }

        return ans;
    }
};