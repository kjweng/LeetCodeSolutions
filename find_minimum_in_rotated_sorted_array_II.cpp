class Solution {
public:
    int findMin(vector<int>& nums) {
        binarySearch(nums, 0, nums.size() - 1);
    }
private:
    int binarySearch(const vector<int>& nums, int lo, int hi) {
        int mid = (lo + hi) / 2;
        if (lo >= hi) {
            return nums[mid];
        }
        if (nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }
        if (nums[mid] < nums[mid -1]) {
            return nums[mid];
        }
        
        if (nums[mid] < nums[lo]) {
            return binarySearch(nums, lo, mid - 1);
        }
        if (nums[mid] > nums[hi]) {
            return binarySearch(nums, mid + 1, hi);
        }
        if (nums[mid] == nums[lo]) {
            return min(binarySearch(nums, mid + 1, hi), binarySearch(nums, lo, mid - 1));
        }
        return nums[lo];
    }
};