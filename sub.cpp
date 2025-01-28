#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Helper function to generate subsequences
void helper(vector<int>& nums, int index, vector<int>& ds, vector<vector<int>>& ans) {
    // Base case: If we've processed all elements
    if (index == nums.size()) {
        ans.push_back(ds); // Add the current subsequence to the result
        return;
    }

    // Include the current element in the subsequence
    ds.push_back(nums[index]);
    helper(nums, index + 1, ds, ans); // Recurse with the element included

    // Exclude the current element from the subsequence
    ds.pop_back(); // Backtrack
    helper(nums, index + 1, ds, ans); // Recurse without the element
}

// Function to check if a subsequence is strictly increasing
bool isIncreasing(const vector<int>& subsequence) {
    for (int i = 1; i < subsequence.size(); i++) {
        if (subsequence[i] <= subsequence[i - 1]) {
            return false; // Not strictly increasing
        }
    }
    return true;
}

// Function to find the Longest Increasing Subsequence (LIS)
int findLIS(vector<int>& nums) {
    vector<vector<int>> subsequences;
    vector<int> ds;

    // Generate all subsequences
    helper(nums, 0, ds, subsequences);

    int maxLength = 0;

    // Iterate through all subsequences
    for (const auto& subsequence : subsequences) {
        // Check if the subsequence is strictly increasing
        if (isIncreasing(subsequence)) {
            // Update the maximum length
            maxLength = max(maxLength, (int)subsequence.size());
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int length = findLIS(nums);

    cout << "Length of the Longest Increasing Subsequence: " << length << endl;
    return 0;
}
