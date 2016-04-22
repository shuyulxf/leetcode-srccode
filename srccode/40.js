var combinationSum2 = function(candidates, target) {
  candidates.sort(function(x, y) {
    return x - y;
  })
  var rst = [];
  dfs(candidates, candidates.length, 0, target, 0, [], rst);
  
  return rst;
};

var dfs = function(c, l, k, t, s, sa, rst){
    if (s > t) return;
    else if (s === t) {
      rst.push(sa.slice());
    } else if (s < t){
      for (var i = k; i < l; i++) {
        if ( i !== k && c[i] === c[i-1]) continue;
        
        s += c[i];
        sa.push(c[i]);
        dfs(c, l, i + 1, t, s, sa, rst);
        sa.pop(c[i]);
        s -= c[i];
      }
    }
}