#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int rangeBitwiseAnd(int m, int n) {

   int bits = 0;
   while (m != n) {
         m >>= 1;
         n >>= 1;
         bits++;
   }
   
   return m << bits;   
}

int main(){
    int a = rangeBitwiseAnd(5,6);
    printf("%5d\n",a); 
    system("pause"); 
    return 0;
}