//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WIDTH 256
#define MAX_HEIGHT 256
#define FILTER_SIZE 3

int watermark[FILTER_SIZE][FILTER_SIZE] =
    {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };

void encrypt(unsigned char image[][MAX_WIDTH], int width, int height)
{
    int i, j, k, l, sum;

    unsigned char encrypted_image[MAX_HEIGHT][MAX_WIDTH] = {0};

    for(i=FILTER_SIZE/2; i<height-FILTER_SIZE/2; i++)
    {
        for(j=FILTER_SIZE/2; j<width-FILTER_SIZE/2; j++)
        {
            sum = 0;

            for(k=-FILTER_SIZE/2; k<=FILTER_SIZE/2; k++)
            {
                for(l=-FILTER_SIZE/2; l<=FILTER_SIZE/2; l++)
                {
                    sum += watermark[k+FILTER_SIZE/2][l+FILTER_SIZE/2] * image[i+k][j+l];
                }
            }

            encrypted_image[i][j] = sum%256;
        }
    }

    printf("\nEncrypted image:\n");

    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            printf("%d ", encrypted_image[i][j]);
        }
        printf("\n");
    }
}

void decrypt(unsigned char encrypted_image[][MAX_WIDTH], int width, int height)
{
    int i, j, k, l, sum;

    unsigned char decrypted_image[MAX_HEIGHT][MAX_WIDTH] = {0};

    for(i=FILTER_SIZE/2; i<height-FILTER_SIZE/2; i++)
    {
        for(j=FILTER_SIZE/2; j<width-FILTER_SIZE/2; j++)
        {
            sum = 0;

            for(k=-FILTER_SIZE/2; k<=FILTER_SIZE/2; k++)
            {
                for(l=-FILTER_SIZE/2; l<=FILTER_SIZE/2; l++)
                {
                    sum += watermark[k+FILTER_SIZE/2][l+FILTER_SIZE/2] * encrypted_image[i+k][j+l];
                }
            }

            decrypted_image[i][j] = sum/(FILTER_SIZE*FILTER_SIZE);
        }
    }

    printf("\nDecrypted image:\n");

    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            printf("%d ", decrypted_image[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j, width, height;

    unsigned char image[MAX_HEIGHT][MAX_WIDTH] = {0};

    printf("Enter dimensions of the image (width height): ");
    scanf("%d %d", &width, &height);

    printf("Enter the pixel values:\n");

    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            scanf("%hhu", &image[i][j]);
        }
    }

    encrypt(image, width, height);
    decrypt(image, width, height);

    return 0;
}