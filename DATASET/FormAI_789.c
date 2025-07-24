//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: scientific
#include <stdio.h>
#include <math.h>

// Function to calculate the discrete cosine transform (DCT)
void dct(int pixel[8][8], float dctMatrix[8][8])
{
    int i, j, x, y;
    float ci, cj, dctVal;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            // Initialize the DCT matrix value
            dctMatrix[i][j] = 0;
            
            // Compute ci and cj
            ci = (i == 0) ? 1 / sqrt(2) : 1;
            cj = (j == 0) ? 1 / sqrt(2) : 1;

            // Compute the DCT value at (i, j)
            for (x = 0; x < 8; x++) {
                for (y = 0; y < 8; y++) {
                    dctVal = pixel[x][y] * cos((2 * x + 1) * i * M_PI / 16) *
                             cos((2 * y + 1) * j * M_PI / 16);
                    dctMatrix[i][j] += dctVal;
                }
            }
            dctMatrix[i][j] *= (1.0 / 4) * ci * cj;
        }
    }
}

// Function to insert watermark data into DCT coefficients
void embedWatermark(float dctMatrix[8][8], char* watermark)
{
    int i, j, idx, bit;
    
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (i == 0 && j == 0) {
                // Skip the first coefficient
                continue;
            }
            idx = (8 * i + j - 1) % 64;
            bit = ((watermark[idx / 8] >> (7 - idx % 8)) & 1) ? 1 : -1;
            dctMatrix[i][j] *= 1 + bit * 0.1; // Increase or decrease coefficient value
        }
    }
}

// Function to extract watermark data from DCT coefficients
void extractWatermark(float dctMatrix[8][8], char* watermark)
{
    int i, j, idx, bit;
    
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (i == 0 && j == 0) {
                // Skip the first coefficient
                continue;
            }
            idx = (8 * i + j - 1) % 64;
            bit = (dctMatrix[i][j] > dctMatrix[0][0]) ? 1 : 0;
            watermark[idx / 8] |= bit << (7 - idx % 8); // Set the corresponding watermark bit
        }
    }
}

int main()
{
    // Input pixel block
    int pixel[8][8] = {{27,21,21,22,26,30,38,49},
                       {24,21,20,20,23,27,34,44},
                       {25,21,19,19,22,25,31,40},
                       {26,22,20,20,23,26,32,41},
                       {26,22,21,21,24,28,35,44},
                       {28,24,22,22,25,29,37,47},
                       {31,27,23,24,28,33,41,51},
                       {36,31,27,28,32,38,47,59}};

    // Define DCT matrix and perform DCT
    float dctMatrix[8][8];
    dct(pixel, dctMatrix);

    // Embed watermark data into DCT coefficients
    char* watermark = "Hello, world!";
    embedWatermark(dctMatrix, watermark);

    // Extract watermark data from DCT coefficients
    char extracted[2] = {0};
    extractWatermark(dctMatrix, extracted);

    // Print the original watermark and the extracted one
    printf("Original watermark: %s\n", watermark);
    printf("Extracted watermark: %s\n", extracted);

    return 0;
}