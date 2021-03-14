class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2) return;
        reverse(nums.begin(), nums.end());

        if (k > nums.size()) {
            k -= nums.size();
        }
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
