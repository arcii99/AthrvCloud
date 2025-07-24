//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_NODES 5
#define H 0.1
#define TOL 1e-6

typedef struct element {
    int from;
    int to;
    double value;
} Element;

double f(double x, double y) {
    return x + y + pow(x, 2) * y;
}

void print_matrix(double **a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%.2lf ", a[i][j]);
        }
        printf("\n");
    }
}

void print_vector(double *v, int n) {
    printf("[ ");
    for (int i = 0; i < n; ++i) {
        printf("%.2lf ", v[i]);
    }
    printf("]\n");
}

double **create_matrix(int rows, int cols) {
    double **matrix = (double **) malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (double *) malloc(cols * sizeof(double));
    }
    return matrix;
}

void free_matrix(double **matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void gauss_jordan(double **a, double *b, int n) {
    double factor, temp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                factor = a[j][i] / a[i][i];
                for (int k = i; k < n; ++k) {
                    a[j][k] -= factor * a[i][k];
                }
                b[j] -= factor * b[i];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        temp = a[i][i];
        for (int j = 0; j < n; ++j) {
            a[i][j] /= temp;
        }
        b[i] /= temp;
    }
}

void solve(Element *elements, int num_elements) {
    double t = 0;
    double y[NUM_NODES] = {0}, y_prev[NUM_NODES] = {0};
    double **a, *b;
    int iterations = 0, converge = 0;

    printf("Initial conditions:\n");
    printf("t = %.2lf\n", t);
    for (int i = 0; i < NUM_NODES; ++i) {
        printf("y%d = %.6lf\n", i, y[i]);
    }
    printf("\n");

    while (!converge && iterations <= 1000) {
        a = create_matrix(NUM_NODES, NUM_NODES);
        b = (double *) malloc(NUM_NODES * sizeof(double));
        for (int i = 0; i < NUM_NODES; ++i) {
            b[i] = y_prev[i];
            a[i][i] = 1 / H;
        }
        for (int i = 0; i < num_elements; ++i) {
            int from = elements[i].from;
            int to = elements[i].to;
            double value = elements[i].value;
            if (from != -1) {
                a[from][from] += 1 / value;
                a[from][to] -= 1 / value;
            }
            if (to != -1) {
                a[to][to] += 1 / value;
                a[to][from] -= 1 / value;
            }
        }
        gauss_jordan(a, b, NUM_NODES);
        for (int i = 0; i < NUM_NODES; ++i) {
            y[i] = b[i] + f(t + H, b[i]);
        }
        converge = 1;
        for (int i = 0; i < NUM_NODES; ++i) {
            if (fabs(y[i] - y_prev[i]) > TOL) {
                converge = 0;
                break;
            }
        }
        printf("t = %.2lf:\n", t + H);
        for (int i = 0; i < NUM_NODES; ++i) {
            printf("y%d = %.6lf\n", i, y[i]);
        }
        printf("\n");
        t += H;
        for (int i = 0; i < NUM_NODES; ++i) {
            y_prev[i] = y[i];
        }
        free_matrix(a, NUM_NODES);
        free(b);
        ++iterations;
    }
    if (converge) {
        printf("Converged in %d iterations\n", iterations);
    } else {
        printf("Could not converge after %d iterations\n", iterations);
    }
}

int main() {
    Element elements[] = {
        {0, 1, 2},
        {1, 2, 1},
        {2, -1, 3},
        {-1, 3, 1},
        {3, 4, 2},
        {4, -1, 3},
    };
    int num_elements = sizeof(elements) / sizeof(elements[0]);
    solve(elements, num_elements);
    return 0;
}