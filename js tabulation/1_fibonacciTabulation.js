// Time - O(n)
// Space - O(n)

const fibonacci = (n) => {
    const dp = Array(n+1).fill(0);
    dp[1] = 1;

    for(let i=0; i<=n; i++){
        dp[i+1] += dp[i];
        dp[i+2] += dp[i];
    }

    return dp[n];
}


console.log(fibonacci(6))
console.log(fibonacci(7))
console.log(fibonacci(8))
console.log(fibonacci(50))