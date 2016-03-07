#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char rlt[1000] = {0};
int isR(char x, char y) {
    if (x == '{' && y == '}' || x == '(' && y == ')' || x == '[' && y == ']')
       return 1;
    return false;
}
int isValid(char* s) {
    int top = 0;
    
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        while (isR(rlt[top], s[i]) && top > 0 && i < len) {
            top--; i++;
        }
        if(i < len) rlt[++top] = s[i];
    }
    if (top != 0) return 0;
    return 1;
}
int main(){
    char *a = "([])()()";
    printf("%d", isValid(a)); 
      
    system("pause"); 
    return 0;
}