var searchRange = function(nums, target) {
    if (!nums || !nums.length) return -1;

    var len = nums.length,
        l = 0,
        r = len - 1,
        rst = [-1, -1];

    while (l <= r) {
        var mid = l + Math.floor((r - l)/2),
            midVal = nums[mid];

        if (midVal == target) {
            for (var i = mid; i >= l && nums[i] == target; i--) {}
            rst[0] = i + 1;
            for (i = mid; i <= r && nums[i] == target; i++) {}
            rst[1] = i - 1;
            break;
        } 
        else if (midVal < target) l = mid + 1;
        else r = mid - 1;
    }
    return rst;
};