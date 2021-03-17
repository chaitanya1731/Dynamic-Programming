// Before Memoization
// O(n^m) time
// O(m) space

// After Memoization
// O(m*n) time
// O(m) space
const bestSum = (target, nums, memo={}) => {
    if(target in memo) return memo[target];
    if(target === 0) return [];
    if(target < 0) return null;

    let shortestCombination = null;

    for(let n of nums){
        const remainder = target - n;
        const remainderResult = bestSum(remainder, nums, memo);
        if(remainderResult !== null){
            const combination = [...remainderResult, n];

            if(shortestCombination === null || combination.length < shortestCombination.length){
                shortestCombination = combination;
            }
            
        }
    }

    memo[target] = shortestCombination;
    return shortestCombination;
}

console.log(bestSum(7, [2,3]))       // True  - [ 3, 2, 2 ]
console.log(bestSum(7, [5,3,4,7]))   // True - [ 4, 3 ]
console.log(bestSum(7, [2,4]))       // False - null
console.log(bestSum(8, [2,3,5]))     // True - [ 2, 2, 2, 2 ]
console.log(bestSum(300, [7,14]))    // False - null