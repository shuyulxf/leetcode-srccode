/**
 * @constructor
 * @param {number[]} nums
 */

// for many times call ,we should cache the middle result.
var NumArray = function(nums) {
  var len = nums.length;
  var cache = [nums[0]];
  for (var i = 1; i < len; i++) {
    cache[i] = cache[i-1] + nums[i];
  }

  this.nums  = nums;
  this.cache = cache;
};

/**
 * @param {number} i
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
  var cache = this.cache;
  if (i < 0 || j < 0 || j < i)  return -1;
  else return  cache[j] - cache[i] + this.nums[i];
};


/**
 * Your NumArray object will be instantiated and called as such:
 * var numArray = new NumArray(nums);
 * numArray.sumRange(0, 1);
 * numArray.sumRange(0, 2);
 */