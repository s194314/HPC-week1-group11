//
// Created by Zahed on 08/01/2025.
//


void initi(int m, int n, double **C) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }
}



// mnk
void matmult_nat(int m, int n, int k, double **A, double **B, double **C) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < k; l++) {
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }
}




void matmult_nat1(int m, int n, int k, double **A, double **B, double **C) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int l = 0; l < k; l++) {
                sum += A[i][l] * B[l][j];
            }
            C[i][j] = sum;
        }
    }
}



void matmult_nat2(int m, int n, int k, double **A, double **B, double **C) {
    initi(m, n, C);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            double sum = 0.0;
            for (int l = 0; l < k; l++) {
                sum += A[i][l] * B[l][j];
            }
            C[i][j] += sum;
        }
    }
}




void matmult_mkn(int m, int n, int k, double **A, double **B, double **C) {
    for (int i = 0; i < m; i++) {
        // Initializes C
        for (int j = 0; j < n; j++) {
            C[i][j] = 0.0;
        }
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < n; l++) {
                C[i][l] += A[i][j] * B[j][l];
            }
        }
    }
}



void matmult_mkn2(int m, int n, int k, double **A, double **B, double **C) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {

            for (int l = 0; l < n; l++) {
                C[i][l] += A[i][j] * B[j][l];
            }
        }
    }
}


void matmult_nmk(int m, int n, int k, double **A, double **B, double **C) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            for (int l = 0; l < k; l++) {
                C[i][j]  += A[i][l] * B[l][j];
            }
        }
    }
}

void matmult_nmk2(int m, int n, int k, double **A, double **B, double **C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double sum = 0.0;
            for (int l = 0; l < k; l++) {
                sum += A[j][l] * B[l][i];
            }
            C[j][i] = sum;
        }
    }
}


void matmult_nkm(int m, int n, int k, double **A, double **B, double **C) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < m; l++) {
                C[l][i] += A[l][j] * B[j][i];
            }
        }
    }
}




void matmult_kmn(int m, int n, int k, double **A, double **B, double **C) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < n; l++) {
                C[j][l] += A[j][i] * B[i][l];
            }
        }
    }
}

void matmult_knm(int m, int n, int k, double **A, double **B, double **C) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }


    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            double temp = B[i][j];
            for (int l = 0; l < m; l++) {
                C[l][j] += A[l][i] * temp;
            }
        }
    }
}

