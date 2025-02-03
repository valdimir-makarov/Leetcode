#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int>& nums) {
    if (nums.empty()) return 0; 

    vector<int> dp(nums.size(), 1);
    int maxLen = 1; 

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << helper(nums) << endl;
    return 0;
}
