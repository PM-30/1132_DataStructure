class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool Decreasing = true,Increasing = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                Decreasing = false;
            }
            if (nums[i] > nums[i + 1]) {
                Increasing = false;
            }
        }
        return Decreasing || Increasing;
    }
};
