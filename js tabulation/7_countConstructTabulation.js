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

const countConstruct = (target, wordbank) => {
    const dp = Array(target.length+1).fill(0);
    dp[0] = 1;

    for(let i=0; i<=target.length; i++){
        if(dp[i] != 0){
            for(let word of wordbank){
                if(target.slice(i, i+word.length) == word){
                    dp[i + word.length] += dp[i];
                }
            }
        }
    }

    return dp[target.length];
}


console.log(countConstruct("purple", ["purp", "p", "ur", "le", "purpl"]));                        // True - 2
console.log(countConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"]));                        // True - 1
console.log(countConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]));         // False - 0
console.log(countConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]));       // True - 4
console.log(countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
    ["e", "ee", "eeee", "eeeeeeeee", "eee"]));                                                  // False - 0