#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char s[1000] = {0};
char* longestCommonPrefix(char** strs, int strsSize) {
    if (!strsSize) return "";
    
    memset(s, 0, sizeof(s));
    int len = strlen(strs[0]);
    
    int flag = 1;
    for (int i = 0; i < len; i++) {
        char c = strs[0][i];
        int j = 0;
        for(; j < strsSize && strs[j][i] != 0; j++) {
           if (c != strs[j][i]) flag = 0;
        }
        if (flag && j == strsSize) s[i] = c; 
    }
    return  s;
}
int main(){
    char *s[10] = {"aa", "a"};
    printf("%s", longestCommonPrefix(s,2));
    
    system("pause"); 
    return 0;
}
