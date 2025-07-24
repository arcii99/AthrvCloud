//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 1000
#define MAX_ELEMENT 2000

int node[MAX_ELEMENT][2], elem_num, node_num;
float G[MAX_NODE][MAX_NODE], B[MAX_NODE][MAX_NODE];

void add_resistor(int n1, int n2, float value)
{
    if (n1 > node_num) {
        node_num = n1;
    }
    if (n2 > node_num) {
        node_num = n2;
    }
    G[n1][n1] += 1.0 / value;
    G[n2][n2] += 1.0 / value;
    G[n1][n2] += -1.0 / value;
    G[n2][n1] += -1.0 / value;
}

void add_current_source(int n1, int n2, float value)
{
    if (n1 > node_num) {
        node_num = n1;
    }
    if (n2 > node_num) {
        node_num = n2;
    }
    G[n1][n2] += 1.0;
    G[n2][n1] += -1.0;
    B[n1][0] += -value;
    B[n2][0] += value;
}

void solve_circuit()
{
    float det, temp;
    int i, j, k;

    for (i = 1; i <= node_num; i++) {
        for (j = 1; j <= node_num; j++) {
            G[i][j] += B[i][j];
        }
    }

    for (k = 1; k <= node_num - 1; k++) {
        for (i = k + 1; i <= node_num; i++) {
            temp = G[i][k] / G[k][k];
            for (j = k + 1; j <= node_num; j++) {
                G[i][j] += -temp * G[k][j];
            }
            B[i][0] += -temp * B[k][0];
        }
    }

    det = 1.0;
    for (i = 1; i <= node_num; i++) {
        det *= G[i][i];
    }

    printf("The determinant is %.6f\n", det);

    for (i = node_num; i >= 1; i--) {
        for (j = i + 1; j <= node_num; j++) {
            B[i][0] += -G[i][j] * B[j][0];
        }
        B[i][0] /= G[i][i];
    }

    printf("The solution is:\n");
    for (i = 1; i <= node_num; i++) {
        printf("V%d = %.6f\n", i, B[i][0]);
    }
}

int main()
{
    int i;
    float value;

    elem_num = 5;
    add_resistor(1, 2, 2.0);
    add_resistor(1, 3, 3.0);
    add_resistor(2, 3, 4.0);
    add_current_source(3, 4, 5.0);
    add_resistor(4, 1, 1.0);

    solve_circuit();
    return 0;
}