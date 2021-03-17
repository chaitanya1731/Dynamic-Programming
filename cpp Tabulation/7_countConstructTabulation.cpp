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

//  create a table like - 

// Ex - target = purple, wordbank = ["purp", "p", "ur", "le", "purpl"]
//      0    1   2   3   4   5   6
//      1    1   0   1   2   1   1
//      p    u   r   p   l   e   

// Meaning - 
//  if dp[0] = 1,  then it is possible to construct word "" (empty string) in 1 way
//  if dp[1] = 1,  then it is possible to construct word "p" in 1 way
//  if dp[2] = 0,  then it is NOT possible to construct word "pu" i.e. 0 ways

//  if dp[5] = 1,  then it is possible to construct word "purpl" in 1 way
//  if dp[6] = 1,  then it is possible to construct word "purple" in 2 ways

int countConstruct(std::string target, std::vector<std::string> wordbank){
    std::vector<int> dp(target.length() + 1, 0);
    dp[0] = 1;

    for(int i=0; i<=target.length(); i++){
        if(dp[i] != 0){
            for(std::string word: wordbank){
                std::string str = target.substr(i, word.length());
                if(str == word){
                    dp[i + word.length()] += dp[i];
                }
            }
        }
    }

    return dp[target.length()];
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