class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
private:
    int binarySearch(const vector<int>& nums, int target, int start, int end) {
        if (start > end) return -1;
        int mid = (start + end) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > nums[start]) {
            if (target < nums[mid] && target >= nums[start])
                return binarySearch(nums, target, start, mid - 1);
            else
                return binarySearch(nums, target, mid + 1, end);
        } else if (nums[mid] < nums[start]) {
            if (target > nums[mid] && target <= nums[end])
                return binarySearch(nums, target, mid + 1, end);
            else
                return binarySearch(nums, target, start, mid - 1);
        } else {
            if (nums[end] == nums[mid]) {
                int x = binarySearch(nums, target, start, mid - 1);
                if (x > -1) {
                    return x;
                } else {
                    return binarySearch(nums, target, mid + 1, end);
                }
            } else {
                return binarySearch(nums, target, mid + 1, end);
            }
        }
    }
};