#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int left, right;
    int row = 100, size = -1, total = 0;
    int sum = 0;
   
    if (numsSize < 3) return  0;

    qsort( nums, numsSize, sizeof(int), cmpfunc);
    int closest = nums[0]+nums[1]+nums[2];
    for (int i = 0; i < numsSize; i++) {
        if(i > 0 && nums[i] == nums[i-1]){  
            continue;  
        } 
        left = i+1;
        right = numsSize - 1;
        while (left < right) {
            sum = nums[i] + nums[left] + nums[right];
            int preDelta  = abs(sum - target);
            int postDelta = abs(closest - target);
            if (preDelta == postDelta) {
               left++;
               right--;
               closest=sum;
            } else if (preDelta < postDelta) {
                closest = sum;
                if ( sum - target > 0) right--;
                else left++;
            } else {
                if ( sum - target > 0) right--;
                else left++;
            }
        }
    }
    
    return closest;
}
int main(){
    int* size = (int*)malloc(sizeof(int));
    *size = 0;
    int nums[]= {0,2,1,-3};
    int rlt = threeSumClosest(nums, 4, 1); 
    printf("%5d", rlt);
  

    system("pause"); 
    return 0;
}