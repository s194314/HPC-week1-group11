#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-6 // Convergence threshold
#define MAX_ITER 10000 // Maximum number of iterations

void initialize_grid(double ***u, double ***f, int N, double delta);
void set_boundary_conditions(double ***u, int N);
void jacobi_iteration(double ***u, double ***u_new, double ***f, int N, double delta_squared, int *iterations);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <grid_size>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    double delta = 2.0 / (N - 1);
    double delta_squared = delta * delta;


    double ***u = malloc(N * sizeof(double **));
    double ***u_new = malloc(N * sizeof(double **));
    double ***f = malloc(N * sizeof(double **));

    for (int i = 0; i < N; i++) {
        u[i] = (double **)malloc(N * sizeof(double *));
        u_new[i] = (double **)malloc(N * sizeof(double *));
        f[i] = (double **)malloc(N * sizeof(double *));
        for (int j = 0; j < N; j++) {
            u[i][j] = (double *)calloc(N, sizeof(double));
            u_new[i][j] = (double *)calloc(N, sizeof(double));
            f[i][j] = (double *)calloc(N, sizeof(double));
        }
    }

    initialize_grid(u, f, N, delta);
    set_boundary_conditions(u, N);

    int iterations = 0;
    jacobi_iteration(u, u_new, f, N, delta_squared, &iterations);

    printf("Converged in %d iterations.\n", iterations);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            free(u[i][j]);
            free(u_new[i][j]);
            free(f[i][j]);
        }
        free(u[i]);
        free(u_new[i]);
        free(f[i]);
    }
    free(u);
    free(u_new);
    free(f);

    return 0;
}

void initialize_grid(double ***u, double ***f, int N, double delta) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                u[i][j][k] = 0.0;
                if (-1.0 + i * delta >= -1 && -1.0 + i * delta <= -3.0 / 8.0 &&
                    -1.0 + j * delta >= -1 && -1.0 + j * delta <= -0.5 &&
                    -1.0 + k * delta >= -2.0 / 3.0 && -1.0 + k * delta <= 0) {
                    f[i][j][k] = 200.0;
                } else {
                    f[i][j][k] = 0.0;
                }
            }
        }
    }
}

void set_boundary_conditions(double ***u, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            u[i][j][0] = 20.0; // z = -1
            u[i][j][N - 1] = 20.0; // z = 1
            u[i][0][j] = 0.0; // y = -1
            u[i][N - 1][j] = 20.0; // y = 1
            u[0][i][j] = 20.0; // x = -1
            u[N - 1][i][j] = 20.0; // x = 1
        }
    }
}

void jacobi_iteration(double ***u, double ***u_new, double ***f, int N, double delta_squared, int *iterations) {
    double max_residual;
    do {
        max_residual = 0.0;

        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                for (int k = 1; k < N - 1; k++) {
                    u_new[i][j][k] = (1.0 / 6.0) * (
                        u[i - 1][j][k] + u[i + 1][j][k] +
                        u[i][j - 1][k] + u[i][j + 1][k] +
                        u[i][j][k - 1] + u[i][j][k + 1] +
                        delta_squared * f[i][j][k]
                    );

                    double residual = fabs(u_new[i][j][k] - u[i][j][k]);
                    if (residual > max_residual) {
                        max_residual = residual;
                    }
                }
            }
        }

        set_boundary_conditions(u_new, N);

        double ***temp = u;
        u = u_new;
        u_new = temp;

        (*iterations)++;
    } while (max_residual > EPSILON && *iterations < MAX_ITER);
}
