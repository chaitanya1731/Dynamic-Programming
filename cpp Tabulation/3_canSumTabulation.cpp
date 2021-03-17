#include <iostream>
#include <vector>
using namespace std;
// Before Memoization
// O(n^m) time
// O(m) space

// After Memoization
// O(m*n) time
// O(m) space

// After Tabulation
// Time - O(mn)
// Space - O(m)
// where m = target and n = array size

bool canSum(int target, vector<int> arr){
    vector<bool> dp(target+1, false);
    dp[0] = true;

    for(int i=0; i<=target; i++){
        if(dp[i] == true){
            for(int j=0; j<arr.size(); j++){
                // if((i + arr[j]) <= target)
                    dp[i+arr[j]] = dp[i];
            }
        }
    }
    return dp[target];
}


int main(int argc, const char** argv) {
    cout <<  canSum(7, {2,3}) << endl;       // True - []
    cout <<  canSum(7, {5,3,4,7}) << endl;   // True - []
    cout <<  canSum(7, {2,4}) << endl;       // False - null
    cout <<  canSum(8, {2,3,5}) << endl;     // True - []
    cout <<  canSum(300, {7,14}) << endl;    // False - null
    return 0;
}