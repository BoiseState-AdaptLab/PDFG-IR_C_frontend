/**
BEGIN_EXPECTED
A
    S0: int i;
    S1: product[row[i]] += A[i] * x[row[i]];
    S2: return 0;
B
    S0: {[]}
    S1: {[i]: 0 <= i < a}
    S2: {[]}
C
    S0:  {[]->[0,0,0]}
    S1:  {[i]->[1,i,0]}
    S2:  {[]->[2,0,0]}
END_EXPECTED
 */

#include <stdlib.h>
#include <stdio.h>


// perform sparse matrix-vector multiplication using COO format
int COO_SpMV(int a, int N, int A[a], int row[a], int x[N], int product[N]) {
    int i;
    for (i = 0; i < a; i++) {
        product[row[i]] += A[i] * x[row[i]];
    }

    return 0;
}

// test operation
int main(void) {
    int a = 6;
    int A[6] = {1, 2, 3, 4, 5, 6};
    int row[6] = {0, 0, 1, 1, 2, 2};
    //int col[6] = {0, 1, 0, 1, 0, 1};
    int N = 3;
    int x[3] = {7, 9, 11};

    int product[3] = {0};
    if (COO_SpMV(a, N, A, row, x, product) != 0) {
        printf("encountered error\n");
    }

    // print out product
    printf("product:\n");
    int i;
    for (i = 0; i < N; i++) {
        printf("%d\n", product[i]);
    }

    return 0;
}
