#include <iostream>
#include <vector>
#include <climits>
#include <map>

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

bool helper(int target, std::vector<int> arr, std::map<int, bool>& memo){
    if(memo.find(target) != memo.end()) return memo[target];
    if(target == 0) return true;
    if(target < 0) return false;

    for (int num : arr) {
        int remainder = target - num;

        if(helper(remainder, arr, memo) == true){
            memo[remainder] = true;
            return memo[remainder];
        }
        
    }
    memo[target] = false;
    return memo[target];
}

bool canSum(int target, std::vector<int> arr){
    std::map<int, bool> memo;
    return helper(target, arr, memo);
}


int main(int argc, const char** argv) {
    std::cout <<  canSum(7, {2,3}) << std::endl;       // True - []
    std::cout <<  canSum(7, {5,3,4,7}) << std::endl;   // True - []
    std::cout <<  canSum(7, {2,4}) << std::endl;       // False - null
    std::cout <<  canSum(8, {2,3,5}) << std::endl;     // True - []
    std::cout <<  canSum(300, {7,14}) << std::endl;    // False - null
    return 0;
}