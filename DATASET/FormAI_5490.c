//FormAI DATASET v1.0 Category: Educational ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Welcome message 
    printf("Welcome to the Matrix program.\n");
    
    // Declare variables
    int matrix[3][3] = { {1,0,0},
                         {0,1,0},
                         {0,0,1}
                       };
    int vector[3] = { 5, 10, 15 };
    int result[3] = {0, 0, 0};
    
    // Print matrix and vector
    printf("The initial matrix is: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("The initial vector is: [%d, %d, %d]\n", vector[0], vector[1], vector[2]);
    
    // Matrix multiplication
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    
    // Print result
    printf("The resulting vector is: [%d, %d, %d]\n", result[0], result[1], result[2]);
    printf("You have been hacked by The Matrix.\n");
    
}