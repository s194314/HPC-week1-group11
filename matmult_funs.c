#include <cblas.h>

void matmult_nat(int m,int n,int k,double **A,double **B,double **C) {
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            C[i][j] = 0;
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            for (int l=0;l<k;l++) {
                C[i][j] += A[i][l]*B[l][j];
            }
        }
    }
}

void matmult_lib(int m,int n,int k,double **A,double **B,double **C) {
    cblas_dgemm(
        CblasRowMajor,  // Matrix storage format
        CblasNoTrans,   // Transpose option for matrix A
        CblasNoTrans,   // Transpose option for matrix B
        m,              // Number of rows in matrix A and C
        n,              // Number of columns in matrix B and C
        k,              // Number of columns in matrix A and rows in matrix B
        1.0,            // Scalar multiplier for the product of matrices A and B
        A[0],           // Pointer to the first element of matrix A
        k,              // Leading dimension of matrix A
        B[0],           // Pointer to the first element of matrix B
        n,              // Leading dimension of matrix B
        0.0,            // Scalar multiplier for matrix C
        C[0],           // Pointer to the first element of matrix C
        n               // Leading dimension of matrix C
    );
}

void matmult_mnk(int m,int n,int k,double **A,double **B,double **C) {
    matmult_nat(m,n,k,A,B,C);
}

void matmult_mkn(int m,int n,int k,double **A,double **B,double **C) {
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            C[i][j] = 0;
        }
    }
    for (int i=0;i<m;i++) {
        for (int l=0;l<k;l++) {
            for (int j=0;j<n;j++) {
                C[i][j] += A[i][l]*B[l][j];
            }
        }
    }
}

void matmult_nmk(int m,int n,int k,double **A,double **B,double **C) {
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            C[i][j] = 0;
        }
    }
    for (int j=0;j<n;j++) {
        for (int i=0;i<m;i++) {
            for (int l=0;l<k;l++) {
                C[i][j] += A[i][l]*B[l][j];
            }
        }
    }
}

void matmult_nkm(int m,int n,int k,double **A,double **B,double **C) {
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            C[i][j] = 0;
        }
    }
    for (int j=0;j<n;j++) {
        for (int l=0;l<k;l++) {
            for (int i=0;i<m;i++) {
                C[i][j] += A[i][l]*B[l][j];
            }
        }
    }
}

void matmult_kmn(int m,int n,int k,double **A,double **B,double **C) {
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            C[i][j] = 0;
        }
    }
    for (int l=0;l<k;l++) {
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                C[i][j] += A[i][l]*B[l][j];
            }
        }
    }
}

void matmult_knm(int m,int n,int k,double **A,double **B,double **C) {
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            C[i][j] = 0;
        }
    }
    for (int l=0;l<k;l++) {
        for (int j=0;j<n;j++) {
            for (int i=0;i<m;i++) {
                C[i][j] += A[i][l]*B[l][j];
            }
        }
    }
}

void matmult_blk(int m,int n,int k,double **A,double **B,double **C, int bs) {
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            C[i][j] = 0;
        }
    }
    for (int i0=0;i0<m;i0+=bs) {
        for (int l0=0;l0<k;l0+=bs) {
            for (int j0=0;j0<n;j0+=bs) {
                for (int i=i0;i<((i0+bs)<m?(i0+bs):m);i++) {
                    for (int l=l0;l<((l0+bs)<k?(l0+bs):k);l++) {
                        for (int j=j0;j<((j0+bs)<n?(j0+bs):n);j++) {
                            C[i][j] += A[i][l]*B[l][j];
                        }
                    }
                }
            }
        }
    }
}
