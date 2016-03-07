#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int which(char c) {
    int rlt = 0;
    switch (c) {
       case 'M':
            rlt = 1000;
            break;
       case 'D':
            rlt = 500;
            break;
       case 'C':
            rlt = 100;
            break;
       case 'L':
            rlt = 50;
            break;
       case 'X':
            rlt = 10;
            break;
       case 'V':
            rlt = 5;
            break;
       case 'I':
            rlt = 1;
            break;
    }
    
    return rlt; 
}

int romanToInt(char* s) {
   int rlt = 0;
   while (*s) {
       int pre = which(*s++);
       if (*s && pre < which(*s)) rlt -= pre;
       else rlt += pre;
   } 
   return rlt;
}
int main(){
    printf("%d", romanToInt("DCXXXIV")); 

    system("pause"); 
    return 0;
}