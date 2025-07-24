//FormAI DATASET v1.0 Category: Image compression ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 8 // Block width
#define HEIGHT 8 // Block height
#define QUALITY 50 // Image quality, higher means better quality

// Image data (8x8 blocks)
int image[HEIGHT][WIDTH] = {
    {120, 120, 120, 120, 120, 120, 120, 120},
    {120, 120, 120, 120, 120, 120, 120, 120},
    {120, 120, 120, 120, 120, 120, 120, 120},
    {120, 120, 120, 120, 120, 120, 120, 120},
    {120, 120, 120, 120, 120, 120, 120, 120},
    {120, 120, 120, 120, 120, 120, 120, 120},
    {120, 120, 120, 120, 120, 120, 120, 120},
    {120, 120, 120, 120, 120, 120, 120, 120}
};

// Zigzag scan pattern
int zigzag[HEIGHT * WIDTH][2] = {
    {0, 0},
    {0, 1}, {1, 0},
    {2, 0}, {1, 1}, {0, 2},
    {0, 3}, {1, 2}, {2, 1}, {3, 0},
    {4, 0}, {3, 1}, {2, 2}, {1, 3}, {0, 4},
    {0, 5}, {1, 4}, {2, 3}, {3, 2}, {4, 1}, {5, 0},
    {6, 0}, {5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5}, {0, 6},
    {0, 7}, {1, 6}, {2, 5}, {3, 4}, {4, 3}, {5, 2}, {6, 1}, {7, 0},
    {7, 1}, {6, 2}, {5, 3}, {4, 4}, {3, 5}, {2, 6}, {1, 7},
    {2, 7}, {3, 6}, {4, 5}, {5, 4}, {6, 3}, {7, 2},
    {7, 3}, {6, 4}, {5, 5}, {4, 6}, {3, 7},
    {4, 7}, {5, 6}, {6, 5}, {7, 4},
    {7, 5}, {6, 6}, {5, 7},
    {6, 7}, {7, 6},
    {7, 7}
};

// Quantization table
int quant_table[HEIGHT][WIDTH] = {
    {16,  11,  10,  16,  24,  40,  51,  61 },
    {12,  12,  14,  19,  26,  58,  60,  55 },
    {14,  13,  16,  24,  40,  57,  69,  56 },
    {14,  17,  22,  29,  51,  87,  80,  62 },
    {18,  22,  37,  56,  68, 109, 103,  77 },
    {24,  35,  55,  64,  81, 104, 113,  92 },
    {49,  64,  78,  87, 103, 121, 120, 101 },
    {72,  92,  95,  98, 112, 100, 103,  99 }
};

// Print block data
void print_block(int block[HEIGHT][WIDTH]) {
    printf("Block: \n");
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%d ", block[i][j]);
        }
        printf("\n");
    }
}

// Quantize block data
void quantize(int block[HEIGHT][WIDTH]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            block[i][j] /= quant_table[i][j] / (QUALITY/50.0); // Quality factor adjustment
            block[i][j] = round(block[i][j]); // Round to nearest integer
        }
    }
}

// Encode block data using run-length encoding
void encode(int block[HEIGHT][WIDTH], int *encoded_data, int *encoded_length) {
    int count = 0; // Counts number of zeroes
    int nz_count = 0; // Counts number of non-zeroes
    for(int i = 0; i < HEIGHT * WIDTH; i++) {
        int x = zigzag[i][0];
        int y = zigzag[i][1];
        
        if(block[y][x] == 0) {
            count++;
        } else {
            encoded_data[*encoded_length] = count;
            (*encoded_length)++;
            encoded_data[*encoded_length] = block[y][x];
            (*encoded_length)++;
            count = 0;
            nz_count++;
        }
    }
    if(count > 0) { // Add trailing zeroes
        encoded_data[*encoded_length] = count;
        (*encoded_length)++;
    }
}

// Compress image using JPEG compression algorithm
unsigned char *compress(int image[HEIGHT][WIDTH]) {
    // Allocate memory for compressed data
    int max_compressed_size = HEIGHT * WIDTH * sizeof(int);
    unsigned char *compressed_data = (unsigned char *)malloc(max_compressed_size);
    
    int compressed_length = 0; // Length of compressed data
    
    // Loop through all 8x8 blocks in the image
    for(int i = 0; i < HEIGHT; i += HEIGHT) {
        for(int j = 0; j < WIDTH; j += WIDTH) {
            int block[HEIGHT][WIDTH];
            
            // Copy block data
            for(int x = 0; x < WIDTH; x++) {
                for(int y = 0; y < HEIGHT; y++) {
                    block[y][x] = image[i + y][j + x];
                }
            }
            
            print_block(block);
            
            // Subtract 128 from each data point
            for(int x = 0; x < WIDTH; x++) {
                for(int y = 0; y < HEIGHT; y++) {
                    block[y][x] -= 128;
                }
            }
            
            quantize(block);
            
            int encoded_data[HEIGHT * WIDTH * 2];
            int encoded_length = 0;
            
            encode(block, encoded_data, &encoded_length);
            
            // Store encoded block length
            compressed_data[compressed_length++] = encoded_length & 0xff;
            compressed_data[compressed_length++] = (encoded_length >> 8) & 0xff;
            
            // Store encoded block data
            for(int k = 0; k < encoded_length; k++) {
                compressed_data[compressed_length++] = encoded_data[k] & 0xff;
            }
        }
    }
    
    return compressed_data;
}

int main() {
    unsigned char *compressed_data = compress(image);
    printf("Compressed data: ");
    for(int i = 0; i < 100; i++) {
        printf("%02x ", compressed_data[i]);
    }
    printf("...\n");
    free(compressed_data);
    return 0;
}