var strStr = function(haystack, needle) {
    
    var l1 = haystack.length, l2 = needle.length;
    if (l1 < l2) return false;
    if (!l2) return 0;
    var next = getNext(needle);

    for (var i = 0, j = 0; i < l1; i++) {
    	while (j > 0 && haystack[i] != needle[j])	j = next[j-1];
    	if (haystack[i] == needle[j]) j++;
    	if (j == l2) 	return i - j + 1;
    }

    return -1;
};
function getNext(s) {
	var len = s.length;
	var next = [], j = 0; 
	next.push(0);

	for (var i = 1, j = 0; i < len; i++) {
		while (j > 0 && s[i] != s[j]) j = next[j-1];
		if (s[i] == s[j])	j++;
		next[i] = j;
	}

	return next;
}

//参考http://blog.csdn.net/joylnwang/article/details/6778316
//http://blog.csdn.net/buaa_shang/article/details/9907183