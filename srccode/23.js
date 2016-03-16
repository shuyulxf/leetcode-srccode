/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */

function ListNode(val) {
    this.val = val;
    this.next = null;
}
var mergeKLists = function(lists) {
    if (!lists || lists&&!lists.length)   return null;

    return divided(lists, 0, lists.length-1);
};

var divided = function(lists, l, r) {
    while (l < r) {
        var m = Math.floor((l + r) / 2);
        return merge(divided(lists, l, m), divided(lists, m+1, r));
    }

    return lists[l];
};

/*
    use a tmp node to contain the merged list head
    use cur.next = l1 to be the current list and l2 is the list to merge to cur
    we add l2 to cur.
*/
var merge = function(list1, list2) {
    var l1 = list1, l2 = list2;
    var tmp = new ListNode(0);
    tmp.next = l1;
    var cur = tmp;

    while (l1 && l2) {
        if (l1.val < l2.val) {
           l1 = l1.next;
        } else {
            var next = l2.next;
            l2.next = l1;
            cur.next = l2;
            l2 = next;
        } 
        cur = cur.next;
    }

    if (l2) cur.next = l2;
    return tmp.next;
};