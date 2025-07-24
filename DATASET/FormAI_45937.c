//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLOCK_SIZE 8
#define ALPHA 0.1

// function to calculate the 2D DCT of a block
void dct(int (*block)[BLOCK_SIZE], double (*dct_block)[BLOCK_SIZE])
{
    int x, y, u, v;
    double alpha_u, alpha_v, sum;
    for (u = 0; u < BLOCK_SIZE; u++) {
        for (v = 0; v < BLOCK_SIZE; v++) {
            sum = 0;
            alpha_u = (u == 0) ? sqrt(1.0 / BLOCK_SIZE) : sqrt(2.0 / BLOCK_SIZE);
            alpha_v = (v == 0) ? sqrt(1.0 / BLOCK_SIZE) : sqrt(2.0 / BLOCK_SIZE);
            for (x = 0; x < BLOCK_SIZE; x++) {
                for (y = 0; y < BLOCK_SIZE; y++) {
                    sum += block[x][y] * cos((2 * x + 1) * u * M_PI / (2 * BLOCK_SIZE))
                           * cos((2 * y + 1) * v * M_PI / (2 * BLOCK_SIZE));
                }
            }
            dct_block[u][v] = alpha_u * alpha_v * sum;
        }
    }
}

// function to embed the watermark into the DCT coefficients
void embed_watermark(double (*dct_block)[BLOCK_SIZE], int watermark)
{
    int u = BLOCK_SIZE - 1;
    int v = BLOCK_SIZE - 1;
    dct_block[u][v] += ALPHA * watermark;
}

// function to extract the watermark from the DCT coefficients
int extract_watermark(double (*dct_block)[BLOCK_SIZE])
{
    int u = BLOCK_SIZE - 1;
    int v = BLOCK_SIZE - 1;
    double watermark_dct = dct_block[u][v];
    double threshold = ALPHA / 2.0;
    return (watermark_dct >= threshold) ? 1 : 0;
}

int main(void)
{
    int i, j;
    int input_block[BLOCK_SIZE][BLOCK_SIZE] = {
        {139, 144, 149, 153, 155, 155, 155, 155},
        {144, 151, 153, 156, 159, 156, 156, 156},
        {150, 155, 160, 163, 158, 156, 156, 156},
        {159, 161, 162, 160, 160, 159, 159, 159},
        {159, 160, 161, 162, 162, 155, 155, 155},
        {161, 161, 161, 161, 160, 157, 157, 157},
        {162, 162, 161, 163, 162, 157, 157, 157},
        {162, 162, 161, 161, 163, 158, 158, 158}
    };
    double dct_block[BLOCK_SIZE][BLOCK_SIZE];
    int watermark = 1;
    int extracted_watermark;

    // calculate the 2D DCT of the input block
    dct(input_block, dct_block);

    // embed the watermark into the DCT coefficients
    embed_watermark(dct_block, watermark);

    // extract the watermark from the DCT coefficients
    extracted_watermark = extract_watermark(dct_block);

    // print output
    printf("Input block:\n");
    for (i = 0; i < BLOCK_SIZE; i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            printf("%d ", input_block[i][j]);
        }
        printf("\n");
    }
    printf("\nDCT coefficients:\n");
    for (i = 0; i < BLOCK_SIZE; i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            printf("%lf ", dct_block[i][j]);
        }
        printf("\n");
    }
    printf("\nEmbedded watermark: %d\n", watermark);
    printf("Extracted watermark: %d\n", extracted_watermark);

    return 0;
}