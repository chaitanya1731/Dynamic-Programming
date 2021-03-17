// Time - O(nm)
// Space - O(nm)

const gridTraveller = (m, n) => {
    const dp = Array(m+1).fill().map(() => Array(n+1).fill(0));
    dp[1][1] = 1;

    for(let i=0; i<=m; i++){
        for(let j=0; j<=n; j++){
            if(j+1 <= n) dp[i][j+1] += dp[i][j];
            if(i+1 <= m) dp[i+1][j] += dp[i][j];
        }
    }
    return dp[m][n];
}


console.log(gridTraveller(1,1))
console.log(gridTraveller(2,3))
console.log(gridTraveller(3,3))
console.log(gridTraveller(10,10))
console.log(gridTraveller(15,15))
console.log(gridTraveller(18,18))