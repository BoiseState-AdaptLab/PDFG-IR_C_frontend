/**
BEGIN_EXPECTED
A
    S0: return 1;
    S1: int i;
    S2: int j;
    S3: product[i] = 0;
    S4: product[i] += x[i][j] * y[j];
B
    S0: {[]: b != c}
    S1: {[]}
    S2: {[]}
    S3: {[i]: 0 <= i < a}
    S4: {[i,j]: 0 <= i < a and 0 <= j < b}
C
    S0:  {[]->[0,0,0,0,0,0]}
    S1:  {[]->[1,0,0,0,0,0]}
    S2:  {[]->[2,0,0,0,0,0]}
    S3:  {[i]->[3,0,i,0,0,0]}
    S4:  {[i,j]->[3,0,i,1,j,0]}
END_EXPECTED
 */

#include <stdlib.h>
#include <stdio.h>


// perform matrix * vector multiplication
int mvm(int a, int b, int x[a][b], int c, int y[c], int product[a]) {
    if (b != c) return 1;

    int i;
    int j;
    for (i = 0; i < a; i++) {
        product[i] = 0;
        for (j = 0; j < b; j++) {
            product[i] += x[i][j] * y[j];
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
    int c = 2;
    int y[2] = {
        7,
        9,
    };

    int product[c];
    if (mvm(a, b, x, c, y, product) != 0) {
        printf("encountered error during matrix vector multiplication\n");
    }

    // print out product
    printf("product:\n");
    int i;
    for (i = 0; i < a; i++) {
        printf("%d\n", product[i]);
    }

    return 0;
}
