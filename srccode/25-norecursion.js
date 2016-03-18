
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */

function ListNode(val) {
    this.val = val;
    this.next = null;
}
var reverseKGroup = function(head, k) {
    var tmp = head;
    var l = 0, h = null;
    while (tmp) {
        l++;
        tmp = tmp.next;
    }
    if (!head || l < k) return head;

    var last = null;
    while (l >= k) {
        var t = reverse(head, k);
        if (!h)  h = t[0];
        else last.next = t[0];
        last = t[1];
        head = head.next;
        l -= k;
    }
 
    return h;
};

var reverse = function(head, k) {
    var pre = new ListNode(-1), i = 0;
    var h = null;

    while (i++ < k) {
        var tmp = pre.next;
        pre.next = head;
        head = head.next;
        pre.next.next =tmp;
        if (!h) h = pre.next;
    }
    h.next = head;

    return [pre.next,h];
}