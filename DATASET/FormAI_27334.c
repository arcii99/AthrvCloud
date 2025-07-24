//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: rigorous
#include <stdio.h>
#include <math.h>

#define MAX_NODES 1000
#define AC_FREQ 50 // AC Frequency in Hz

double mag(double r, double i) {
    return sqrt(r * r + i * i);
}

double phase(double r, double i) {
    return atan(i / r);
}

double impedance(double r, double i) {
    return mag(r, i) * cos(phase(r, i));
}

double reactance(double r, double i) {
    return mag(r, i) * sin(phase(r, i));
}

int main() {
    int n, m, freq, node1, node2;
    double value, r, i, t;
    double a[MAX_NODES][MAX_NODES], b[MAX_NODES], x[MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
        b[i] = 0;
        x[i] = 0;
    }

    printf("Enter the number of components: ");
    scanf("%d", &m);

    for (int k = 1; k <= m; k++) {
        printf("Enter component %d's details (Node 1, Node 2, Value): ", k);
        scanf("%d %d %lf", &node1, &node2, &value);

        if (node1 != 0) {
            a[node1][node1] += 1 / impedance(value, 0);
        }

        if (node2 != 0) {
            a[node2][node2] += 1 / impedance(value, 0);
        }

        if (node1 != 0 && node2 != 0) {
            a[node1][node2] -= 1 / impedance(value, 0);
            a[node2][node1] -= 1 / impedance(value, 0);
        }
    }

    printf("Enter the frequency of AC source: ");
    scanf("%d", &freq);

    t = 2 * M_PI * freq / AC_FREQ;

    for (int i = 1; i <= n; i++) {
        printf("Enter voltage of Node %d: ", i);
        scanf("%lf %lf", &r, &i);
        b[i] = mag(r, i) * cos(phase(r, i) - t);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%lf  ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 1; i <= n; i++) {
        printf("%lf  ", b[i]);
    }
    printf("\n");

    // Gauss-Jordan elimination with pivoting
    for (int k = 1; k <= n; k++) {
        int i_max = k;
        double max = a[k][k];

        for (int i = k + 1; i <= n; i++) {
            if (fabs(a[i][k]) > fabs(max)) {
                max = a[i][k];
                i_max = i;
            }
        }

        if (i_max != k) {
            for (int j = k; j <= n; j++) {
                double temp = a[k][j];
                a[k][j] = a[i_max][j];
                a[i_max][j] = temp;
            }

            double temp = b[k];
            b[k] = b[i_max];
            b[i_max] = temp;
        }

        for (int i = k + 1; i <= n; i++) {
            double f = a[i][k] / a[k][k];

            for (int j = k + 1; j <= n; j++) {
                a[i][j] -= f * a[k][j];
            }

            b[i] -= f * b[k];
            a[i][k] = 0;
        }
    }

    // Backward substitution
    for (int i = n; i >= 1; i--) {
        double sum = b[i];

        for (int j = i + 1; j <= n; j++) {
            sum -= a[i][j] * x[j];
        }

        x[i] = sum / a[i][i];
    }

    printf("Solutions: \n");

    for (int i = 1; i <= n; i++) {
        printf("Node %d : %lf V + j%lf A \n", i, x[i], b[i+1] / reactance(a[i+1][i], 0));
    }

    return 0;
}