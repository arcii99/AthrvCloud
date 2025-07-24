//FormAI DATASET v1.0 Category: Image compression ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLOCK_SIZE 8
#define IMAGE_SIZE 64

// Function to generate a random image
void generateRandomImage(int image[][IMAGE_SIZE]) {
    srand(42);
    for(int i=0; i<IMAGE_SIZE; i++) {
        for(int j=0; j<IMAGE_SIZE; j++) {
            image[i][j] = rand() % 256;
        }
    }
}

// Function to print the image
void printImage(int image[][IMAGE_SIZE]) {
    for(int i=0; i<IMAGE_SIZE; i++) {
        for(int j=0; j<IMAGE_SIZE; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

// Function to perform DCT on a block
void performDCT(int block[][BLOCK_SIZE], double dct[][BLOCK_SIZE]) {
    double c_u, c_v, sum;
    for(int u=0; u<BLOCK_SIZE; u++) {
        for(int v=0; v<BLOCK_SIZE; v++) {
            c_u = (u == 0) ? (1/sqrt(2)) : 1;
            c_v = (v == 0) ? (1/sqrt(2)) : 1;
            sum = 0;
            for(int i=0; i<BLOCK_SIZE; i++) {
                for(int j=0; j<BLOCK_SIZE; j++) {
                    sum += (block[i][j] * cos((2*i+1)*u*M_PI/16) * cos((2*j+1)*v*M_PI/16));
                }
            }
            dct[u][v] = 0.25 * c_u * c_v * sum;
        }
    }
}

// Function to perform quantization on a block
void performQuantization(double dct[][BLOCK_SIZE], int quantizationMatrix[][BLOCK_SIZE], int quantizedBlock[][BLOCK_SIZE]) {
    for(int i=0; i<BLOCK_SIZE; i++) {
        for(int j=0; j<BLOCK_SIZE; j++) {
            quantizedBlock[i][j] = round(dct[i][j] / quantizationMatrix[i][j]);
        }
    }
}

// Function to perform dequantization on a block
void performDequantization(int quantizedBlock[][BLOCK_SIZE], int quantizationMatrix[][BLOCK_SIZE], double dct[][BLOCK_SIZE]) {
    for(int i=0; i<BLOCK_SIZE; i++) {
        for(int j=0; j<BLOCK_SIZE; j++) {
            dct[i][j] = quantizedBlock[i][j] * quantizationMatrix[i][j];
        }
    }
}

// Function to perform inverse DCT on a block
void performIDCT(double dct[][BLOCK_SIZE], int block[][BLOCK_SIZE]) {
    double c_u, c_v, sum;
    for(int i=0; i<BLOCK_SIZE; i++) {
        for(int j=0; j<BLOCK_SIZE; j++) {
            sum = 0;
            for(int u=0; u<BLOCK_SIZE; u++) {
                for(int v=0; v<BLOCK_SIZE; v++) {
                    c_u = (u == 0) ? (1/sqrt(2)) : 1;
                    c_v = (v == 0) ? (1/sqrt(2)) : 1;
                    sum += (c_u * c_v * dct[u][v] * cos((2*i+1)*u*M_PI/16) * cos((2*j+1)*v*M_PI/16));
                }
            }
            block[i][j] = round(0.25 * sum);
        }
    }
}

// Function to compress an image using JPEG compression
void compressImage(int image[][IMAGE_SIZE], int compressedImage[][IMAGE_SIZE], int quantizationMatrix[][BLOCK_SIZE]) {
    // Compress image by dividing it into blocks of size 8x8 and performing DCT, quantization and zigzag scan
    int N = IMAGE_SIZE / BLOCK_SIZE;
    double dct[BLOCK_SIZE][BLOCK_SIZE];
    int quantizedBlock[BLOCK_SIZE][BLOCK_SIZE];
    int zigzagBlock[BLOCK_SIZE*BLOCK_SIZE];
    int row, col;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            // Dividing the image into blocks of size 8x8
            int block[BLOCK_SIZE][BLOCK_SIZE];
            for(int p=0; p<BLOCK_SIZE; p++) {
                for(int q=0; q<BLOCK_SIZE; q++) {
                    row = i*BLOCK_SIZE + p;
                    col = j*BLOCK_SIZE + q;
                    block[p][q] = image[row][col];
                }
            }
            // Performing DCT on the block
            performDCT(block, dct);
            // Performing quantization on the block
            performQuantization(dct, quantizationMatrix, quantizedBlock);
            // Performing zigzag scan on the quantized block
            int k = 0;
            for(int p=0; p<BLOCK_SIZE; p++) {
                if(p%2 == 0) {
                    for(int q=0; q<=p; q++) {
                        zigzagBlock[k++] = quantizedBlock[q][p-q];
                    }
                } else {
                    for(int q=p; q>=0; q--) {
                        zigzagBlock[k++] = quantizedBlock[q][p-q];
                    }
                }
            }
            for(int p=BLOCK_SIZE-2; p>=0; p--) {
                if(p%2 == 0) {
                    for(int q=p; q>=0; q--) {
                        zigzagBlock[k++] = quantizedBlock[p-q][q];
                    }
                } else {
                    for(int q=0; q<=p; q++) {
                        zigzagBlock[k++] = quantizedBlock[p-q][q];
                    }
                }
            }
            // Saving the compressed block in the compressed image
            k = 0;
            for(int p=0; p<BLOCK_SIZE; p++) {
                for(int q=0; q<BLOCK_SIZE; q++) {
                    compressedImage[i*BLOCK_SIZE+p][j*BLOCK_SIZE+q] = zigzagBlock[k++];
                }
            }
        }
    }
}

// Function to decompress a compressed image using JPEG compression
void decompressImage(int compressedImage[][IMAGE_SIZE], int decompressedImage[][IMAGE_SIZE], int quantizationMatrix[][BLOCK_SIZE]) {
    // Decompress image by performing inverse zigzag, dequantization and inverse DCT
    int N = IMAGE_SIZE / BLOCK_SIZE;
    double dct[BLOCK_SIZE][BLOCK_SIZE];
    int quantizedBlock[BLOCK_SIZE][BLOCK_SIZE];
    int zigzagBlock[BLOCK_SIZE*BLOCK_SIZE];
    int row, col;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            // Dividing the compressed image into blocks of size 8x8
            for(int p=0; p<BLOCK_SIZE; p++) {
                for(int q=0; q<BLOCK_SIZE; q++) {
                    zigzagBlock[p*BLOCK_SIZE+q] = compressedImage[i*BLOCK_SIZE+p][j*BLOCK_SIZE+q];
                }
            }
            // Performing inverse zigzag scan on the compressed block
            int k = 0;
            int p = 0, q = 0;
            while(p != BLOCK_SIZE-1 || q != BLOCK_SIZE-1) {
                quantizedBlock[p][q] = zigzagBlock[k++];
                if(p == 0 && q%2 == 0) {
                    q++;
                } else if(q == 0 && p%2 == 1) {
                    p++;
                } else if((p+q)%2 == 0) {
                    p--; q++;
                } else {
                    p++; q--;
                }
            }
            quantizedBlock[p][q] = zigzagBlock[k++];
            // Performing dequantization on the block
            performDequantization(quantizedBlock, quantizationMatrix, dct);
            // Performing inverse DCT on the block
            int block[BLOCK_SIZE][BLOCK_SIZE];
            performIDCT(dct, block);
            // Saving the decompressed block in the decompressed image
            for(int p=0; p<BLOCK_SIZE; p++) {
                for(int q=0; q<BLOCK_SIZE; q++) {
                    row = i*BLOCK_SIZE + p;
                    col = j*BLOCK_SIZE + q;
                    decompressedImage[row][col] = block[p][q];
                }
            }
        }
    }
}

