#include <stdio.h>

int main(void) {

    /* Variable declaration */
    double factorial;
    int n, i;

    /* Enter N from the keyboard */
    printf("Compute the factorial of 1 to N.\n");
    printf("Please enter N.\n"); scanf("%2d", &n);

    /* Validation of input value */
    if( n <= 0 ){
        printf("Please enter a positive integer for N.\n");
    /* Abnormal termination (return value is 1）*/
        return 1;
    }else if( n > 21 ){
        printf("Please enter the number below 21");
    /* Abnormal termination (return value is 1）*/
        return 1;
    }

    /* Calculate factorial */
    factorial = 1;
    for (i=1; i<=n; i++) {
        factorial *= i;
    }

    /* Output factorial */
    printf("The factorial from 1 to %d is %.0f.\n", n ,factorial);

    return 0;
}