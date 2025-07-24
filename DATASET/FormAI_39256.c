//FormAI DATASET v1.0 Category: Image compression ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLOCK_LENGTH 8
#define N 64

int quantization_matrix[N] = {
    16, 11, 10, 16, 24,  40,  51,  61,
    12, 12, 14, 19, 26,  58,  60,  55,
    14, 13, 16, 24, 40,  57,  69,  56,
    14, 17, 22, 29, 51,  87,  80,  62,
    18, 22, 37, 56, 68, 109, 103,  77,
    24, 35, 55, 64, 81, 104, 113,  92,
    49, 64, 78, 87, 103, 121, 120, 101,
    72, 92, 95, 98, 112, 100, 103,  99
};

double cosine(int u, int v, int x, int y) {
    double cu, cv, sum = 0.0;

    if (u == 0) {
        cu = 1.0 / sqrt(2);
    } else {
        cu = 1.0;
    }

    if (v == 0) {
        cv = 1.0 / sqrt(2);
    } else {
        cv = 1.0;
    }

    for (int i = 0; i < BLOCK_LENGTH; i++) {
        for (int j = 0; j < BLOCK_LENGTH; j++) {
            sum += cos((2 * i + 1) * u * M_PI / (2 * BLOCK_LENGTH)) *
                   cos((2 * j + 1) * v * M_PI / (2 * BLOCK_LENGTH)) *
                   x * y;
        }
    }

    return 0.25 * cu * cv * sum;
}

void forward_discrete_cosine_transform(int *in, double *out) {
    double alpha, beta;

    for (int u = 0; u < BLOCK_LENGTH; u++) {
        for (int v = 0; v < BLOCK_LENGTH; v++) {
            alpha = u == 0 ? 1.0 / sqrt(2) : 1.0;
            beta = v == 0 ? 1.0 / sqrt(2) : 1.0;

            double sum = 0;
            for (int x = 0; x < BLOCK_LENGTH; x++) {
                for (int y = 0; y < BLOCK_LENGTH; y++) {
                    sum += in[x * BLOCK_LENGTH + y] * cosine(u, v, x, y);
                }
            }
            out[u * BLOCK_LENGTH + v] = alpha * beta * sum;
        }
    }
}

void quantize(double *in, int *out) {
    int index = 0;

    for (int u = 0; u < BLOCK_LENGTH; u++) {
        for (int v = 0; v < BLOCK_LENGTH; v++) {
            out[index] = (int)round(in[u * BLOCK_LENGTH + v] / quantization_matrix[index]);
            index++;
        }
    }
}

void dequantize(int *in, double *out) {
    int index = 0;

    for (int u = 0; u < BLOCK_LENGTH; u++) {
        for (int v = 0; v < BLOCK_LENGTH; v++) {
            out[u * BLOCK_LENGTH + v] = in[index] * quantization_matrix[index];
            index++;
        }
    }
}

void inverse_discrete_cosine_transform(double *in, int *out) {
    double sum;
    int index;

    for (int x = 0; x < BLOCK_LENGTH; x++) {
        for (int y = 0; y < BLOCK_LENGTH; y++) {
            sum = 0;

            for (int u = 0; u < BLOCK_LENGTH; u++) {
                for (int v = 0; v < BLOCK_LENGTH; v++) {
                    index = u * BLOCK_LENGTH + v;
                    sum += (in[index] * cosine(u, v, x, y));
                }
            }

            out[x * BLOCK_LENGTH + y] = (int)round(sum);
        }
    }
}

int main() {
    int image[N] = {      
        52, 55, 61, 66,  70,  61,  64, 73,
        63, 59, 55, 90, 109,  85,  69, 72,
        62, 59, 68, 113, 144, 104,  66, 73,
        63, 58, 71, 122, 154, 106,  70, 69,
        67, 61, 68, 104, 126,  88,  68, 70,
        79, 65, 60, 70,  77,  68,  58, 75,
        85, 71, 64, 59,  55,  61,  65, 83,
        87, 79, 69, 68,  65,  76,  78, 94
    };

    double dct[N], dequantized[N];
    int quantized[N], result[N];

    // Forward DCT
    forward_discrete_cosine_transform(image, dct);

    // Quantize
    quantize(dct, quantized);

    // Dequantize
    dequantize(quantized, dequantized);

    // Inverse DCT
    inverse_discrete_cosine_transform(dequantized, result);

    printf("Input Image: \n");
    for (int i = 0; i < BLOCK_LENGTH; i++) {
        for (int j = 0; j < BLOCK_LENGTH; j++) {
            printf("%d ", image[i * BLOCK_LENGTH + j]);
        }
        printf("\n");
    }

    printf("\nQuantization matrix: \n");
    for (int i = 0; i < BLOCK_LENGTH; i++) {
        for (int j = 0; j < BLOCK_LENGTH; j++) {
            printf("%d ", quantization_matrix[i * BLOCK_LENGTH + j]);
        }
        printf("\n");
    }

    printf("\nQuantized DCT: \n");
    for (int i = 0; i < BLOCK_LENGTH; i++) {
        for (int j = 0; j < BLOCK_LENGTH; j++) {
            printf("%d ", quantized[i * BLOCK_LENGTH + j]);
        }
        printf("\n");
    }

    printf("\nDequantized DCT: \n");
    for (int i = 0; i < BLOCK_LENGTH; i++) {
        for (int j = 0; j < BLOCK_LENGTH; j++) {
            printf("%lf ", dequantized[i * BLOCK_LENGTH + j]);
        }
        printf("\n");
    }

    printf("\nOutput Image: \n");
    for (int i = 0; i < BLOCK_LENGTH; i++) {
        for (int j = 0; j < BLOCK_LENGTH; j++) {
            printf("%d ", result[i * BLOCK_LENGTH + j]);
        }
        printf("\n");
    }

    return 0;
}