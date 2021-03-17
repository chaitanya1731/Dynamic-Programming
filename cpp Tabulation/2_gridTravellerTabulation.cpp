#include <iostream>
#include <vector>

// Before Memoization
// O(2^m+n) time
// O(m+n) space

// After Memoization
// O(m*n) time
// O(m+n) space

// After Tabulation
// Time - O(mn)
// Space - O(mn)

// where m and n = size of matrix m*n;

long long gridTraveller(int m, int n){
    std::vector<std::vector<long long>> dp(m+1, std::vector<long long>(n+1, 0));
    dp[1][1] = 1;

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(j+1 <= n) dp[i][j+1] += dp[i][j];
            if(i+1 <= m) dp[i+1][j] += dp[i][j];
        }
    }
    
    return dp[m][n];
}


int main(){
    std::cout << gridTraveller(1,1) << std::endl;
    std::cout << gridTraveller(1,2) << std::endl;
    std::cout << gridTraveller(2,3) << std::endl;
    std::cout << gridTraveller(3,3) << std::endl;
    std::cout << gridTraveller(10,10) << std::endl;
    std::cout << gridTraveller(18,18) << std::endl;
    return 0;
}