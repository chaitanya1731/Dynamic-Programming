#include <iostream>
#include <vector>
#include <unordered_map>
// Before Memoization
// O(2^m+n) time
// O(m+n) space

// After Memoization
// O(m*n) time
// O(m+n) space

long long helper(int m ,int n, std::unordered_map<std::string, long long>& memo){   
    std::string key = std::to_string(m) + '-' + std::to_string(n);
    
    if (memo.find(key) != memo.end())
        return memo[key];

    if(m == 1 and n == 1) return 1;
    if(m == 0 or n == 0) return 0;

    memo[key] = helper(m-1, n, memo) + helper(m, n-1, memo);
    return memo[key];
}

long long gridTraveller(int m, int n){
    std::unordered_map<std::string, long long> memo;
    return helper(m, n, memo);
}


int main(){
    std::cout << gridTraveller(1,1) << std::endl;
    std::cout << gridTraveller(2,3) << std::endl;
    std::cout << gridTraveller(3,3) << std::endl;
    std::cout << gridTraveller(10,10) << std::endl;
    std::cout << gridTraveller(18,18) << std::endl;
    return 0;
}