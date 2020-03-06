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