int main() {
    // Example program to compress an image using JPEG compression
    int image[IMAGE_SIZE][IMAGE_SIZE];
    generateRandomImage(image);
    printf("Original Image:\n");
    printImage(image);
    int compressedImage[IMAGE_SIZE][IMAGE_SIZE];
    int decompressedImage[IMAGE_SIZE][IMAGE_SIZE];
    // Using standard 8x8 quantization matrix for luminance component
    int quantizationMatrix[BLOCK_SIZE][BLOCK_SIZE] = {{16, 11, 10, 16, 24, 40, 51, 61},
                                                      {12, 12, 14, 19, 26, 58, 60, 55},
                                                      {14, 13, 16, 24, 40, 57, 69, 56},
                                                      {14, 17, 22, 29, 51, 87, 80, 62},
                                                      {18, 22, 37, 56, 68, 109, 103, 77},
                                                      {24, 35, 55, 64, 81, 104, 113, 92},
                                                      {49, 64, 78, 87, 103, 121, 120, 101},
                                                      {72, 92, 95, 98, 112, 100, 103, 99}};
    compressImage(image, compressedImage, quantizationMatrix);
    printf("Compressed Image:\n");
    printImage(compressedImage);
    decompressImage(compressedImage, decompressedImage, quantizationMatrix);
    printf("Decompressed Image:\n");
    printImage(decompressedImage);
    return 0;
}