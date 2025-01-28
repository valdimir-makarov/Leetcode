#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Function to check if a substring is special (all characters are the same)
bool isSpecial(const string& substring) {
    char firstChar = substring[0];
    for (char c : substring) {
        if (c != firstChar) {
            return false; // Not special
        }
    }
    return true; // All characters are the same
}

// Brute force solution to find the longest special substring that occurs at least thrice
int longestSpecialSubstring(string s) {
    int n = s.size();
    int maxLength = -1;

    // Iterate through all possible substrings
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            string substring = s.substr(i, j - i); // Extract substring from i to j-1

            // Check if the substring is special
            if (isSpecial(substring)) {
                // Count occurrences of the substring in the original string
                int count = 0;
                size_t pos = s.find(substring);
                while (pos != string::npos) {
                    ++count;
                    pos = s.find(substring, pos + 1);
                }

                // If it occurs at least thrice, update the maximum length
                if (count >= 3) {
                    maxLength = max(maxLength, (int)substring.size());
                }
            }
        }
    }

    return maxLength;
}

int main() {
    string s = "bubunbuubuuuuubububububu";
    int result = longestSpecialSubstring(s);

    cout << "The length of the longest special substring that occurs at least thrice is: " << result << endl;
    return 0;
}
