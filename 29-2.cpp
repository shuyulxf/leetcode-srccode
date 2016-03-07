#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int divide(int dividend, int divisor) {

	long long a = dividend;
	long long b = divisor;
	char sign = 1;

	if (a < 0) { sign = -sign; a = -a; }
	if (b < 0) { sign = -sign; b = -b; }

	long long rst = 0;
	long long bitv[32] = {b};
	long long bit[32] = {1};

	int i = 1;
	for (; true; i++) {
		bitv[i] = bitv[i-1] + bitv[i-1];
		bit[i] = bit[i-1] + bit[i-1];
		if (a < bitv[i]) break;
	}

	long long remain = a;
	for (; i >= 0; i--) {
		if (bitv[i] <= remain) {
			remain -= bitv[i];
			rst += bit[i];
			if (remain == 0) break;
		}
	}

	if (sign < 0) rst = -rst;
	return rst;
}

int main(){
    int a = divide(-2147483648,-1);
    printf("%d",a);
    system("pause"); 
    return 0;
}