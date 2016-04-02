var binarySearch = function(Arr, x, left, right){
    if (!Arr || left > right ) return -1;

    var l = left, 
        r = right;

    while (l <= r) {
      var mid = l + Math.floor((r - l)/2),
          midEle = Arr[mid];
      if (x == midEle) return mid;
      else if (x < midEle) r = mid - 1;
      else l = mid + 1;
    }

    return -1;
}

var search = function(nums, target) {
    if (!nums || !nums.length) return -1;
    if(nums.length == 1) return nums[0] == target ? 0 : -1;
    
    var idx = -1,
        len = nums.length;

    for (var i = 0; i < len-1; i++) {
      if (nums[i] > nums[i+1]) {idx = i; break;}
    }
    if (idx != -1) {
        var tf = binarySearch(nums, target, 0, idx);
        if (tf != -1) return tf;
    }
    var tb = binarySearch(nums, target, idx+1, len-1);
    if (tb != -1) return tb;

    return -1;
}; 