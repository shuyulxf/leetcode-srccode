#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int left, right;
    int row = 1000, size = -1, total = 0;
    int sum = 0;
    int** rlt = (int **)malloc(sizeof(int *) * row); 
    memset(rlt, 0, sizeof(rlt));
    if (numsSize < 3) return  rlt;
    
    qsort( nums, numsSize, sizeof(int), cmpfunc);
    
  
    for (int i = 0; i < numsSize; i++) {
        if(i > 0 && nums[i] == nums[i-1]){  
            continue;  
        } 
        
        left = i+1;
        right = numsSize - 1;
        while (left < right) {
            sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
               if (size == -1 || size >= 0 && (rlt[size][0] != nums[i] || rlt[size][1] != nums[left] ||
                   rlt[size][2] != nums[right])) {
                   rlt[++size] = (int *)malloc(sizeof(int)* 3);
                   memset(rlt[size], 0, sizeof(rlt[size]));
                   rlt[size][0] = nums[i];
                   rlt[size][1] = nums[left];
                   rlt[size][2] = nums[right];
                   printf("%5d",nums[i]);
                   printf("%5d",nums[left]);
                   printf("%5d\n",nums[right]);
               }
               left++;right--;
            } else if (sum > 0){
               right--;
            } else {
               left++;
            }
        }
    }
    *returnSize = size + 1;
    
    return rlt;
}
int main(){
    int* size = (int*)malloc(sizeof(int));
    *size = 0;
    int nums[]= {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    int** rlt = threeSum(nums, 15, size); 
    
   // for (int i = 0; i < 2; i++) {
    //   for (int j = 0; j < 3; j++) {
      //     printf("%5d", rlt[i][j]);
      //  }
      //  printf("\n");
    //}
   // printf("%d", len); 

    system("pause"); 
    return 0;
}