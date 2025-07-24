//FormAI DATASET v1.0 Category: Image compression ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 8
#define COLS 8

int main() {
    int i, j;

    int image[ROWS][COLS] = {  {  1,  1,  1,  1,  2,  3,  6,  8 },
                                {  1,  1,  1,  2,  2,  7,  9,  8 },
                                {  1,  1,  1,  2,  6,  8,  8,  8 },
                                {  1,  2,  3,  4,  7,  8,  8,  8 },
                                {  2,  3,  6,  8,  9,  8,  8,  8 },
                                {  3,  7,  8,  8,  8,  8,  8,  8 },
                                {  6,  9,  8,  8,  8,  8,  8,  8 },
                                {  8,  8,  8,  8,  8,  8,  8,  8 }};

    double dct[ROWS][COLS];

    double alpha_u, alpha_v, sum;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(i == 0) alpha_u = sqrt(1.0 / ROWS);
            else alpha_u = sqrt(2.0 / ROWS) * cos((2*i+1) * j * M_PI / (2*ROWS));

            if(j == 0) alpha_v = sqrt(1.0 / COLS);
            else alpha_v = sqrt(2.0 / COLS) * cos((2*j+1) * i * M_PI / (2*COLS));

            sum = 0.0;
            for(int m = 0; m < ROWS; m++) {
                for(int n = 0; n < COLS; n++) {
                    sum += (double)image[m][n] * cos((2*m+1) * i * M_PI / (2*ROWS)) * cos((2*n+1) * j * M_PI / (2*COLS));
                }
            }
            dct[i][j] = alpha_u * alpha_v * sum;
        }
    }

    double dct_quant[ROWS][COLS] = {    {  9,  5,  4,  4,  3,  2,  1,  1 },
                                        {  5,  4,  4,  3,  3,  1,  1,  1 },
                                        {  4,  4,  5,  4,  2,  1,  1,  1 },
                                        {  4,  3,  4,  4,  1,  1,  1,  1 },
                                        {  3,  3,  2,  1,  1,  1,  1,  1 },
                                        {  2,  1,  1,  1,  1,  1,  1,  1 },
                                        {  1,  1,  1,  1,  1,  1,  1,  1 },
                                        {  1,  1,  1,  1,  1,  1,  1,  1 }};

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            dct[i][j] /= dct_quant[i][j];
            dct[i][j] = round(dct[i][j]);
        }
    }

    int dct_int[ROWS][COLS];
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            dct_int[i][j] = (int)dct[i][j];
        }
    }

    printf("Original Image:\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    printf("\nDCT Compressed Image:\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", dct_int[i][j]);
        }
        printf("\n");
    }

    return 0;
}