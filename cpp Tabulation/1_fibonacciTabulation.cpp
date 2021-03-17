#include <iostream>
#include <vector>
// Time = O(n)
// Space = O(n)

/*
long long int fibonacci(int n){
    std::vector<long long int> dp(n+1, 0);
    dp[1] = 1;

    for(int i=0; i<=n; i++){
        if(i+1 <= n) dp[i + 1] += dp[i];
        if(i+2 <= n) dp[i + 2] += dp[i];
    }

    return dp[n];
}*/

long long int fibonacci(int n){
    std::vector<long long int> dp(n+1, 0);
    dp[1] = 1;

    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

int main(int argc, const char** argv) {
    std::cout <<  fibonacci(6) << std::endl;       
    std::cout <<  fibonacci(7) << std::endl;       
    std::cout <<  fibonacci(8) << std::endl;    
    std::cout <<  fibonacci(50) << std::endl;    
    return 0;
}