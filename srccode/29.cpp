#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int divide(int dividend, int divisor) {
    int rlt = 0, flag = 1;
    int sign = 1;
    
    if (dividend <= INT_MIN && divisor == -1) return INT_MAX;
    if (dividend >= INT_MAX && divisor == -1)  return INT_MIN;
    if (dividend <= INT_MIN && divisor == 1) return INT_MIN;
    
    long long a = dividend;  
    long long b = divisor; 

    if (a < 0) { sign = -sign; a = -a; }
    if (b < 0) { sign = -sign; b = -b; }
    
    while ( a >= b) {
        long long c = b;  
        for(int i = 0; a >= c; i++, c <<=1)  
        {  
            a -= c; 
            rlt += 1 << i; 
        }  
    }
    
    if (sign < 0) rlt = -rlt;
    return rlt;
}

int main(){
    int a = divide(2147483647,-2147483648);
    printf("%d",a);
    system("pause"); 
    return 0;
}