//BRUTE FORCE
// Time - O(n^m * m)
// Space - O(m^2)

// MEMOIZATION
// Time - O(n * m^2)
// Space - O(m^2)

// AFTER TABULATION
// Time - O(m^2 * n)
// Space - O(m)

// m= target, n= arr.length()

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

const canConstruct = (target, wordbank) => {
    const dp = Array(target.length + 1).fill(false);
    dp[0] = true;

    for(let i=0; i<= target.length; i++){
        if(dp[i] === true){
            for(let word of wordbank){
                if(target.slice(i, i + word.length) === word){
                    dp[i + word.length] = true;
                }
            }
        }
    }

    return dp[target.length];
}

console.log(canConstruct("purple", ["purp", "p", "ur", "le", "purpl"]));      // True
console.log(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"]));      // True
console.log(canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]));      //False
console.log(canConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]));      //True
console.log(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
    ["e", "ee", "eeee", "eeeeeeeee", "eee"]));      //False