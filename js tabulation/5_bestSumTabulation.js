// Before Memoization
// O(n^m) time
// O(m) space

// After Memoization
// O(m*n) time
// O(m) space

// AFTER TABULATION
// Time = O(m^2 * n)
// Space = O(m^2)

// m = targetSum, n = numbers.size()

const bestSum = (target, nums) => {
    const dp = Array(target+1).fill(null);
    dp[0] = [];

    for(let i=0; i<=target; i++){
        if(dp[i] != null){
            for(let num of nums){
                if(i+num <= target){
                    const combination = [...dp[i], num];
                    if(dp[i + num] == null || combination.length < dp[i+num].length){
                        dp[i+num] = combination;
                    }
                }
            }
        }
    }

    return dp[target];
}

console.log(bestSum(7, [2,3]))       // True  - [ 2, 2, 3 ]
console.log(bestSum(7, [5,3,4,7]))   // True - [ 7 ]
console.log(bestSum(7, [2,4]))       // False - null
console.log(bestSum(8, [2,3,5]))     // True - [ 3, 5 ]
console.log(bestSum(300, [7,14]))    // False - null
console.log(bestSum(8, [1,4,5]))     // True - [ 4, 4 ]
console.log(bestSum(100, [1,2,5,25]))// True - [ 25, 25, 25, 25 ]