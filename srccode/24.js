/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
 
//add a header node to save the prev node info 
//because to swap we need know the prev node
var swapPairs = function(head) {
    if (!head || !head.next) return head;

    var rlt = head.next;
    var cur = new ListNode(0);
    while (head && head.next) {
        var next = head.next;
        var nn = next.next;
        cur.next = next;
        cur = next;
        head.next = nn;
        cur.next = head;
        cur = head;
        head = nn;
    }  
    return rlt;
};