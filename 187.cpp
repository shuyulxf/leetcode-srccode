#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
//time exceed
char** findRepeatedDnaSequences(char* s, int* returnSize) {
    char** rst = (char**)malloc(sizeof(char*) * 100); 
    memset(rst, 0, sizeof(rst));
    int len = strlen(s), size = -1;
    
    for (int i = 0; i < len - 11; i++) {
        if (i > 0 && s[i] == s[i-1]) continue;
        for (int j = i+1; j < len; j++){
            int flag = 1;
            for (int k = 0; k < 10; k++) {
                if (s[i+k] != s[j+k]) {flag = 0; break;}
            }
            if (flag){
               rst[++size] = (char*)malloc(sizeof(char)*10);
               memset(rst[size], 0, sizeof(rst[size]));
               
               for(int h = 0; h < 10; h++){
                  rst[size][h] = s[i+h];
               }
            }
        }
    }
    *returnSize = size;
    return rst;
}

int main(){
    char* s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGGGTTTTTGGGGGTTTTT";
    int* size = (int*)malloc(sizeof(int));
    *size = 0;
    char** rst = (char **)malloc(sizeof(char *) * 100); 
   
    rst = findRepeatedDnaSequences(s, size);
    for(int i = 0; i < 3; i++) {
        printf("%s\n",rst[i]);
    }
   // printf("%5d\n",a); 
    system("pause"); 
    return 0;
}