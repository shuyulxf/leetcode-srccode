var countBits = function(num) {
  if (!num) return [0];
  if (num == 1) return [0, 1];
  var rst = [0, 1],
      midRst = [1];

  for (var i = 2, j = 2, k = j*2; i <= num; i++) {
      var tmp = i % j,
          idx = Math.floor(tmp/2);

      if(tmp%2 == 0) rst.push(midRst[idx]);
      else rst.push(midRst[idx] + 1);

      if(i == k - 1) {
        midRst = rst.slice(j, k);
        j <<= 1;
        k <<= 1;
      }
  }
  return rst;
};