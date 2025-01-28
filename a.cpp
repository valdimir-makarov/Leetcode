#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Length of the sequence
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // If the sequence length is 1, no operations can be performed
        if (n == 1) {
            cout << a[0] << endl;
            continue;
        }

        // Calculate the maximum sum
        long long max_sum = 0;
        for (int i = 0; i < n; i++) {
            max_sum += abs(a[i]); // Sum the absolute values of all elements
        }

        cout << max_sum << endl; // Output the maximum possible sum
    }

    return 0;
}
