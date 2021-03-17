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
// Time - O(n^m)
// Space - O(n^m)
using namespace std;

vector<vector<string>> allConstruct(string target, vector<string> wordbank){
    vector<vector<vector<string>>> dp(target.length() + 1, vector<vector<string>>{});
    dp[0].push_back({});

    for(int i=0; i<dp.size(); i++){
        if(dp[i].size()){
            for(string word: wordbank){
                if(target.substr(i, word.length()) == word){
                    vector<vector<string>> allCombinations = dp[i];
                    
                    for(int j=0; j<allCombinations.size(); j++){
                        vector<string> newCombination = allCombinations[j];
                        newCombination.push_back(word);
                        allCombinations[j] = (newCombination);
                        dp[i + word.length()].push_back(allCombinations[j]);
                    }
                }
            }
        }
    }


    return dp[target.length()];
}

void print(vector<vector<string>> allCombination) {
    cout << "[" << endl;
    for(int i=0; i<allCombination.size(); ++i) {
        cout << "  [";
        
        for(int j=0; j<allCombination[i].size(); j++) {
            cout << allCombination[i][j] << "  ";
        }
        cout << "]";
        cout << endl;
    }
    cout << "]";
    cout << endl << endl << endl;
}


int main(int argc, char const *argv[])
{
    print(allConstruct("purple", {"purp", "p", "ur", "le", "purpl"}));                       // True - [ [ 'purp', 'le' ], [ 'p', 'ur', 'p', 'le' ] ]
    print(allConstruct("catsanddog", {"cat","cats","and","sand","dog"}));                       // True - [ ['cat', 'sand', 'dog'],['cats', 'and', 'dog'] ]
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