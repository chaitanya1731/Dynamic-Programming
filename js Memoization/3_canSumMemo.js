// Before Memoization
// O(n^m) time
// O(m) space

// After Memoization
// O(m*n) time
// O(m) space
const canSum = (target, nums, dp={}) => {
    if(target in dp) return dp[target];
    if(target === 0) return true;
    if(target < 0) return false;

    for(let n of nums){
        const remainder = target - n;
        if(canSum(remainder, nums, dp) === true){
            dp[remainder] = true;
            return true;
        }
    }

    dp[target] = false;
    return false;
}

console.log(canSum(7, [2,3]))       // True
console.log(canSum(7, [5,3,4,7]))   // True
console.log(canSum(7, [2,4]))       // False
console.log(canSum(8, [2,3,5]))     // True
console.log(canSum(300, [7,14]))    // False
