var longestValidParentheses = function(s) {
    if (!s || s.length < 2) return 0;

    var len = s.length;
    var dp = new Array(len),
        maxLen = 0;
    
    for (var i = 0; i < len; i++) dp[i] = 0;
    for (var i = len - 2; i >= 0; i--) {
        if (s[i] == ")") dp[i] = 0;
        else {
            var j = i + 1 + dp[i+1];
            if (j < len && s[j] == ")") {
                dp[i] = dp[i+1] + 2;
                if (j+1 < len) dp[i] += dp[j+1];
            }
        }

        maxLen = Math.max(maxLen, dp[i]);
    }

   
    return maxLen;
};
