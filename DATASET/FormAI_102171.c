//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXNODE 10000
#define MAXHDR  100000

/* Definition of a node */
struct node
{
    int id;
    int type;  // 0 for resistor, 1 for inductor, 2 for capacitor
    double value;
};
struct node nodes[MAXNODE];
int n_nodes = 0;

/* Definition of a header */
struct header
{
    int src;
    int dst;
    double value;
};
struct header headers[MAXHDR];
int n_headers = 0;

/* Definition of a solver */
double A[MAXNODE][MAXNODE], B[MAXNODE], X[MAXNODE];
void solve(int n)
{
    int i, j, k;
    for (k = 0; k < n; ++k)
    {
        for (i = k + 1; i < n; ++i)
        {
            double factor = A[i][k] / A[k][k];
            for (j = 0; j < n; ++j)
            {
                A[i][j] -= factor * A[k][j];
            }
            B[i] -= factor * B[k];
        }
    }
    for (i = n - 1; i >= 0; --i)
    {
        X[i] = B[i];
        for (j = i + 1; j < n; ++j)
        {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
    }
}

/* Definition of a main function */
int main()
{
    /* Define nodes */
    nodes[n_nodes++] = (struct node) { .id = 0, .type = 0, .value = 10.0 };
    nodes[n_nodes++] = (struct node) { .id = 1, .type = 2, .value = 0.01 };
    nodes[n_nodes++] = (struct node) { .id = 2, .type = 0, .value = 20.0 };
    nodes[n_nodes++] = (struct node) { .id = 3, .type = 1, .value = 0.001 };
    nodes[n_nodes++] = (struct node) { .id = 4, .type = 2, .value = 0.001 };

    /* Define headers */
    headers[n_headers++] = (struct header) { .src = 0, .dst = 1, .value = 1.0 };
    headers[n_headers++] = (struct header) { .src = 1, .dst = 2, .value = 1.0 };
    headers[n_headers++] = (struct header) { .src = 2, .dst = 3, .value = 1.0 };
    headers[n_headers++] = (struct header) { .src = 3, .dst = 4, .value = 1.0 };
    headers[n_headers++] = (struct header) { .src = 4, .dst = 1, .value = 1.0 };

    /* Build circuit matrix */
    int i, j;
    for (i = 0; i < n_nodes; ++i)
    {
        double sum = 0.0;
        for (j = 0; j < n_headers; ++j)
        {
            if (headers[j].src == i)
            {
                sum += 1.0 / headers[j].value;
                A[i][headers[j].dst] += 1.0 / headers[j].value;
            }
            else if (headers[j].dst == i)
            {
                sum += 1.0 / headers[j].value;
                A[i][headers[j].src] += 1.0 / headers[j].value;
            }
        }
        A[i][i] = sum;
    }
    for (i = 0; i < n_nodes; ++i)
    {
        if (nodes[i].type == 1)
        {
            A[i][i] += nodes[i].value;
        }
        else if (nodes[i].type == 2)
        {
            A[i][i] += 1.0 / nodes[i].value;
        }
        B[i] = 0.0;
    }
    B[1] = 10.0;

    /* Solve circuit */
    solve(n_nodes);

    /* Print output */
    for (i = 0; i < n_nodes; ++i)
    {
        printf("V%d = %g\n", i, X[i]);
    }

    return 0;
}