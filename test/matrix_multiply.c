/**
BEGIN_EXPECTED
A
    S0: return 1;
    S1: int i;
    S2: int j;
    S3: int k;
    S4: product[i][j] = 0;
    S5: product[i][j] += x[i][k] * y[k][j];
B
    S0: {[]: b != c}
    S1: {[]}
    S2: {[]}
    S3: {[]}
    S4: {[i,j]: 0 <= i < a and 0 <= j < d}
    S5: {[i,j,k]: 0 <= i < a and 0 <= j < d 0 <= k < c}
C
    S0: {[]->[0,0,0,0,0,0,0,0]}
    S1: {[]->[1,0,0,0,0,0,0,0]}
    S2: {[]->[2,0,0,0,0,0,0,0]}
    S3: {[]->[3,0,0,0,0,0,0,0]}
    S4: {[i,j]->[4,i,0,j,0,0,0,0]}
    S5: {[i,j,k]->[4,i,0,j,1,k,0]}
END_EXPECTED
 */

#include <stdlib.h>
#include <stdio.h>


// perform matrix multiplication
int mm(int a, int b, int x[a][b], int c, int d, int y[c][d], int product[a][d]) {
    if (b != c) return 1;

    int i;
    int j;
    int k;
    for (i = 0; i < a; i++) {
        for (j = 0; j < d; j++) {
            product[i][j] = 0;
            for (k = 0; k < c; k++) {
                product[i][j] += x[i][k] * y[k][j];
            }
        }
    }

    return 0;
}

// main function just for testing
int main(void) {
    int a = 3, b = 2;
    int x[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
    };
    int c = 2, d = 2;
    int y[2][2] = {
        {7, 8},
        {9, 0},
    };

    int product[a][d];
    if (mm(a, b, x, c, d, y, product) != 0) {
        printf("encountered error during matrix multiplication\n");
    }

    // print out product
    printf("product:\n");
    int i;
    int j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < d; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}
