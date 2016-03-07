#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int max(int x, int y) {
    if (x > y) return x;
    return y;
}
int min(int x, int y) {
    if (x < y) return x;
    return y;
}
int maxArea(int* height, int heightSize) {
    int v = 0;
    int low = 0, high = heightSize - 1;
    
    while (low <= high) {
         v = max(v, min(height[low], height[high]) * (high - low));
         if (height[low] <= height[high]) low++;
         else high--;
    } 
    return v;
}
int main(){
    int a[] = {3,4,2,5,6};
    printf("%d", maxArea(a, 5)); 
      
    system("pause"); 
    return 0;
}