//BRUTE FORCE
// Time - O(n^m * m)
// Space - O(m^2)

// MEMOIZATION
// Time - O(n * m^2)
// Space - O(m^2)

const countConstruct = (target, wordbank, memo={}) => {
    if(target in memo) return memo[target];
    if (target === '') return 1;

    let countWays = 0;
    for(let word of wordbank){
        if(target.indexOf(word) === 0){
            const suffix = target.slice(word.length);
            const numOfWays = countConstruct(suffix, wordbank, memo);
            countWays += numOfWays;
        }
    }

    memo[target] = countWays;
    return countWays;
}


console.log(countConstruct("purple", ["purp", "p", "ur", "le", "purpl"]));                        // True - 2
console.log(countConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"]));                        // True - 1
console.log(countConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]));         // False - 0
console.log(countConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]));       // True - 4
console.log(countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
    ["e", "ee", "eeee", "eeeeeeeee", "eee"]));                                                  // False - 0