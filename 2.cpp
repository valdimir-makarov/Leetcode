#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> helper(vector<int>& nums, int index, vector<int>& ds) {
    vector<vector<int>> result;

    // Base case: If index is equal to the size of nums, return the current subset.
    if (index == nums.size()) {
        result.push_back(ds);
        return result;
    }

    // Include the current element in the subset.
    ds.push_back(nums[index]);
    vector<vector<int>> include = helper(nums, index + 1, ds);
    ds.pop_back(); // Backtrack

    // Exclude the current element from the subset.
    vector<vector<int>> exclude = helper(nums, index + 1, ds);

    // Manually append elements from 'include' to 'result'
    for (const auto& subset : include) {
        result.push_back(subset);
    }

    // Manually append elements from 'exclude' to 'result'
    for (const auto& subset : exclude) {
        result.push_back(subset);
    }

    return result;
}

int main() {
    vector<int> nums = {3,5,4,2,4,6};
    vector<int> ds;

    // Generate all subsets using the helper function.
    vector<vector<int>> subsets = helper(nums, 0, ds);
vector<vector<int>>pairs;
    // Print all subsets.
    cout << "Subsets:" << endl;
    for (const auto& subset : subsets) {
       if(subset.size()==2){
         pairs.push_back(subset);
       }
    }
    for(const auto &x:pairs){
      cout << "{ ";
        for(const auto &y:x){
            cout<<
            "The subsest{"<<y<<"}";
        } cout << "}" << endl;
    }
   int maxValue = INT_MIN; // Initialize to a very small value
 
    for (const auto& pair : pairs) {
        int pairSum = pair[0] + pair[1];
        maxValue = max(pairSum, maxValue);
    }
cout << "Maximum Sum of Two Elements: " << maxValue << endl;

    
       

    return 0;
}
