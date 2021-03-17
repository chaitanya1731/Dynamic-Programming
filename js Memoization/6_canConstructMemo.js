//BRUTE FORCE
// Time - O(n^m * m)
// Space - O(m^2)

// MEMOIZATION
// Time - O(n * m^2)
// Space - O(m^2)

const canConstruct = (target, wordbank, memo={}) => {
    if(target in memo) return memo[target];
    if (target === '') return true;

    for(let word of wordbank){
        if(target.indexOf(word) === 0){
            const suffix = target.slice(word.length);
            if(canConstruct(suffix, wordbank, memo) === true) {
                memo[target] = true;
                return memo[target];
            }
        }
    }

    memo[target] = false;
    return false;
}

console.log(canConstruct("purple", ["purp", "p", "ur", "le", "purpl"]));      // True
console.log(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"]));      // True
console.log(canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]));      //False
console.log(canConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]));      //True
console.log(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
    ["e", "ee", "eeee", "eeeeeeeee", "eee"]));      //False