var binaryTreePaths = function(root) {
    var rlt = [], path="";
    binaryTree(root, rlt, path);

    return rlt;
};
var binaryTree = function(root, rlt, path){
  if (!root) return;
  
  path += root.val;
  var left  = root.left, 
      right = root.right;

  if (left || right)  path += "->";
  if (!left && !right) {
    rlt.push(path); path ="";
  }

  if(root.left)  binaryTree(left, rlt, path);
  if(root.right) binaryTree(right, rlt, path);
}