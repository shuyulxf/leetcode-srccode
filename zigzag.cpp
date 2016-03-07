#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char res[1000] = {0};
char* convert(char* s, int numRows) {
    if (!numRows || numRows == 1) return s;
    
    int i, j, n = strlen(s);
    //char res = (char*)(malloc(sizeof(char)*(n+1)));
    //memset(res,0, sizeof(res));
    
    for (i = 0, j = 0; i < n && i < numRows; i++) {
        int idx = i;
        if (i == 0 || i == numRows -1) {
           while ( idx < n) {
              res[j++] = s[idx];
              idx += 2 * numRows - 2;
           }
        }
        else {
           int flag = 1;
           while (idx < n) {
              res[j++] = s[idx];
              if (flag == 0) {
                 idx += 2 * i; 
                 flag = 1;
              } else {
                 idx += 2 * numRows - 2 - 2 * i;
                 flag = 0;
              }
           }
        }
    }
    
    return res;
}
int main(){
    char s[] = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    printf("%s", convert(s,61));
    
    system("pause");
    return 0;
}
