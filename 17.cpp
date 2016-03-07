#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char tbl[][5] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    *returnSize = 0;
    char** rlt = (char **)malloc(sizeof(char *) * len); 
    
    return rlt;
}
void letterCombination(char** rlt, char* digits, int* returnSize) {
     int len = strlen(digits);
     char* s = tbl[digits[0] - '0'];
     int size = strlen(s);
     
     if (!len) return;
     if (len == 1) {
        for (int i = 0; i < size; i++) {
            rlt[*returnSize][0] = s[i];
            *returnSize += 1;      
        }
        return;
     }
     int a = *returnSize;
     int* tmp; 
     *tmp = a*a;
     letterCombination(rlt, digits++, tmp);
     for (int i = 0; i < strlen(s); i++) {
         for(int j = 0; j < *tmp; j++) {
                 int l = strlen(rlt[j]);
                 rlt[j][l] = s[i];
         }
     }
}
int main(){
    char *s = "23";
    int* size = 0;
    
    char** str = letterCombinations(s, size); 
    for(int i = 0; i < 9; i++) {
       printf("%s", str[i]);
    }

    system("pause"); 
    return 0;
}