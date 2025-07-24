//FormAI DATASET v1.0 Category: Image compression ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){

    // Input the image data
    int image[4][4] = {{12, 14, 10, 12},
                       {9, 20, 22, 12},
                       {8, 11, 12, 16},
                       {11, 12, 15, 19}};

    // Define variables
    int rows = 4, cols = 4;
    int block_rows = 2, block_cols = 2;
    int block_size = block_rows * block_cols;
    int num_blocks = (rows / block_rows) * (cols / block_cols);
    int blocks[num_blocks][block_size];
    int compressed[num_blocks][block_size];
    int uncompressed[num_blocks][block_size];
    int i, j, k, l, m, n;

    // Divide image into non-overlapping blocks
    int block_count = 0;
    for(i = 0; i < rows; i += block_rows){
        for(j = 0; j < cols; j += block_cols){
            for(k = 0; k < block_rows; k++){
                for(l = 0; l < block_cols; l++){
                    blocks[block_count][k * block_cols + l] = image[i+k][j+l];
                }
            }
            block_count++;
        }
    }

    // Perform DCT on each block
    for(i = 0; i < num_blocks; i++){
        double c_u, c_v;
        for(k = 0; k < block_rows; k++){
            for(l = 0; l < block_cols; l++){
                double sum = 0;
                for(m = 0; m < block_rows; m++){
                    for(n = 0; n < block_cols; n++){
                        c_u = (k == 0) ? 1 / sqrt(2) : 1;
                        c_v = (l == 0) ? 1 / sqrt(2) : 1;
                        sum += c_u * c_v * blocks[i][m * block_cols + n] * cos( ((2 * m + 1) * k * M_PI) / (2 * block_rows) ) * cos( ((2 * n + 1) * l * M_PI) / (2 * block_cols) );
                    }
                }
                compressed[i][k * block_cols + l] = (int) round(sum / block_size);
            }
        }
    }

    // Perform IDCT on each block
    for(i = 0; i < num_blocks; i++){
        double c_u, c_v;
        for(k = 0; k < block_rows; k++){
            for(l = 0; l < block_cols; l++){
                double sum = 0;
                for(m = 0; m < block_rows; m++){
                    for(n = 0; n < block_cols; n++){
                        c_u = (k == 0) ? 1 / sqrt(2) : 1;
                        c_v = (l == 0) ? 1 / sqrt(2) : 1;
                        sum += c_u * c_v * compressed[i][m * block_cols + n] * cos( ((2 * k + 1) * m * M_PI) / (2 * block_rows) ) * cos( ((2 * l + 1) * n * M_PI) / (2 * block_cols) );
                    }
                }
                uncompressed[i][k * block_cols + l] = (int) round(sum);
            }
        }
    }

    // Print original image
    printf("Original Image:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Print compressed image
    printf("Compressed Image:\n");
    block_count = 0;
    for(i = 0; i < rows; i += block_rows){
        for(j = 0; j < cols; j += block_cols){
            for(k = 0; k < block_rows; k++){
                for(l = 0; l < block_cols; l++){
                    printf("%d ", compressed[block_count][k * block_cols + l]);
                }
                printf("\n");
            }
            block_count++;
        }
    }
    printf("\n");

    // Print uncompressed image
    printf("Uncompressed Image:\n");
    block_count = 0;
    for(i = 0; i < rows; i += block_rows){
        for(j = 0; j < cols; j += block_cols){
            for(k = 0; k < block_rows; k++){
                for(l = 0; l < block_cols; l++){
                    printf("%d ", uncompressed[block_count][k * block_cols + l]);
                }
                printf("\n");
            }
            block_count++;
        }
    }

    return 0;
}