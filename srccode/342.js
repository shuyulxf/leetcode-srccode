var isPowerOfFour = function(num) {
   if (num <= 0) return false;
   return Math.log2(num)%2===0? true : false; 
};