var longestValidParentheses = function(s) {
    if (!s || s.length < 2) return 0;

    var len = s.length,
        stack = [],
        maxLen = 0,
        start = -1;

    for (var i = 0; i < len; i++) {
        if (s[i] == "(") stack.push(i);
        else{
            if (stack.length) {
                var idx = stack.pop();
                if (!stack.length) maxLen = maxLen > i - start ? maxLen : i - start;
                else {
                    var tmp = i - stack.slice(-1);
                    maxLen = maxLen > tmp ? maxLen : tmp;
                }
            } else {
                start = i;
            }
        }
    }

    return maxLen;
};

console.log(longestValidParentheses("(()()"));
