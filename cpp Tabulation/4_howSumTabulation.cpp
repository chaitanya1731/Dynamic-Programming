#include <iostream>
#include <vector>
#include <climits>

// BEFORE MEMOIZATION 
// Time = O((n^m) * m)
// Space = O(m^2)

// AFTER MEMOIZATION
// Time - O(m^2 * n)
// Space = O(m^2)

// AFTER TABULATION
// Time - O(m^2 * n)
// Space - O(m^2)

// where m = targetSum, n = numbers.size()

std::vector<int> howSum(int target, std::vector<int> arr){
    std::vector<std::vector<int>> dp(target + 1, std::vector<int>{INT_MIN});
    dp[0] = {};

    for(int i=0; i<=target; i++){
        if(dp[i] != std::vector<int>{INT_MIN}){
            for(int num : arr){
                if(i+num <= target){
                    std::vector<int> combination = dp[i];
                    combination.push_back(num);
                    dp[i + num] = combination;
                }
            }
        }
    }

    return dp[target];
}

void print(std::vector<int> ans){
    for(int i: ans){
        if(i == INT_MIN)
            std::cout << "null";
        else
            std::cout << i << " ";
    }
    std::cout << std::endl; 
}

int main(int argc, const char** argv) {
    print(howSum(7, {2,3}));       // True - [3 2 2 ]
    print(howSum(7, {5,3,4,7}));   // True - [4 3 ]
    print(howSum(7, {2,4}));       // False - null
    print(howSum(8, {2,3,5}));     // True - [2 2 2 2 ]
    print(howSum(300, {7,14}));    // False - null
    return 0;
}