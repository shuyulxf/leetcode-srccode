#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int size =  1 << numsSize;
    int** rst = (int**)malloc(sizeof(int *) * size); 
    int *colSizeArr;
    colSizeArr = (int *)malloc(sizeof(int) * size);
    
    memset(colSizeArr, 0, sizeof(int)*size);
    for(int i = 0; i < size; i++) printf("%d",colSizeArr[i]);
    memset(rst,0,sizeof(sizeof(int *) * size));
    for(int i = 0; i < size; i++) {
        rst[i] = (int*)malloc(sizeof(int)*numsSize);
        memset(rst[i],0,sizeof(int) * numsSize);
    }
    
    qsort( nums, numsSize, sizeof(int), cmpfunc);
    
    for (int i = 0; i < size; i++) {       
        int len = 0;
        int tmp = i;
        
        for (int j = 0; (j < numsSize) && tmp; j++) {
           if (tmp & 1) {
               rst[i][len++] = nums[j];
           }
           tmp >>= 1;
        }
        
        colSizeArr[i] = len;
        //columnSizes[i] = (int*)malloc(sizeof(int));
        //*columnSizes[i] = len;
    } 
    *columnSizes = colSizeArr;
  
    *returnSize = size;
    
    return rst;
}
int main(){
    int nums[] = {0};
    int numsSize =1;
    int size = 0;
    int** columnSizes = (int **)malloc(sizeof(int *)); 
    int** rst1 = (int **)malloc(sizeof(int*)*numsSize); 
    memset(rst1,0,sizeof(rst1));
    rst1 = subsets(nums,numsSize,columnSizes,&size); 
    int len = 1 << numsSize;;
    printf("%5d\n",size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < *columnSizes[i]; j++) {
           printf("%5d",rst1[i][j]);
        }
       //free(rst[i]);
       // printf("\n");
    }
    //free(rst);
    
   // printf("%5d\n",a); 
    system("pause"); 
    return 0;
}