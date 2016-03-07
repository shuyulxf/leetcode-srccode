#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
char rlt[20] = {'\0'};
void join(char* s) {
    if(!s) return;
    
    char* tmp = rlt;
    int len = strlen(rlt);
    while(*s!='\0') tmp[len++] = *s++; 
}
char* intToRoman(int num) {
    char pattern[][3] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    char* tmp = rlt;
    
    for (int i = 0; num > 0 && i < 13; i++) {
       while (num >= value[i]) {
           num -= value[i];
           join(pattern[i]); 
       }
    }
    
    return rlt;
}

int main(){
    printf("%s", intToRoman(634)); 

    system("pause"); 
    return 0;
}