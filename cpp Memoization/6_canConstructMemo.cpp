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

bool helper(std::string target, std::vector<std::string> arr, std::unordered_map<std::string, bool> &memo){
    if(memo.find(target) != memo.end()) return memo[target];
    if(target.empty()) return true;

    for(std::string word: arr){
        if(target.find(word) == 0){
            std::string suffix = target.substr(word.length(), target.length() - word.length());
            if(helper(suffix, arr, memo) == true){
                memo[target = true];
                return true;
            }
        }
    }
    memo[target] = false;
    return memo[target];
}

bool canConstruct(std::string s, std::vector<std::string> arr){
    std::unordered_map<std::string, bool> memo;
    return helper(s, arr, memo);
}

int main(int argc, char const *argv[])
{
    std::cout <<  canConstruct("purple", {"purp", "p", "ur", "le", "purpl"}) << std::endl;                       // True
    std::cout <<  canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << std::endl;                       // True
    std::cout <<  canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << std::endl;        //False
    std::cout <<  canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << std::endl;      //True
    std::cout <<  canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
        {"e", "ee", "eeee", "eeeeeeeee", "eee"}) << std::endl;                                                   //False
    return 0;
}