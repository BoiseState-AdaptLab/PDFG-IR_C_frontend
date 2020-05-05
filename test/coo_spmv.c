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

// perform sparse matrix-vector multiplication using COO format
int COO_SpMV(int a, int N, int A[a], int row[a], int x[N], int product[N]) {
    int i;
    for (i = 0; i < a; i++) {
        product[row[i]] += A[i] * x[row[i]];
    }

    return 0;
}
