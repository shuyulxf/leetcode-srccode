#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int singleNumber(int* nums, int numsSize) {
    if (numsSize <= 0) return 0;
    
    int intLen = sizeof(int) * 8, sum, rst = 0;
    
    for (int i = 0; i < intLen; i++) {
        sum = 0;
        for (int j = 0; j < numsSize; j++) {
            sum += (nums[j] >> i) & 0x01;
        }
        rst += (sum % 3) << i;
    }
    return rst;
}
int main(){
    int b[] = {1,1,1,1,1,2,2,2};
    int a = singleNumber(b, 4);
    printf("%d",a);
    system("pause"); 
    return 0;
}