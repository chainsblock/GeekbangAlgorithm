class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size());
    }

    int majority(vector<int> &nums, int s, int e) {
        if (s == e - 1) return nums[s];

        int mid = (s + e) / 2;
        
        int left = majority(nums, s, mid);
        int right = majority(nums, mid, e);

        if (left == right) {
            return left;
        }

        int left_cnt = countNum(nums, left, s, e);
        int right_cnt = countNum(nums, right, s, e);
        return left_cnt > right_cnt ? left : right;
    }
    
    int countNum(vector<int> &nums, int num, int s, int e) {
        int cnt = 0;
        for (int i = s; i < e; ++i) {
            if (nums[i] == num) ++cnt;
        }
        return cnt;
    }
};