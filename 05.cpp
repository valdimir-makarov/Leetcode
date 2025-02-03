#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> minOperations(vector<int>&nums) {
    int n = nums.size();
    vector<int> result(n, 0);

int multi1 =1;
for( int i =0;i<n;i++){
result[i]=multi1;
multi1 =multi1  * nums[i];

}
for(auto &x:result){
    cout<<x<<"fir"<<endl;
}
int multi2=1;
for(int  i=n-1;i>=0;i--){
result[i] *=multi2;
multi2 =multi2  * nums[i];


}

    return result;
}

int main() {
   vector<int>nums={1,2,3,4};
    vector<int> result = minOperations(nums);

    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}