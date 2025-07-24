//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int image[8][8] = {{240, 230, 140, 160, 200, 220, 210, 145},
                        {190, 170, 180, 150, 125, 135, 180, 190},
                        {230, 215, 190, 205, 200, 200, 190, 175},
                        {250, 230, 220, 190, 210, 220, 235, 240},
                        {180, 200, 210, 220, 235, 240, 230, 210},
                        {160, 175, 200, 210, 240, 235, 200, 170},
                        {150, 140, 180, 240, 220, 190, 150, 130},
                        {170, 190, 230, 215, 200, 180, 160, 155}};

    int watermark[8][8] = {{1, 2, 3, 4, 5, 6, 7, 8},
                            {9, 10, 11, 12, 13, 14, 15, 16},
                            {17, 18, 19, 20, 21, 22, 23, 24},
                            {25, 26, 27, 28, 29, 30, 31, 32},
                            {33, 34, 35, 36, 37, 38, 39, 40},
                            {41, 42, 43, 44, 45, 46, 47, 48},
                            {49, 50, 51, 52, 53, 54, 55, 56},
                            {57, 58, 59, 60, 61, 62, 63, 64}};

    // Generate pseudorandom matrix
    int seed = 1234;
    int prand[8][8];
    srand(seed);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            prand[i][j] = rand() % 256;
        }
    }

    // Digital watermarking
    double alfa = 0.75;
    int S[8][8];
    int C[8][8];
    double A[8][8];
    double B[8][8];
    int D[8][8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            S[i][j] = (watermark[i][j] + prand[i][j]) % 256;
            C[i][j] = (image[i][j] + S[i][j]) % 256;
            A[i][j] = C[i][j] / alfa;
            B[i][j] = floor(A[i][j] + 0.5);
            D[i][j] = (int)(B[i][j] * alfa) % 256;
        }
    }

    // Print results
    printf("Original image:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%4d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Watermark:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%4d ", watermark[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Pseudorandom matrix:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%4d ", prand[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Digital watermarking results:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%4d ", D[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}