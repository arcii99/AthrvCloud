//FormAI DATASET v1.0 Category: Image Classification system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Initialize Input Data and Weights */

double input_data[3][3] = {{3.0, 2.0, 1.0},
                           {1.0, 2.0, 3.0},
                           {2.0, 1.0, 3.0}};

double weights[3][3] = {{0.1, 0.2, 0.3},
                        {0.2, 0.3, 0.4},
                        {0.3, 0.4, 0.5}};

/* Initialize Output Data */

double output_data[3] = {0.0};

/* Main function to classify the input data */

int main() { 
    int i, j, k;
    double sum;

    /* Compute output for each class */
    for(i=0; i<3; i++) {
        sum = 0.0;
        for(j=0; j<3; j++) {
            sum += input_data[i][j] * weights[i][j];
        }
        output_data[i] = 1.0 / (1.0 + exp(-sum));
    }

    /* Print the results */
    printf("Input Data:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("%1.1f ", input_data[i][j]);
        }
        printf("\n");
    }

    printf("Weights:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("%1.1f ", weights[i][j]);
        }
        printf("\n");
    }

    printf("Output Data:\n");
    for(i=0; i<3; i++) {
        printf("%1.4f ", output_data[i]);
    }
    printf("\n");

    return 0;
}