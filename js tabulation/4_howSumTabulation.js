// Before Memoization
// O(n^m) time
// O(m) space

// After Memoization
// O(m*n) time
// O(m) space

// After Tabulation
// Time - O(m^2 * n)
// Space - O(m^2)

// where m = target and n = size or arr

const howSum = (target, arr) => {
    const dp = Array(target + 1).fill(null);
    dp[0] = [];

    for(let i=0; i <= target; i++){
        if(dp[i] !== null){
            for(let num of arr){
                // if(dp[i+num] === null){
                    const combination = [...dp[i], num];
                    dp[i+num] = combination;
                // }
                
            }
        }
        
    }

    console.log(dp[293]);
    return dp[target];
}


// console.log(howSum(7, [2,3]))       // True  - [ 3, 2, 2 ]
// console.log(howSum(7, [5,3,4,7]))   // True - [ 4, 3 ]
// console.log(howSum(7, [2,4]))       // False - null
// console.log(howSum(8, [2,3,5]))     // True - [ 2, 2, 2, 2 ]
console.log(howSum(300, [7,14]))    // False - null
