// BRUTE FORCE
// Time - O(n^m)
// Space - O(m)

// AFTER MEMOIZATION
// Time - O(n^m)
// Space - O(m)

const allConstruct = (target, wordbank, memo={}) => {
    if(target in memo) return memo[target];
    if(target === '') return [[]];

    let result = [];
    let res = [];
    let resultString = "";

    for(let word of wordbank){
        if(target.indexOf(word) === 0){
            const suffix = target.slice(word.length);
            const suffixWays = allConstruct(suffix, wordbank, memo);
            const targetWays = suffixWays.map(item => [word, ...item]);
            result.push(...targetWays);
            
            // resultString = targetWays.join(" ");
            // res.push(resultString);
        }
    }
    memo[target] = result;
    const temp = result.map(item => item.join(" "));
    console.log(temp);
    return result;
}


console.log(allConstruct("purple", ["purp", "p", "ur", "le", "purpl"]));                        // True  [ [ 'purp', 'le' ], [ 'p', 'ur', 'p', 'le' ] ]
// console.log(allConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"]));                        // True  [ [ 'abc', 'def' ] ]
// console.log(allConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]));         // False []
// console.log(allConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]));       // True
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

// console.log(allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", 
    // ["e", "ee", "eeee", "eeeeeeeee", "eee"]));                                                  // False []