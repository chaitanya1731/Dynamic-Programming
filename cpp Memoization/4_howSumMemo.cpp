#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

// m = targetSum, n = numbers.size()
// BEFORE MEMOIZATION 
// Time = O((n^m) * m)
// Space = O(m*m)

// AFTER MEMOIZATION
// Time = O(m*n *m)
// Space = O(m^2)

std::vector<int> helper(int target, std::vector<int> arr, std::unordered_map<int, std::vector<int>>& memo){
    if(memo.find(target) != memo.end()) return memo[target];
    if(target == 0) return {};
    if(target < 0) return {INT_MIN};

    for (int num: arr) {
        int remainder = target - num;
        
        std::vector<int> remainderResult = helper(remainder, arr, memo);    
        if (remainderResult != std::vector<int>{INT_MIN}) {
            remainderResult.push_back(num);
            memo[remainder] = remainderResult;
            return memo[remainder];
        }
    }
    memo[target] = {INT_MIN};
    return {INT_MIN};
}

std::vector<int> howSum(int target, std::vector<int> arr){
    std::unordered_map<int, std::vector<int>> memo;
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
    print(howSum(7, {2,3}));       // True - [3 2 2 ]
    print(howSum(7, {5,3,4,7}));   // True - [4 3 ]
    print(howSum(7, {2,4}));       // False - null
    print(howSum(8, {2,3,5}));     // True - [2 2 2 2 ]
    print(howSum(300, {7,14}));    // False - null
    return 0;
}