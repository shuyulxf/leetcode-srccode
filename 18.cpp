#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int left, right;
    int row = 1000, size = -1, total = 0;
    int sum = 0;
    int** rlt = (int **)malloc(sizeof(int *) * row); 
    memset(rlt, 0, sizeof(rlt));
    if (numsSize < 4) return  rlt;
    
    qsort( nums, numsSize, sizeof(int), cmpfunc);

    for (int i = 0; i < numsSize - 1; i++) {
        if(i > 0 && nums[i] == nums[i-1]){  
            continue;  
        } 
        for (int j = i+1; j < numsSize; j++){ 
            if(j > i+1 && nums[j] == nums[j-1]) continue;
             
            left = j+1;
            right = numsSize - 1;
            
            while (left < right) {
                sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                   if (size == -1 || size >= 0 && (rlt[size][0] != nums[i] || rlt[size][1] != nums[j] || rlt[size][2] != nums[left] ||
                       rlt[size][3] != nums[right])) {
                       rlt[++size] = (int *)malloc(sizeof(int)* 4);
                       memset(rlt[size], 0, sizeof(rlt[size]));
                       rlt[size][0] = nums[i];
                       rlt[size][1] = nums[j];
                       rlt[size][2] = nums[left];
                       rlt[size][3] = nums[right];
                       printf("%5d",nums[i]);
                       printf("%5d",nums[j]);
                       printf("%5d",nums[left]);
                       printf("%5d\n",nums[right]);
                   }
                   left++;right--;
                } else if (sum > target){
                   right--;
                } else {
                   left++;
                }
            }
        }   
    }
    
    *returnSize = size + 1;
    
    return rlt;
}

int main(){
    int* size = (int*)malloc(sizeof(int));
    *size = 0;
    int nums[]= {-5,-4,-3,-2,-1,0,0,1,2,3,4,5};
    int** rlt = fourSum(nums, 12, 0,size); 
    

    system("pause"); 
    return 0;
}