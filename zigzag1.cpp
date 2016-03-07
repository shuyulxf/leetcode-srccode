#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int myAtoi(char* str) {
    int sum = 0, len = strlen(str), i = 0;
    const int MAX_POS = 2147483647;
    const int MAX_NEG = -2147483648;
    int max = MAX_POS;
    int flag = 1;
    
    while (str[i] == ' ' && i < len) i++; 
    
    if (str[i] == '-') {
       flag = -1;
       max = MAX_NEG;
       i++; 
    }
    else if (str[i] == '+') i++;
    
    for (; i < len; i++) {
        if (str[i] > '9' || str[i] < '0') break;
        int bit = str[i] - '0';
        if (((max - (str[i] - '0')*flag) / 10)*flag >= sum)
           sum = sum*10 + str[i] - '0';
        else return max;
    }
    
    return flag * sum;
}
int main(){
    char s[] = "-1a";
    printf("%d\n", myAtoi(s));
    printf("%d", atoi(s));
    system("pause");
    return 0;
}
