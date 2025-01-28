#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Upper Bound Function
    int upperBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); // Use nums.size() for exclusive right boundary
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid; // Narrow the search to the left
            } else {
                left = mid + 1; // Move right if nums[mid] <= target
            }
        }
        return left; // Left will hold the position of the upper bound
    }

    // Lower Bound Function
    int lowerBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); // Use nums.size() for exclusive right boundary
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid; // Narrow the search to the left
            } else {
                left = mid + 1; // Move right if nums[mid] < target
            }
        }
        return left; // Left will hold the position of the lower bound
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 3, 5, 7, 9};
    int target = 3;

    // Call the upperBound function
    int result = solution.upperBound(nums, target);
    cout << "Upper Bound Index: " << result << endl; // Expected: 3

    // Call the lowerBound function
    int result2 = solution.lowerBound(nums, target);
    cout << "Lower Bound Index: " << result2 << endl; // Expected: 1

    return 0;
}
