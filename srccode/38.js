var countAndSay = function(n) {
  if ( n <= 0 ) return "";

  var rlt = "1";
  if (n === 1) return rlt;
  for (var i = 1; i < n; i++) {
    rlt += "#";
    var tmp = "", pre = rlt[0], cnt = 1;
    for (var j = 1 ; j < rlt.length; j++) {
      if (rlt[j] === pre) cnt++;
      else {
        tmp = tmp + cnt + pre;
        pre = rlt[j]; 
        cnt = 1;
      }
    }
    rlt = tmp;
  }

  return rlt;
}; 