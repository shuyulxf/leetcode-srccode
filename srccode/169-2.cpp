#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int majorityElement(int* nums, int numsSize) {
      int m = -1;
        int count = 0;
        
        int size = numsSize;
        for (int i = 0; i < size; i++)
            if (count == 0) {
                count = 1;
                m = nums[i];
            } else {
                if (m == nums[i])
                    count++;
                else
                    count--;
            }
        
        return m;
}
int main(){
    int b[] = {2,2,3};
    int a = majorityElement(b, 2);
    printf("%20d", a);
    system("pause"); 
    return 0;
}