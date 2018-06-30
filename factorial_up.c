#include <stdio.h>
#define RADIX 10000
#define MAX 10000

int f[MAX], carry;
int n = -1, digit=0, i, j;
long tmp;

int main(void) {
    for(i = 0; i < MAX; i++) f[i] = 0;
    f[0] = 1;
    while(1) {
        printf("n = ");
        scanf("%5d", &n);
        if(n >= 0) break;
        printf("ERR: n must be zero or positive.");
    }

    for(j = 2; j <= n; j++) {
        carry = 0;
        for(i = 0; i <= digit; i++){
            tmp =  f[i] * j + carry;
            f[i] = tmp % RADIX ;
            carry = tmp / RADIX;
        }
        if(carry) f[++digit] = carry;
        if(digit >= MAX) {
            printf("overflow\n");
            return(-1);
        }
    }
    printf("%d",f[digit]);
    for(i = digit-1; i >= 0; i--) {
        printf("%04d", f[i]);
    }
    return(0);
}
