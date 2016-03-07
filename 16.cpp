#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int** threeSumClosest(int* nums, int numsSize, int target) {
    int left, right;
    int row = 100, size = -1, total = 0;
    int sum = 0;
    int** rlt = (int **)malloc(sizeof(int *) * row); 
    int closest = 0;
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
            int preDelta  = abs(sum - target);
            int postDelta = abs(closest - target);
            if (preDelta == postDelta) {
               if (size == -1 || size >= 0 && (rlt[size][0] != nums[i] || rlt[size][1] != nums[left] ||
                   rlt[size][2] != nums[right])) {
                   rlt[++size] = (int *)malloc(sizeof(int)* 3);
                   memset(rlt[size], 0, sizeof(rlt[size]));
                   rlt[size][0] = nums[i];
                   rlt[size][1] = nums[left];
                   rlt[size][2] = nums[right];
               }
               left++;
               right--;
            } else if (preDelta < postDelta) {
                while (size != -1) free(rlt[size--]); 
                rlt[++size] = (int *)malloc(sizeof(int)* 3);
                memset(rlt[size], 0, sizeof(rlt[size]));
                rlt[size][0] = nums[i];
                rlt[size][1] = nums[left];
                rlt[size][2] = nums[right];
                if ( sum - target > 0) right--;
                else left++;
            } else {
                if ( sum - target > 0) right--;
                else left++;
            }
        }
    }
    
    return rlt;
}
int main(){
    int* size = (int*)malloc(sizeof(int));
    *size = 0;
    int nums[]= {0,0,0};
    int** rlt = threeSumClosest(nums, 3, 1); 
    
    for (int i = 0; i < 1; i++) {
       for (int j = 0; j < 3; j++) {
           printf("%5d", rlt[i][j]);
        }
       printf("\n");
    } 

    system("pause"); 
    return 0;
}