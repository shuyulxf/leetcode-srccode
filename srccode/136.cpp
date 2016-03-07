#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int singleNumber(int* nums, int numsSize) {
    if (numsSize <= 0) return 0;
    
    int rst = 0;
    for (int i = 0; i < numsSize; i++) {
        rst ^= nums[i];
    }
    
    return rst;
}
int main(){
    int b[] = {1,2,1,3,2};
    int a = singleNumber(b, 5);
    printf("%d",a);
    system("pause"); 
    return 0;
}