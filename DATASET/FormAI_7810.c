//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

void fft(double *x, double *Xre, double *Xim, int n, int m, int sign)
{
    int i, j, k, n1, n2, a;
    double c, s, t1, t2;

    for (i = 0; i < m; i++) {
        n1 = 1 << i;
        n2 = n1 << 1;
        for (j = 0; j < n1; j++) {
            for (k = j; k < n; k += n2) {
                t1 = x[k] + x[k + n1];
                t2 = x[k] - x[k + n1];
                x[k] = t1;
                x[k + n1] = t2;
                t1 = sign * (Xim[k] + Xim[k + n1]);
                t2 = sign * (Xre[k] - Xre[k + n1]);
                Xre[k] += Xre[k + n1];
                Xim[k] += Xim[k + n1];
                Xre[k + n1] = t2 * c - t1 * s;
                Xim[k + n1] = t1 * c + t2 * s;
            }
            c = cos(M_PI*j/n1);
            s = sin(M_PI*j/n1);
        }
    }
    j = 0;
    for (i = 1; i < n-1; i++) {
        for (k = n >> 1; k > (j ^= k); k >>= 1);
        if (i < j) {
            t1 = x[j];
            x[j] = x[i];
            x[i] = t1;
            t1 = Xre[j];
            Xre[j] = Xre[i];
            Xre[i] = t1;
            t1 = Xim[j];
            Xim[j] = Xim[i];
            Xim[i] = t1;
        }
    }
}

int main()
{
    double x[N], Xre[N], Xim[N];
    int i;
    for (i = 0; i < N; i++) {
        x[i] = sin(2*M_PI*i/N);
        Xre[i] = Xim[i] = 0;
    }
    
    fft(x, Xre, Xim, N, log2(N), 1);
    fft(x, Xre, Xim, N, log2(N), -1);
    
    for (i = 0; i < N; i++) {
        printf("x[%d] = %f\tXre[%d] = %f\tXim[%d] = %f\n",
            i, x[i], i, Xre[i], i, Xim[i]);
    }
    return 0;
}