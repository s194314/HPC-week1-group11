#include <stdio.h>
#include <stdlib.h>
#include <time.h>




double **dmalloc_2d(int m, int n) {
    if (m <= 0 || n <= 0) return NULL;
    double **A = malloc(m * sizeof(double *));
    if (A == NULL) return NULL;
    A[0] = malloc(m * n * sizeof(double));
    if (A[0] == NULL) {
        free(A);
        return NULL;
    }
    for (int i = 1; i < m; i++) {
        A[i] = A[0] + i * n;
/*        printf("%d\n", A[i]);
        printf("\n");*/
    }

    return A;
}


void dfree_2d(double **A) {
    free(A[0]);
    free(A);
}

int random_num() {
    srand(time(NULL));
    return rand() % 11;
}

void init_2d(double **A, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = i + j;
        }
    }
}

void print_2d(double **A, int m, int n) {
    printf("\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            double val = A[i][j];
            printf("%f ", val);
        }
        printf("\n");

    }
    printf("\n");
}


// mnk
void matmult_nat(int m, int n, int k, double **A, double **B, double **C) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            double sum = 0.0;
            for (int p = 0; p < k; p++) {
                sum += A[i][p] * B[p][j];
            }
            C[i][j] += sum;
        }
    }
}



void free_2d(double **A) {
    free(A[0]);
    free(A);
}


void init_data(int m, int n, double **A, double **B) {

    int i, j;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
            A[i][j] = 1.0;
            B[i][j] = 2.0;
        }

}


/*int main() {
    //printf("Hello, World!\n");

    int m = 4, n = 4;
    double **A = dmalloc_2d(m, n);

    init_2d(A, m, n);
    print_2d(A, m, n);




    return 0;
}*/






/*
#define M 4
#define K 3
#define N 2
*/

//#define NREPEAT 100
#define mytimer clock
#define delta_t(a, b) (1e3 * (b - a) / CLOCKS_PER_SEC)

int main() {
    printf("Hello world");

/*    double A[M][K] = {
            {1.0, -3.0, 4.0},
            {2.0, 0.0, 5.0},
            {1.0, -3.0, 4.0},
            {0.0, 1.0, -2.0}
    };

    double *A_ptrs[M];
    for (int i = 0; i < M; i++) {
        A_ptrs[i] = A[i];
    }

    double B[K][N] = {
            {-2.0, 1.0},
            {0.0, 4.0},
            {1.0, 0.0}
    };



    double *B_ptrs[K];
    for (int i = 0; i < K; ++i) {
        B_ptrs[i] = B[i];
    }


    printf("A:\n");
    print_2d(A_ptrs, M, K);
    printf("B:\n");
    print_2d(B_ptrs, K, N);


    double **C = dmalloc_2d(M, N);

    matmult_nat(M, N, K, A_ptrs, B_ptrs, C);

    print_2d(C, M, N);*/






/*
    int n, k, N = 100;
    double **A, **B, **C;
    double tcpu1;

    clock_t t1, t2;

    for (int m = 200; m <= 3500; m += 300) {
        n = m + 25;

        *//* Allocate memory *//*
        A = dmalloc_2d(m, n);
        B = dmalloc_2d(m, n);
        C = dmalloc_2d(m, n);
        if (A == NULL || B == NULL | C == NULL) {
            fprintf(stderr, "Memory allocation error...\n");
            exit(EXIT_FAILURE);
        }

        *//* initialize with useful data - last argument is reference *//*
        init_data(m, n, A, B);

        *//* timings for matadd *//*
        t1 = mytimer();
        for (int i = 0; i < N; i++)
            matmult_nat(m, n, A, B, C);
        t2 = mytimer();
        tcpu1 = delta_t(t1, t2) / N;

        //check_results("main", m, n, C);

        *//* Print n and results  *//*
        printf("%4d %4d %8.3f\n", m, n, tcpu1);

        *//* Free memory *//*
        free_2d(A);
        free_2d(B);
        free_2d(C);
    }*/


    return 0;
}
