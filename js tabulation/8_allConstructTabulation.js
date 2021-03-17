// BRUTE FORCE
// Time - O(n^m)
// Space - O(m)

// AFTER MEMOIZATION
// Time - O(n^m)
// Space - O(m)

// AFTER TABULATION
// Time - O(n^m)
// Space - O(n^m)

const allConstruct = (target, wordbank) => {
    const dp = Array(target.length + 1).fill().map(()=>[]);
    dp[0] = [[]];

    for(let i=0; i<=target.length; i++){
        if(dp[i].length > 0){
            for(const word of wordbank){
                if(target.slice(i, i+word.length) === word){
                    const combinations = dp[i];
                    const newCombinations = combinations.map((item)=>[...item, word]);
                    dp[i + word.length].push(...newCombinations);
                }
            }
        }
    }

    return dp[target.length];
}


console.log(allConstruct("purple", ["purp", "p", "ur", "le", "purpl"]));                        // True  [ [ 'purp', 'le' ], [ 'p', 'ur', 'p', 'le' ] ]
console.log(allConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"]));                        // True  [ [ 'abc', 'def' ] ]
console.log(allConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]));         // False []
console.log(allConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]));       // True
// [
//     [ 'enter', 'a', 'p', 'ot', 'ent', 'p', 'ot' ],
//     [
//       'enter', 'a',
//       'p',     'ot',
//       'ent',   'p',
//       'o',     't'
//     ],
//     [
//       'enter', 'a',
//       'p',     'o',
//       't',     'ent',
//       'p',     'ot'
//     ],
//     [
//       'enter', 'a',
//       'p',     'o',
//       't',     'ent',
//       'p',     'o',
//       't'
//     ]
//   ]

console.log(allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
    ["e", "ee", "eeee", "eeeeeeeee", "eee"]));                                                  // False []