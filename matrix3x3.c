
#include <stdio.h>		

int main(void) {
    /* Define matrix C (one-dimensional array, only declaration）.*/
    int C[3][3];

    /* Define 3 × 3 matrix A (initialize at the same time as declaration).*/
    int A[3][3] = {
        { 1, 0, 3},
        { 2,-8, 1},
        { 2, 1,-3},
    };

   /* Define 3 × 3 matrix B (initialize at the same time as declaration).*/
    int B[3][3] = {
        { 1, 0, 0},
        { 0, 1, 0},
        { 0, 0, 1},
    };

    /* Calculate C = A B. */
    C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0] + A[0][2]*B[2][0];
    C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0] + A[1][2]*B[2][0];
    C[2][0] = A[2][0]*B[0][0] + A[2][1]*B[1][0] + A[2][2]*B[2][0];

    C[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1] + A[0][2]*B[2][1];
    C[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1] + A[1][2]*B[2][1];
    C[2][1] = A[2][0]*B[0][1] + A[2][1]*B[1][1] + A[2][2]*B[2][1];

    C[0][2] = A[0][0]*B[0][2] + A[0][1]*B[1][2] + A[0][2]*B[2][2];
    C[1][2] = A[1][0]*B[0][2] + A[1][1]*B[1][2] + A[1][2]*B[2][2];
    C[2][2] = A[2][0]*B[0][2] + A[2][1]*B[1][2] + A[2][2]*B[2][2];

    /* Output matrix A. */
    printf("    |%3d %3d %3d |\n", A[0][0], A[0][1], A[0][2]);
    printf("A = |%3d %3d %3d |\n", A[1][0], A[1][1], A[1][2]);
    printf("    |%3d %3d %3d |\n", A[2][0], A[2][1], A[2][2]);
    printf("\n");

    /* Output matrix B. */
    printf("    |%3d %3d %3d |\n", B[0][0], B[0][1], B[0][2]);
    printf("B = |%3d %3d %3d |\n", B[1][0], B[1][1], B[1][2]);
    printf("    |%3d %3d %3d |\n", B[2][0], B[2][1], B[2][2]);
    printf("\n");

    /* Output matrix C. */
    printf("         |%3d %3d %3d |\n", C[0][0], C[0][1], C[0][2]);
    printf("C = AB = |%3d %3d %3d |\n", C[1][0], C[1][1], C[1][2]);
    printf("         |%3d %3d %3d |\n", C[2][0], C[2][1], C[2][2]);
    printf("\n");

    return 0;				/* Return value at normal termination is 0. */
}