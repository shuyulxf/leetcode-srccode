#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int maxProduct(char** words, int wordsSize) {
    int rst = 0;
    int* map = (int*)malloc(sizeof(int)*wordsSize);
    memset(map, 0, sizeof(map));
    int* lens = (int*)malloc(sizeof(int)*wordsSize);
    memset(lens, 0, sizeof(lens));
    
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        int bit = 0;
        for (int j = 0; j < strlen(word); j++)  bit |= 1 << (word[j] - 'a');
        map[i] = bit;
        lens[i] = strlen(words[i]);
    }
    
    for (int i = 0; i < wordsSize - 1; i++) {
        for (int j = i+1; j < wordsSize; j++) {
            if (map[i] & map[j]) continue;
            else {
                 int tmp = lens[i] * lens[j];
                 rst = rst < tmp ? tmp : rst; 
            }
        }
    }
    
    return rst;
}

int main(){
    int size = 5;
    char** s = (char **)malloc(sizeof(char *) * size); 
    for (int i = 0; i < size; i++) {
        s[i] = (char*)malloc(sizeof(char)*10);
    }
    s[0] = "a";s[1]="ab";s[2]="abc";s[3]="abcd";s[4]="abcde";
    s[5] = "ghijklmnopqrstuvwxyz";s[6]="fghijklmnopqrstuvwxyz";s[7]="efghijklmnopqrstuvwxyz";s[8]="defghijklmnopqrstuvwxyz";s[9]="cdefghijklmnopqrstuvwxyz";
    s[10] = "abcdef";s[11]="abcdefg";s[12]="abcdefgh";s[13]="abcdefghi";s[14]="abcdefghij";
    s[15] = "abcdefghijk";s[16]="abcdefghijkl";s[17]="abcdefghijklm";s[18]="nopqrstuvwxyz";s[19]="mnopqrstuvwxyz";
    s[20] = "lmnopqrstuvwxyz";s[21]="klmnopqrstuvwxyz";s[22]="jklmnopqrstuvwxyz";s[23]="ijklmnopqrstuvwxyz";s[24]="hijklmnopqrstuvwxyz";
    s[25] = "bcdefghijklmnopqrstuvwxyz";
    int a = maxProduct(s,26);
    printf("%5d\n",a); 
    system("pause"); 
    return 0;
}