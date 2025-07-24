//FormAI DATASET v1.0 Category: Digital signal processing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

double hamming_window(int n, int length) {
    /* Hamming window function */
    return 0.54 - 0.46*cos(2*PI*n/(length-1));
}

void convolve(double x[], int N, double h[], int M, double y[]) {
    /* Convolution of two sequences x and h using the overlap-add method */
    int L = M + N - 1;
    int P = 2;
    while (P < L) P *= 2;

    /* Create the padded signals */
    double *xp = (double*)malloc(P * sizeof(double));
    double *hp = (double*)malloc(P * sizeof(double));
    for (int i=0; i<P; i++) {
        xp[i] = (i<N) ? x[i] : 0;
        hp[i] = (i<M) ? h[i] : 0;
    }

    /* Pad with zeros so that the signal length is a power of 2 */
    for (int i=N; i<P; i++) xp[i] = 0;
    for (int i=M; i<P; i++) hp[i] = 0;

    /* Compute the FFT of the padded signals */
    double *Xp_real = (double*)malloc(P * sizeof(double));
    double *Xp_imag = (double*)malloc(P * sizeof(double));
    double *Hp_real = (double*)malloc(P * sizeof(double));
    double *Hp_imag = (double*)malloc(P * sizeof(double));
    fft(xp, P, Xp_real, Xp_imag);
    fft(hp, P, Hp_real, Hp_imag);

    /* Multiply the FFTs of the signals */
    double *Yp_real = (double*)malloc(P * sizeof(double));
    double *Yp_imag = (double*)malloc(P * sizeof(double));
    for (int i=0; i<P; i++) {
        Yp_real[i] = Xp_real[i]*Hp_real[i] - Xp_imag[i]*Hp_imag[i];
        Yp_imag[i] = Xp_real[i]*Hp_imag[i] + Xp_imag[i]*Hp_real[i];
    }

    /* Compute the inverse FFT of the product */
    fft(Yp_real, Yp_imag, P);

    /* Extract the real part and scale */
    for (int i=0; i<L; i++) {
        y[i] = Yp_real[i] / P;
    }

    /* Free memory */
    free(xp);
    free(hp);
    free(Xp_real);
    free(Xp_imag);
    free(Hp_real);
    free(Hp_imag);
    free(Yp_real);
    free(Yp_imag);
}

void fft(double x[], int N, double X_real[], double X_imag[]) {
    /* Fast Fourier transform of a real sequence using the decimation-in-time algorithm */
    if (N == 1) {
        X_real[0] = x[0];
        X_imag[0] = 0;
        return;
    }

    /* Split the sequence into even and odd parts */
    double *xe = (double*)malloc((N/2) * sizeof(double));
    double *xo = (double*)malloc((N/2) * sizeof(double));
    for (int i=0; i<N/2; i++) {
        xe[i] = x[2*i];
        xo[i] = x[2*i+1];
    }

    /* Compute the FFT of the even and odd parts recursively */
    double *Xe_real = (double*)malloc((N/2) * sizeof(double));
    double *Xe_imag = (double*)malloc((N/2) * sizeof(double));
    double *Xo_real = (double*)malloc((N/2) * sizeof(double));
    double *Xo_imag = (double*)malloc((N/2) * sizeof(double));
    fft(xe, N/2, Xe_real, Xe_imag);
    fft(xo, N/2, Xo_real, Xo_imag);

    /* Combine the sub-FFT's */
    for (int k=0; k<N/2; k++) {
        double theta = -2 * PI * k / N;
        double W_real = cos(theta);
        double W_imag = sin(theta);
        X_real[k] = Xe_real[k] + W_real*Xo_real[k] - W_imag*Xo_imag[k];
        X_imag[k] = Xe_imag[k] + W_real*Xo_imag[k] + W_imag*Xo_real[k];
        X_real[k+N/2] = Xe_real[k] - W_real*Xo_real[k] + W_imag*Xo_imag[k];
        X_imag[k+N/2] = Xe_imag[k] - W_real*Xo_imag[k] - W_imag*Xo_real[k];
    }

    /* Free memory */
    free(xe);
    free(xo);
    free(Xe_real);
    free(Xe_imag);
    free(Xo_real);
    free(Xo_imag);
}

int main() {
    /* Low-pass filter design using the Kaiser window method */
    double fc = 1200.0;  // Cutoff frequency
    double fs = 8000.0;  // Sampling frequency
    double T = 1.0/fs;   // Sampling period
    int N = 61;          // Filter order (must be odd)
    double beta = 5.0;   // Kaiser window parameter
    double h[N];         // Filter coefficients

    /* Compute the impulse response of the filter */
    for (int n=0; n<N; n++) {
        h[n] = (2*fc/fs)*sin(2*PI*fc*(n-N/2)*T) / (n-N/2)*T;
        h[n] *= hamming_window(n, N);
    }

    /* Normalize the filter coefficients */
    double sum = 0;
    for (int n=0; n<N; n++) {
        sum += h[n];
    }
    for (int n=0; n<N; n++) {
        h[n] /= sum;
    }

    /* Print the filter coefficients */
    printf("Filter coefficients:\n");
    for (int n=0; n<N; n++) {
        printf("h[%d] = %f\n", n, h[n]);
    }

    /* Perform signal filtering using convolution */
    int num_samples = 10000;
    double x[num_samples];  // Input signal
    double y[num_samples];  // Output signal
    for (int n=0; n<num_samples; n++) {
        x[n] = 0.5*sin(2*PI*500*n*T) + sin(2*PI*1200*n*T) + 0.5*sin(2*PI*2000*n*T);
    }
    convolve(x, num_samples, h, N, y);

    /* Save the filtered signal to a file for visualization */
    FILE *fp = fopen("filtered_signal.txt", "w");
    for (int n=0; n<num_samples; n++) {
        fprintf(fp, "%d\t%f\t%f\n", n, x[n], y[n]);
    }
    fclose(fp);

    return 0;
}