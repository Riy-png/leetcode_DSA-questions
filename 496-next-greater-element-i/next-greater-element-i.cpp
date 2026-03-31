class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> Ans;

        for(int i = 0; i < nums1.size(); i++) {
            int element = nums1[i];
            int nextGreater = -1;
            int j;
            for(j = 0; j < nums2.size(); j++) {
                if(nums2[j] == element) {
                    break;
                }
            }

            // Step 2: Find next greater element
            for(int k = j + 1; k < nums2.size(); k++) {
                if(nums2[k] > element) {
                    nextGreater = nums2[k];
                    break;
                }
            }

            Ans.push_back(nextGreater);
        }

        return Ans;
    }
};