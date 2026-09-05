class Solution {
    struct State {
        int r, c, e, mask;
    };
public:
    int minMoves(vector<string>& classroom, int energy) {
        int rows = classroom.size();
        int cols = classroom[0].size();
        
        // Fast 2D array lookup for litter IDs
        vector<vector<int>> litter_id(rows, vector<int>(cols, -1));
        int start_r = -1, start_c = -1;
        int num_litters = 0;
        
        // Map the classroom, track the start position and number the litter
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (classroom[r][c] == 'S') {
                    start_r = r;
                    start_c = c;
                } else if (classroom[r][c] == 'L') {
                    litter_id[r][c] = num_litters++;
                }
            }
        }
        
        // Base Case: No litter to clean
        if (num_litters == 0) return 0;
        
        // Initial mask: all litters uncollected (bits set to 1)
        int initial_mask = (1 << num_litters) - 1;
        
        // BFS Queue
        queue<State> q;
        q.push({start_r, start_c, energy, initial_mask});
        
        // max_energy[r][c][mask] tracks the highest energy achieved at this specific state
        // Initialized to -1 to denote unvisited states
        vector<vector<vector<int>>> max_energy(rows, 
            vector<vector<int>>(cols, vector<int>(1 << num_litters, -1)));
        
        max_energy[start_r][start_c][initial_mask] = energy;
        
        int moves = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [r, c, cur_e, mask] = q.front();
                q.pop();
                
                // If all litter is collected, we found the shortest path
                if (mask == 0) return moves;
                
                // Out of energy, cannot move further from this state
                if (cur_e == 0) continue;
                
                for (auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    
                    // Boundary and Obstacle checks
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && classroom[nr][nc] != 'X') {
                        char ch = classroom[nr][nc];
                        int nxt_e = cur_e - 1;
                        int nxt_mask = mask;
                        
                        // Apply cell logic for 'R' and 'L'
                        if (ch == 'R') {
                            nxt_e = energy; // Fully restore energy
                        } else if (ch == 'L') {
                            int id = litter_id[nr][nc];
                            if (mask & (1 << id)) { // If this litter hasn't been collected
                                nxt_mask ^= (1 << id); // Flip the bit to 0 to mark collected
                            }
                        }
                        
                        // Only queue if it leaves us with strictly more energy than prior visits
                        if (max_energy[nr][nc][nxt_mask] < nxt_e) {
                            max_energy[nr][nc][nxt_mask] = nxt_e;
                            q.push({nr, nc, nxt_e, nxt_mask});
                        }
                    }
                }
            }
            moves++;
        }
        
        return -1; // Impossible to collect all litter items
    }
};
