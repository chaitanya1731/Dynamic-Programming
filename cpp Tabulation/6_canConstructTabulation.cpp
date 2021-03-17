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

// AFTER TABULATION
// Time - O(m^2 * n)
// Space - O(m)

// m= target, n= wordbank.length()

//  create a table like - 

// Ex - target = abcdef, wordbank = ["ab", "abc", "cd", "def", "abcd"]
//      0    1   2   3   4   5   6
//      T    F   T   T   T   F   T
//      a    b   c   d   e   f   

// Meaning - 
//  if dp[0] = T,  then it is possible to construct word "" (empty string)
//  if dp[1] = F,  then it is NOT possible to construct word "a"
//  if dp[2] = T,  then it is possible to construct word "ab"

//  if dp[5] = F,  then it is NOT possible to construct word "abcde"
//  if dp[6] = T,  then it is possible to construct word "abcdef"

bool canConstruct(std::string target, std::vector<std::string> wordbank){
    std::vector<bool> dp(target.length() + 1, false);
    dp[0] = true;

    for(int i=0; i<=target.length(); i++){
        if(dp[i] == true){
            for(std::string word: wordbank){
                // if the word matches the characters starting at position i
                std::string str = target.substr(i, word.length());
                if(str == word){
                    dp[i + word.length()] = true;
                }

            }
        }
    }

    return dp[target.length()];
}

int main(int argc, char const *argv[])
{
    // std::cout <<  canConstruct("cats", {"dogs", "dog", "cat", "ss"}) << std::endl;                            // False
    std::cout <<  canConstruct("purple", {"purp", "p", "ur", "le", "purpl"}) << std::endl;                       // True
    std::cout <<  canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << std::endl;                       // True
    std::cout <<  canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << std::endl;        // False
    std::cout <<  canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << std::endl;      // True
    std::cout <<  canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
        {"e", "ee", "eeee", "eeeeeeeee", "eee"}) << std::endl;                                                   // False
    return 0;
}