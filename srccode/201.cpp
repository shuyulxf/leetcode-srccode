#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int rangeBitwiseAnd(int m, int n) {
    if (m == 0) return 0;
    int rst = 0, bits = -1;
    int k = n;
    while (k) { bits++; k >>= 1;} 
    
    for (int i = bits; i >= 0; i--) {
        int tmp = m >> i & 0x01;
        for (int j = m+1 ; j > INT_MIN && j <= n ; j++) {
            tmp &= j >> i;
            if(!tmp) break;
        }
        if (i == bits && !tmp) return 0;
        rst += tmp << i;
    }
    
    return rst;
}

int main(){
    int a = rangeBitwiseAnd(2147483646,2147483647);
    printf("%5d\n",a); 
    system("pause"); 
    return 0;
}