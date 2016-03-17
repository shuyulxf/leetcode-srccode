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

// use a array to save the nodes for reverse nodes
var reverse = function(head, k) {
    var pre = new ListNode(-1), i = 0;
    var tmp = [];

    while (i++ < k) {
        tmp.push(head);
        head = head.next;
    }

    var rlt = tmp[k-1];
    while (--i > 0) {
        pre.next = tmp.pop();
        pre = pre.next;
    }
    pre.next = head;

    return [rlt,pre];
}