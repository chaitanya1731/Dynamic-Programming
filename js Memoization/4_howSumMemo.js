// Before Memoization
// O(n^m) time
// O(m) space

// After Memoization
// O(m*n) time
// O(m) space
const howSum = (target, nums, memo={}) => {
    if(target in memo) return memo[target];
    if(target === 0) return [];
    if(target < 0) return null;

    for(let n of nums){
        const remainder = target - n;
        const remainderResult = howSum(remainder, nums, memo);
        if(remainderResult !== null){
            const combination = [...remainderResult, n];
            memo[remainder] = combination;
            return memo[remainder];
        }
    }

    memo[target] = null;
    return null;
}

console.log(howSum(7, [2,3]))       // True  - [ 3, 2, 2 ]
console.log(howSum(7, [5,3,4,7]))   // True - [ 4, 3 ]
console.log(howSum(7, [2,4]))       // False - null
console.log(howSum(8, [2,3,5]))     // True - [ 2, 2, 2, 2 ]
console.log(howSum(300, [7,14]))    // False - null
