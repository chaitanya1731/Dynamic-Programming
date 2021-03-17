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

// m = targetSum, n = numbers.size()

std::vector<int> helper(int target, std::vector<int> arr, std::map<int, std::vector<int>>& memo){
    if(memo.find(target) != memo.end()) return memo[target];
    if(target == 0) return {};
    if(target < 0) return {INT_MIN};

    std::vector<int> smallestCombination{INT_MIN};
    for (int num: arr) {
        int remainder = target - num;
        
        std::vector<int> remainderCombination = helper(remainder, arr, memo);    
        if (remainderCombination != std::vector<int>{INT_MIN}) {
            std::vector<int> combination = remainderCombination;
            combination.push_back(num);
            
            if(smallestCombination == std::vector<int>{INT_MIN} || combination.size() < smallestCombination.size()){
                smallestCombination = combination;               
            }
            
        }
        
    }
    
    memo[target] = smallestCombination;
    return smallestCombination;
}

std::vector<int> bestSum(int target, std::vector<int> arr){
    std::map<int, std::vector<int>> memo;
    return helper(target, arr, memo);
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
    print(bestSum(7, {2,3}));       // True - [3 2 2 ]
    print(bestSum(7, {5,3,4,7}));   // True - [7 ]
    print(bestSum(7, {2,4}));       // False - null
    print(bestSum(8, {2,3,5}));     // True - [5 3 ]
    print(bestSum(300, {7,14}));    // False - null
    return 0;
}