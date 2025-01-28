#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    unordered_map<char, int> charMap;

    // Count the frequency of each character
    for (const auto &x : s) {
        charMap[x]++;
    }

    // Convert the map to a vector of pairs for sorting
    vector<pair<char, int>> charVector(charMap.begin(), charMap.end());

    // Sort the vector in descending order by value
    sort(charVector.begin(), charVector.end(),
         [](const pair<char, int> &a, const pair<char, int> &b) {
             return a.second > b.second; // Compare by value in descending order
         });

    // Print the sorted result
    cout << "Character frequencies:\n";
    for (const auto &pair : charVector) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    vector<char> charVec;
    for (auto &pair : charVector) { // Remove `const` since we modify `pair.second`
        while (pair.second > 0) {
            charVec.push_back(pair.first);
            pair.second--; // Decrease frequency
        }
    }

   
    cout << "\nExpanded characters in order:\n";
    for (const auto &ch : charVec) {
        cout << ch << " ";
    }
    cout << "\n";

    return 0;
}
