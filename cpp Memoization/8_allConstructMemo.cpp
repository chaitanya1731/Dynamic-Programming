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

std::vector<std::vector<std::string>> helper(std::string target, std::vector<std::string> arr, std::unordered_map<std::string, std::vector<std::vector<std::string>>> &memo){
    if(memo.find(target) != memo.end()) return memo[target];
    if(target.empty()) return {{}};

    std::vector<std::vector<std::string>> combinations;
    for(std::string word: arr){
        if(target.find(word) == 0){
            std::string suffix = target.substr(word.length(), target.length() - word.length());
            std::vector<std::vector<std::string>> suffixWays = helper(suffix, arr, memo);
            for(int i=0; i< suffixWays.size(); i++){
                suffixWays[i].push_back(word);
                combinations.push_back(suffixWays[i]);
            }
        }
    }

    memo[target] = combinations;
    return combinations;
}

std::vector<std::vector<std::string>> allConstruct(std::string s, std::vector<std::string> arr){
    std::unordered_map<std::string, std::vector<std::vector<std::string>>> memo;
    return helper(s, arr, memo);
}

void print(std::vector<std::vector<std::string>> allCombination) {
    std::cout << "[" << std::endl;
    for(int i=0; i<allCombination.size(); ++i) {
        std::cout << "  [";
        
        for(int j=allCombination[i].size()-1; j>=0; --j) {
            std::cout << allCombination[i][j] << "  ";
        }
        std::cout << "]";
        std::cout << std::endl;
    }
    std::cout << "]";
    std::cout << std::endl << std::endl << std::endl;
}

int main(int argc, char const *argv[])
{
    print(allConstruct("purple", {"purp", "p", "ur", "le", "purpl"}));                       // True - [ [ 'purp', 'le' ], [ 'p', 'ur', 'p', 'le' ] ]
    print(allConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}));                       // True - [ [ 'abc', 'def' ] ]
    print(allConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}));        // False - []
    print(allConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}));      // True - 
    /*
    [
        [ 'enter', 'a', 'p', 'ot', 'ent', 'p', 'ot' ],
        [
            'enter', 'a',
            'p',     'ot',
            'ent',   'p',
            'o',     't'
        ],
        [
            'enter', 'a',
            'p',     'o',
            't',     'ent',
            'p',     'ot'
        ],
        [
            'enter', 'a',
            'p',     'o',
            't',     'ent',
            'p',     'o',
            't'
        ]
    ]
    */
    print(allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
        {"e", "ee", "eeee", "eeeeeeeee", "eee"}));                                                   // False - []
    return 0;
}