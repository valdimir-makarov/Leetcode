#include <bits/stdc++.h>
using namespace std;

void helper(vector<int>& nums, int i, vector<int>& ds, vector<vector<int>>& result) {
    if (i == nums.size()) {
        result.push_back(ds); 
        return;
    }
  
    // Include the current element
    ds.push_back(nums[i]);
    helper(nums, i + 1, ds, result);
  
    // Exclude the current element
    ds.pop_back();
    helper(nums, i + 1, ds, result);
}

int main() {
    vector<int> nums = {3,3,6,8}; 
    vector<vector<int>> result; 
    vector<int> ds; 
    int target = 10;  // Fixed missing semicolon
    helper(nums, 0, ds, result);

    int count = 0;

    for (int i = 0; i < result.size(); i++) {
        if (!result[i].empty()) {  // Ignore empty subarrays
            // Sort the subarray
            std::sort(result[i].begin(), result[i].end());
            int sum = result[i][0] + result[i][result[i].size() - 1];

            // Check if the condition is met
            if (sum <= target) {
                count++;
            }
        }
    }

    cout << "Count of valid subarrays: " << count << endl;
    return 0;
}
