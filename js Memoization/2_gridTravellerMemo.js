const dp = {};

const gridTraveller = (m, n, dp) => {
    const key = m + "-" + n;

    if (key in dp)
        return dp[key];

    if(m == 1 && n == 1) return 1;
    if(m == 0 || n == 0) return 0;

    dp[key] = gridTraveller(m-1, n, dp) + gridTraveller(m, n-1, dp);
    return dp[key];
}

console.log(gridTraveller(1,1, dp))
console.log(gridTraveller(2,3, dp))
console.log(gridTraveller(3,3, dp))
console.log(gridTraveller(10,10, dp))
console.log(gridTraveller(15,15, dp))
console.log(gridTraveller(18,18, dp))

// O(m*n) time
// O(m+n) space