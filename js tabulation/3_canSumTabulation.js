// Before Memoization
// O(n^m) time
// O(m) space

// After Memoization
// O(m*n) time
// O(m) space

// After Tabulation
// Time - O(mn)
// Space - O(m)
// where m = target and n = array size


const canSum = (target, nums) => {
    const dp = Array(target+1).fill(false);
    dp[0] = true;

    for(let i=0; i<=target; i++){
        if(dp[i] === true){
            for(let num of nums){
                dp[i + num] = true;
            }
        }
    }

    return dp[target];
}

console.log(canSum(7, [2,3]))       // True
console.log(canSum(7, [5,3,4,7]))   // True
console.log(canSum(7, [2,4]))       // False
console.log(canSum(8, [2,3,5]))     // True
console.log(canSum(300, [7,14]))    // False