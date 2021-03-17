#include <iostream>
#include <vector>
#include <map>
#include <climits>

// BEFORE MEMOIZATION 
// Time =  O((n^m) * m)
// Space = O(m)

// AFTER MEMOIZATION
// Time = O(m^2 *n)
// Space = O(m^2)

// AFTER TABULATION
// Time = O(m^2 * n)
// Space = O(m^2)

// m = targetSum, n = numbers.size()

std::vector<int> bestSum(int target, std::vector<int> arr){
    std::vector<std::vector<int>> dp(target+1, std::vector<int>{INT_MIN});
    dp[0] = {};

    for(int i=0; i<= target; i++){
        if(dp[i] != std::vector<int>{INT_MIN}){
            for(int num: arr){
                if (i + num <= target){
                    std::vector<int> combination = dp[i];
                    combination.push_back(num);
                    if(dp[i + num] == std::vector<int>{INT_MIN} || combination.size() < dp[i + num].size()){
                        
                        
                        dp[i + num] = combination;
                    }
                    
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
    print(bestSum(7, {2,3}));       // True - [2 2 3 ]
    print(bestSum(7, {5,3,4,7}));   // True - [7 ]
    print(bestSum(7, {2,4}));       // False - null
    print(bestSum(8, {2,3,5}));     // True - [3 5 ]
    print(bestSum(300, {7,14}));    // False - null
    print(bestSum(8, {1,4,5}));     // True - [4 4 ]
    print(bestSum(100, {1,2,5,25}));    // True - [25 25 25 25 ]
    return 0;
}