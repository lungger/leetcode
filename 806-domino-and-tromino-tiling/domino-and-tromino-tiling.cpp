class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        if (n <= 1) return 1;
        if (n == 2) return 2;
        
        vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        long long sum = dp[0];  // 累積和：dp[0] + dp[1] + ... + dp[i-3]
        
        // for (int i = 3; i <= n; ++i) {
        //     dp[i] = (dp[i-1] + dp[i-2] + 2 * sum) % MOD;
        //     sum = (sum + dp[i-2]) % MOD;  // 更新累積和
        // }
        for (int i = 3; i <= n; ++i) {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
            
            // 加上 2 * (dp[i-3] + dp[i-4] + ... + dp[0])
            for (int j = i - 3; j >= 0; --j) {
                dp[i] = (dp[i] + 2 * dp[j]) % MOD;
            }
        }
        
        return dp[n];
    }
};