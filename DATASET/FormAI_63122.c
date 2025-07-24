//FormAI DATASET v1.0 Category: Digital signal processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

/* Implementation of Discrete Fourier Transform */
void DFT(int *input, int *real_output, int *imag_output, int size) {
    int n, k;
    for (k = 0; k < size; ++k) {
        real_output[k] = 0;
        imag_output[k] = 0;
        for (n = 0; n < size; ++n) {
            real_output[k] += input[n] * cos(2 * PI * k * n / size);
            imag_output[k] -= input[n] * sin(2 * PI * k * n / size);
        }
    }
}

/* Implementation of Fast Fourier Transform */
void FFT(int *input, int *real_output, int *imag_output, int size) {
    int i, k, n1, n2, a;
    double c, s, t1, t2;
    int log_size = log(size) / log(2);
  
    for (i = 0; i < size; ++i) {
        real_output[i] = input[i];
        imag_output[i] = 0;
    }

    n1 = 0;
    n2 = 1;

    for (i = 0; i < log_size; ++i) {
        n1 = n2;
        n2 <<= 1;
      
        for (k = 0; k < n1; ++k) {
            c = cos(PI * k / n1);
            s = sin(PI * k / n1);
            for (a = k; a < size; a += n2) {
                t1 = real_output[a + n1] * c - imag_output[a + n1] * s;
                t2 = real_output[a + n1] * s + imag_output[a + n1] * c;
                real_output[a + n1] = real_output[a] - t1;
                imag_output[a + n1] = imag_output[a] - t2;
                real_output[a] += t1;
                imag_output[a] += t2;
            }
        }
    }
}

int main() {
    int size = 16;
    int input[] =
        {0, 1, 2, 3, 4, 5, 6, 7,
         8, 9, 10, 11, 12, 13, 14, 15};
    int real_output[size], imag_output[size];

    printf("Input sequence:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", input[i]);
    }

    DFT(input, real_output, imag_output, size);

    printf("\n\nDFT Output:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d + i%d\n", real_output[i], imag_output[i]);
    }

    FFT(input, real_output, imag_output, size);

    printf("\nFFT Output:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d + i%d\n", real_output[i], imag_output[i]);
    }

    return 0;
}