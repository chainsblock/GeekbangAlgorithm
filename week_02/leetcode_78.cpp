class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rest;
        vector<int> subset;
        rest.push_back(subset);
        recursion(rest, nums, subset, 0);
        return rest;
    }

    void recursion(vector<vector<int>> &rest, vector<int> &nums,
                    vector<int> &subset, int index) {
        if (index == nums.size()) return;

        recursion(rest, nums, subset, index + 1);

        subset.push_back(nums[index]);

        recursion(rest, nums, subset, index + 1);

        rest.push_back(subset);

        subset.pop_back();
    }
};