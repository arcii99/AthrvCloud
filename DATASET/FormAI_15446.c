//FormAI DATASET v1.0 Category: Image Classification system ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the image matrix size
    int ROWS = 28;
    int COLS = 28;

    // Define the number of filters
    int NUM_FILTERS = 16;

    // Define the filter matrix size
    int FILTER_ROWS = 5;
    int FILTER_COLS = 5;

    // Create the input image matrix
    float input_image[ROWS][COLS];

    // Initialize the input image matrix with random values between 0 and 1
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            input_image[i][j] = (float)rand() / RAND_MAX;
        }
    }

    // Create the filter matrix
    float filters[NUM_FILTERS][FILTER_ROWS][FILTER_COLS];

    // Initialize the filter matrix with random values between -1 and 1
    for (int f = 0; f < NUM_FILTERS; f++) {
        for (int i = 0; i < FILTER_ROWS; i++) {
            for (int j = 0; j < FILTER_COLS; j++) {
                filters[f][i][j] = (((float)rand() / RAND_MAX) - 0.5) * 2.0;
            }
        }
    }

    // Define the stride and padding values
    int STRIDE = 1;
    int PADDING = 0;

    // Define the output matrix size
    int OUT_ROWS = (ROWS - FILTER_ROWS + 2 * PADDING) / STRIDE + 1;
    int OUT_COLS = (COLS - FILTER_COLS + 2 * PADDING) / STRIDE + 1;

    // Create the output matrix
    float output[OUT_ROWS][OUT_COLS][NUM_FILTERS];

    // Apply the convolution operation to the input image using the filters
    for (int f = 0; f < NUM_FILTERS; f++) {
        for (int i = 0; i < OUT_ROWS; i++) {
            for (int j = 0; j < OUT_COLS; j++) {
                float sum = 0;
                for (int k = 0; k < FILTER_ROWS; k++) {
                    for (int l = 0; l < FILTER_COLS; l++) {
                        int row_index = i * STRIDE + k - PADDING;
                        int col_index = j * STRIDE + l - PADDING;
                        if (row_index < 0 || row_index >= ROWS || col_index < 0 || col_index >= COLS) {
                            sum += 0;
                        } else {
                            sum += input_image[row_index][col_index] * filters[f][k][l];
                        }
                    }
                }
                output[i][j][f] = sum;
            }
        }
    }

    // Print out the output matrix
    for (int f = 0; f < NUM_FILTERS; f++) {
        printf("Filter %d:\n", f);
        for (int i = 0; i < OUT_ROWS; i++) {
            for (int j = 0; j < OUT_COLS; j++) {
                printf("%.2f ", output[i][j][f]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}