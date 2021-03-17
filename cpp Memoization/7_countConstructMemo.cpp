#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
//BRUTE FORCE
// Time - O(n^m * m)
// Space - O(m^2)

// MEMOIZATION
// Time - O(n * m^2)
// Space - O(m^2)

int helper(std::string target, std::vector<std::string> arr, std::unordered_map<std::string, int> &memo){
    if(memo.find(target) != memo.end()) return memo[target];
    if(target.empty()) return 1;

    int countWays = 0;
    for(std::string word: arr){
        if(target.find(word) == 0){
            std::string suffix = target.substr(word.length(), target.length() - word.length());
            countWays += helper(suffix, arr, memo);
        }
    }

    memo[target] = countWays;
    return countWays;
}

int countConstruct(std::string s, std::vector<std::string> arr){
    std::unordered_map<std::string, int> memo;
    return helper(s, arr, memo);
}

int main(int argc, char const *argv[])
{
    std::cout <<  countConstruct("purple", {"purp", "p", "ur", "le", "purpl"}) << std::endl;                       // True - 2
    std::cout <<  countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << std::endl;                       // True - 1
    std::cout <<  countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << std::endl;        // False - 0
    std::cout <<  countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << std::endl;      // True - 4
    std::cout <<  countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
        {"e", "ee", "eeee", "eeeeeeeee", "eee"}) << std::endl;                                                   // False - 0
    return 0;
}