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
