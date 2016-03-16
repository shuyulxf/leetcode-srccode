var mergeKLists = function(lists) {
    var k = lists && lists.length ? lists.length : 0;
    if (!k)   return null;
    var rlt = null, head = null;
    //build heap
    var heap = [];
    for ( var i = 0; i < k; i++) {
       if (lists[i]) heap.push(lists[i]);
    }
    initHeap(heap); 
    head = heap[0];

    while (heap.length != 0) {
        var smallest = heap[0];
        if (rlt) {
            rlt.next = smallest;
            rlt = rlt.next;
        }
        else rlt = smallest;

        //adjust heap
        var next = smallest.next;
        if (next) {
            heap[0] = next;
            ajustHeap(heap, 0, heap.length);
        }  else {
            heap.shift();
            initHeap(heap);
        }
    }
    
    return head ? head : null;
};

//build heap use ajusting
var initHeap = function(heap){
    if (!heap)  return;
    var l = heap.length;
    if (!l) return;

    for (var i = Math.floor(l/2); i >= 0; i--) {
        ajustHeap(heap, i, l);
    }
}

var ajustHeap = function(heap, i, len) {
    if (!len) return;
    var l = left(i), r = right(i);
    var smaller = i;
    var val = heap[i].val;

    if (l < len && heap[l].val < val)   smaller = l;
    if (r < len && heap[r].val < heap[smaller].val)   smaller = r;

    if (i != smaller) {
        var tmp = heap[i];
        heap[i] = heap[smaller];
        heap[smaller] = tmp;
        ajustHeap(heap, smaller, len);
    }
}

var left = function(i) {
    return 2*i + 1;
}

var right = function(i) {
    return 2*i + 2;
}