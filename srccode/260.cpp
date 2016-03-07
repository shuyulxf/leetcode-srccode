#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int majorityElement(int* nums, int numsSize) {
    int intLen = sizeof(int) * 8, rst = 0, flag = 1;
    
    for (int i = 0; i < intLen && flag; i++) {
        int zNum = 0, oNum = 0;
        for (int j = 0; j < numsSize; j++) {
            int n = nums[j];
            
            if (n >> i & 0x01) oNum++; 
            else zNum++; 
        }
        
        if (oNum > zNum) rst += 1 << i;
    }
    
    return rst;
}
int main(){
    int b[] = {2,2};
    int a = majorityElement(b, 2);
    printf("%20d", a);
    system("pause"); 
    return 0;
}