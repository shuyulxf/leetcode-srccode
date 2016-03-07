#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool isPalindrome(int x) {
    
    int y = x;
    int reverse = 0;
    
    if (x < 0) return false;
    while (y) {
        reverse = reverse * 10 + y % 10;
        y /= 10;
    }
    
    return x == reverse; 
}
int main(){
    int a = -123321;
    printf("%d", isPalindrome(a)); 
      
    system("pause"); 
    return 0;
}