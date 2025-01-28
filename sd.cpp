#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<int> first;
        unordered_map<int, int> hashTable;
        int i = 0;

        for (const auto& x : nums) {
            first.push_back(x);
            hashTable[x] = i;
            i++;
        }

        sort(nums.begin(), nums.end());
        return hashTable[nums[nums.size() - 1]];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3,1}; // Example input
    int peakIndex = solution.findPeakElement(nums);
    cout << "Index of the peak element: " << peakIndex << endl;
    return 0;
}
