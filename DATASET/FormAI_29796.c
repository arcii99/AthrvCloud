//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_DEVICES 1000

typedef struct {
    int node1, node2;
    double value;
} Device;

int num_nodes, num_devices;
double G[MAX_NODES][MAX_NODES], B[MAX_NODES][MAX_NODES], V[MAX_NODES], I[MAX_NODES];

Device devices[MAX_DEVICES];

void stamp_device(Device d) {
    if(d.node1 > 0) G[d.node1][d.node1] += 1.0 / d.value;
    if(d.node2 > 0) G[d.node2][d.node2] += 1.0 / d.value;
    if(d.node1 > 0 && d.node2 > 0) {
        G[d.node1][d.node2] -= 1.0 / d.value;
        G[d.node2][d.node1] -= 1.0 / d.value;
    }
}

void stamp_devices() {
    for(int i = 0; i < num_devices; i++) {
        stamp_device(devices[i]);
    }
}

void solve() {
    for(int i = 1; i <= num_nodes; i++) {
        for(int j = 1; j <= num_nodes; j++) {
            B[i][j] = G[i][j];
        }
    }

    for(int k = 1; k <= num_nodes; k++) {
        for(int i = 1; i <= num_nodes; i++) {
            if(i == k) continue;
            for(int j = 1; j <= num_nodes; j++) {
                if(j == k) continue;
                B[i][j] -= B[i][k] * B[k][j] / B[k][k];
            }
        }
    }

    for(int i = 1; i <= num_nodes; i++) {
        V[i] = B[i][num_nodes+1] / B[i][i];
    }

    for(int i = 1; i <= num_nodes; i++) {
        I[i] = 0.0;
        for(int j = 1; j <= num_nodes; j++) {
            I[i] += G[i][j] * V[j];
        }
    }
}

int main() {
    num_nodes = 5;
    num_devices = 7;
    devices[0] = (Device){1,2,1000};
    devices[1] = (Device){1,3,1000};
    devices[2] = (Device){2,3,2000};
    devices[3] = (Device){2,4,5000};
    devices[4] = (Device){3,4,2500};
    devices[5] = (Device){3,5,1000};
    devices[6] = (Device){4,5,500};
    stamp_devices();
    solve();
    printf("Node Voltages:\n");
    for(int i = 1; i <= num_nodes; i++) {
        printf("V(%d) = %.2f\n", i, V[i]);
    }
    printf("Device Currents:\n");
    for(int i = 0; i < num_devices; i++) {
        double current = (devices[i].node1 > 0 ? I[devices[i].node1] : 0) -
            (devices[i].node2 > 0 ? I[devices[i].node2] : 0);
        printf("I(%d) = %.2f\n", i+1, current);
    }
    return 0;
}