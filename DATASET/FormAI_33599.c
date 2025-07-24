//FormAI DATASET v1.0 Category: Image compression ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLOCK_SIZE 8
#define QUALITY 50

void dct(double matrix[BLOCK_SIZE][BLOCK_SIZE], double dct_matrix[BLOCK_SIZE][BLOCK_SIZE])
{
    int i,j,x,y;
    double ci,cj,sum;
    double c,s;

    for(i=0;i<BLOCK_SIZE;i++)
    {
        for(j=0;j<BLOCK_SIZE;j++)
        {
            if(i==0)
                ci = sqrt(1.0/BLOCK_SIZE);
            else
                ci = sqrt(2.0/BLOCK_SIZE);

            if(j==0)
                cj = sqrt(1.0/BLOCK_SIZE);
            else
                cj = sqrt(2.0/BLOCK_SIZE);

            sum = 0;

            for(x=0;x<BLOCK_SIZE;x++)
            {
                for(y=0;y<BLOCK_SIZE;y++)
                {
                    c = (2*x + 1)*i*M_PI/(2*BLOCK_SIZE);
                    s = (2*y + 1)*j*M_PI/(2*BLOCK_SIZE);

                    sum+= matrix[x][y] * cos(c) * cos(s);
                }
            }

            dct_matrix[i][j] = ci * cj * sum;
        }
    }
}

void compress(double dct_matrix[BLOCK_SIZE][BLOCK_SIZE], double quantization_matrix[BLOCK_SIZE][BLOCK_SIZE])
{
    int i,j;

    for(i=0;i<BLOCK_SIZE;i++)
    {
        for(j=0;j<BLOCK_SIZE;j++)
        {
            dct_matrix[i][j] = round(dct_matrix[i][j] / quantization_matrix[i][j]);
        }
    }
}

void dequantize(double dct_matrix[BLOCK_SIZE][BLOCK_SIZE], double quantization_matrix[BLOCK_SIZE][BLOCK_SIZE])
{
    int i,j;

    for(i=0;i<BLOCK_SIZE;i++)
    {
        for(j=0;j<BLOCK_SIZE;j++)
        {
            dct_matrix[i][j] = dct_matrix[i][j] * quantization_matrix[i][j];
        }
    }
}

void idct(double dct_matrix[BLOCK_SIZE][BLOCK_SIZE], double matrix[BLOCK_SIZE][BLOCK_SIZE])
{
    int i,j,x,y;
    double ci,cj,sum;
    double c,s;

    for(i=0;i<BLOCK_SIZE;i++)
    {
        for(j=0;j<BLOCK_SIZE;j++)
        {
            sum = 0;

            for(x=0;x<BLOCK_SIZE;x++)
            {
                for(y=0;y<BLOCK_SIZE;y++)
                {
                    if(x==0)
                        ci = sqrt(1.0/BLOCK_SIZE);
                    else
                        ci = sqrt(2.0/BLOCK_SIZE);

                    if(y==0)
                        cj = sqrt(1.0/BLOCK_SIZE);
                    else
                        cj = sqrt(2.0/BLOCK_SIZE);

                    c = (2*i + 1)*x*M_PI/(2*BLOCK_SIZE);
                    s = (2*j + 1)*y*M_PI/(2*BLOCK_SIZE);

                    sum+= ci * cj * dct_matrix[x][y] * cos(c) * cos(s);
                }
            }

            matrix[i][j] = round(sum);
        }
    }
}

void print_matrix(double matrix[BLOCK_SIZE][BLOCK_SIZE])
{
    int i,j;

    for(i=0;i<BLOCK_SIZE;i++)
    {
        for(j=0;j<BLOCK_SIZE;j++)
        {
            printf("%.0f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    double matrix[BLOCK_SIZE][BLOCK_SIZE] = {
        {140, 144, 147, 140, 140, 155, 179, 175},
        {144, 152, 140, 147, 140, 148, 167, 179},
        {152, 155, 136, 167, 163, 162, 152, 172},
        {168, 145, 156, 160, 152, 155, 136, 160},
        {162, 148, 156, 148, 140, 136, 147, 162},
        {147, 167, 140, 155, 155, 140, 136, 162},
        {136, 156, 123, 167, 162, 144, 140, 147},
        {148, 155, 136, 155, 152, 147, 147, 136}
    };

    double quantization_matrix[BLOCK_SIZE][BLOCK_SIZE] = {
        {16, 11, 10, 16, 24, 40, 51, 61},
        {12, 12, 14, 19, 26, 58, 60, 55},
        {14, 13, 16, 24, 40, 57, 69, 56},
        {14, 17, 22, 29, 51, 87, 80, 62},
        {18, 22, 37, 56, 68, 109, 103, 77},
        {24, 35, 55, 64, 81, 104, 113, 92},
        {49, 64, 78, 87, 103, 121, 120, 101},
        {72, 92, 95, 98, 112, 100, 103, 99}
    };

    double dct_matrix[BLOCK_SIZE][BLOCK_SIZE];
    double compressed_matrix[BLOCK_SIZE][BLOCK_SIZE];
    double decompressed_matrix[BLOCK_SIZE][BLOCK_SIZE];

    printf("Original Matrix\n");
    print_matrix(matrix);

    dct(matrix, dct_matrix);

    compress(dct_matrix, quantization_matrix);

    dequantize(dct_matrix, quantization_matrix);

    idct(dct_matrix, decompressed_matrix);

    printf("Decompressed Matrix\n");
    print_matrix(decompressed_matrix);

    return 0;
}