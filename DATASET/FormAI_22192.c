//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: accurate
#include <stdio.h>

// Function to generate the Fibonacci sequence up to a given number of terms.
void generateFibonacci(int num_terms) {
    int first_num = 0, second_num = 1, sum;

    printf("%d %d ", first_num, second_num);

    for (int i = 2; i < num_terms; i++) {
        sum = first_num + second_num;
        printf("%d ", sum);
        first_num = second_num;
        second_num = sum;
    }

    printf("\n");
}

// Function to print out the Fibonacci sequence as a visual pattern.
void visualizeFibonacci(int num_terms) {
    int first_num = 0, second_num = 1, sum = 0;
    int curr_row = 1, curr_col = 1, direction = 1;
    int matrix[num_terms][num_terms];

    // Initialize the matrix to all zeros.
    for (int i = 0; i < num_terms; i++) {
        for (int j = 0; j < num_terms; j++) {
            matrix[i][j] = 0;
        }
    }

    // Place the first two Fibonacci numbers in the matrix.
    matrix[0][0] = first_num;
    matrix[0][1] = second_num;

    for (int i = 2; i < num_terms; i++) {
        sum = first_num + second_num;
        matrix[curr_row][curr_col] = sum;

        // Move to the next row or column depending on the direction.
        if (direction == 1) {
            curr_col += 1;

            // Check if we need to change direction.
            if (matrix[curr_row - 1][curr_col] != 0) {
                direction = 2;
                curr_row += 1;
            }
        } else if (direction == 2) {
            curr_row += 1;

            // Check if we need to change direction.
            if (matrix[curr_row][curr_col - 1] != 0) {
                direction = 3;
                curr_col -= 1;
            }
        } else if (direction == 3) {
            curr_col -= 1;

            // Check if we need to change direction.
            if (matrix[curr_row - 1][curr_col] != 0) {
                direction = 4;
                curr_row -= 1;
            }
        } else if (direction == 4) {
            curr_row -= 1;

            // Check if we need to change direction.
            if (matrix[curr_row][curr_col + 1] != 0) {
                direction = 1;
                curr_col += 1;
            }
        }

        first_num = second_num;
        second_num = sum;
    }

    // Print out the matrix with visual formatting.
    for (int i = 0; i < num_terms; i++) {
        for (int j = 0; j < num_terms; j++) {
            if (matrix[i][j] != 0) {
                printf("%-3d", matrix[i][j]);
            } else {
                printf("   ");
            }
        }

        printf("\n");
    }
}

int main() {
    int num_terms;

    // Get user input for the number of terms to generate.
    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &num_terms);

    // Generate the Fibonacci sequence and print it out.
    generateFibonacci(num_terms);

    // Print out the Fibonacci sequence as a visual pattern.
    printf("\nFibonacci sequence as a visual pattern:\n");
    visualizeFibonacci(num_terms);

    return 0;
}