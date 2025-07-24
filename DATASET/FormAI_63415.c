//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: invasive
#include <stdio.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_DEVICES 1000

typedef struct {
    int n1, n2;
    double value;
} Device;

int num_nodes = 0, num_devices = 0;
double G[MAX_NODES][MAX_NODES];
double B[MAX_NODES];
Device devices[MAX_DEVICES];

void add_device(int n1, int n2, double value) {
    Device device = { n1, n2, value };
    devices[num_devices++] = device;
}

void build_matrix() {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            G[i][j] = 0;
        }
        B[i] = 0;
    }
    for (int i = 0; i < num_devices; i++) {
        int n1 = devices[i].n1, n2 = devices[i].n2;
        double value = devices[i].value;
        if (n1 >= 0) G[n1][n1] += 1.0 / value;
        if (n2 >= 0) G[n2][n2] += 1.0 / value;
        if (n1 >= 0 && n2 >= 0) {
            G[n1][n2] += -1.0 / value;
            G[n2][n1] += -1.0 / value;
        }
    }
}

void solve_matrix() {
    for (int k = 0; k < num_nodes; k++) {
        int pivot = k;
        for (int i = k + 1; i < num_nodes; i++) {
            if (fabs(G[i][k]) > fabs(G[pivot][k])) pivot = i;
        }
        if (pivot != k) {
            for (int j = k; j < num_nodes; j++) {
                double tmp = G[k][j];
                G[k][j] = G[pivot][j];
                G[pivot][j] = tmp;
            }
            double tmp = B[k];
            B[k] = B[pivot];
            B[pivot] = tmp;
        }
        for (int i = k + 1; i < num_nodes; i++) {
            double factor = G[i][k] / G[k][k];
            for (int j = k; j < num_nodes; j++) {
                G[i][j] -= factor * G[k][j];
            }
            B[i] -= factor * B[k];
        }
    }
    for (int k = num_nodes - 1; k >= 0; k--) {
        B[k] /= G[k][k];
        for (int i = 0; i < k; i++) {
            B[i] -= G[i][k] * B[k];
            G[i][k] = 0;
        }
    }
}

int main() {
    add_device(0, 1, 1);
    add_device(1, 2, 2);
    add_device(2, -1, 3);
    num_nodes = 3;
    build_matrix();
    solve_matrix();
    printf("Node voltages: ");
    for (int i = 0; i < num_nodes; i++) {
        printf("%f ", B[i]);
    }
    printf("\n");
    return 0;
}