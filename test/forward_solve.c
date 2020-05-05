/**
BEGIN_EXPECTED
A
    S0: int i;
    S1: x[i] = b[i];
    S2: int j;
    S3: x[j] /= l[j][j];
    S4: x[i] -= l[i][j] * x[j];
B
    S0: {[]}
    S1: {[i]: 0 <= i < n}
    S2: {[]}
    S3: {[j]: 0 <= j < n}
    S4: {[i,j]: 0 <= j < n and j+1 <= i < n}
C
    S0: {[]->[0,0,0,0,0]}
    S1: {[i]->[1,i,0,0,0]}
    S2: {[]->[2,0,0,0,0]}
    S3: {[j]->[3,j,0,0,0]}
    S4: {[i,j]->[4,j,1,i,0]}
END_EXPECTED
 */

int forward_solve(int n, int l[n][n], double b[n], double x[n]) {
    int i;
    for (i = 0; i < n; i++) {
        x[i] = b[i];
    }

    int j;
    for (j = 0; j < n; j++) {
        x[j] /= l[j][j];
        for (i = j + 1; i < n; i++) {
            if (l[i][j]) x[i] -= l[i][j] * x[j];
        }
    }

    return 0;
}
