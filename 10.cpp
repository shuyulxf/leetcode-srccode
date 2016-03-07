#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isMatch1(char* s, char* p) {
    int si = 0, pi = 0;
    int sLen = strlen(s), pLen = strlen(s); 
    //int rlt = 0;
    char prev = '\0';
    
    while (si < sLen && pi < pLen) {
       char sc = s[si], pc = p[pi];
       if (pc == '.') {
          if (p[pi+1] == '*') {
             
          }
       }
       if (pc == '*') {
          
       } else if (pc == sc || pc == '.'){
         si++; pi++;
         prev = pc[pi];
         if (si == sLen) return 1;
       }
    }
    return 0;
}
int isMatch2(char* s, char* p) {
   if (*p == 0) return *s == 0;
   if (*(p+1) != '*') {
      if (*s != 0 && (*p == *s || *p == '.')) return isMatch2(s+1, p+1);
      else return false;
   } else {
      while (*s != 0 && (*p == *s || *p == '.')) {
         if (isMatch2(s, p+2)) return true;
         s++;
      }
      return isMatch2(s, p+2);
   }
}
int main(){
    char* s = "ab";
    char* p = "ab";
    printf("%d", isMatch(s, p)); 
      
    system("pause"); 
    return 0;
}