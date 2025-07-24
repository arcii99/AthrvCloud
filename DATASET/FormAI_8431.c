//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Variables Initialization
    int i, j;
    int w = 10; // Watermark Size
    int N = 64; // Image Size
    int x[64][64]; // Original Image
    int y[64][64]; // Watermarked Image
    double g0[10] = {0.269, 0.0099, -0.0867, 0.760, 0.4946, -0.2778, -0.0825, 0.1870, 0.0421, -0.1237};  // Gaussian Masked Filter
    double alpha = 1.0;  // Normalization Factor

    // Reading the Original Image from file
    FILE *fp = fopen("cimage.raw", "rb");
    if(fp == NULL)
    {
        printf("File not found!\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fread(x, 1, file_size, fp);
    fclose(fp);

    // Creating a Watermark Vector
    int wm[10] = {1, 1, 0, 1, 0, 1, 0, 0, 1, 0};  // Watermark Bit Array

    // Embedding the Watermark into the Image using DWT Techniques
    for(i=0;i<N;i+=w)
    {
        for(j=0;j<N;j+=w)
        {
            // Picking a 10x10 Block from the Image
            int block[10][10];
            for(int a=0;a<w;a++)
            {
                for(int b=0;b<w;b++)
                {
                    block[a][b] = x[i+a][j+b];
                }
            }

            // Applying 2D Discrete Wavelet Transform
            double dwt[10][10];
            for(int a=0;a<w;a++)
            {
                for(int b=0;b<w;b++)
                {
                    dwt[a][b] = 0;
                    for(int c=0;c<w;c++)
                    {
                        dwt[a][b] += block[a][c] * g0[c];
                    }
                }
            }

            // Applying Watermarking using Statistical Techniques
            double mean = 0.0;
            double SD = 0.0;
            for(int a=0;a<w;a++)
            {
                for(int b=0;b<w;b++)
                {
                    mean += dwt[a][b];
                }
            }
            mean /= w*w;

            for(int a=0;a<w;a++)
            {
                for(int b=0;b<w;b++)
                {
                    SD += pow((dwt[a][b] - mean), 2);
                }
            }
            SD /= w*w;
            SD = sqrt(SD);

            double threshold = alpha * SD;
            for(int a=0;a<w;a++)
            {
                for(int b=0;b<w;b++)
                {
                    if(wm[a*w+b] == 1)
                    {
                        if(dwt[a][b] < threshold)
                        {
                            dwt[a][b] += threshold;
                        }
                    }
                    else
                    {
                        if(dwt[a][b] < threshold)
                        {
                            dwt[a][b] -= threshold;
                        }
                    }
                }
            }

            // Applying 2D Inverse Discrete Wavelet Transform
            for(int a=0;a<w;a++)
            {
                for(int b=0;b<w;b++)
                {
                    double v = 0;
                    for(int c=0;c<w;c++)
                    {
                        v += dwt[a][c] * g0[b-c+w-1];
                    }
                    block[a][b] = (int)round(v);
                }
            }

            // Storing the Watermarked Block Back to the Image
            for(int a=0;a<w;a++)
            {
                for(int b=0;b<w;b++)
                {
                    y[i+a][j+b] = block[a][b];
                }
            }
        }
    }

    // Writing the Watermarked Image to file
    FILE *fpw = fopen("watermarked_image.raw", "wb");
    if(fpw == NULL)
    {
        printf("Could not create output file!\n");
        exit(1);
    }
    fwrite(y, 1, file_size, fpw);
    fclose(fpw);

    printf("Process Completed. Check watermarked_image.raw\n");

    return 0;
}