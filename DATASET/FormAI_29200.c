//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// function to print the matrix
void printMatrix(int M[][COLS])
{
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

// function to check if the number is prime
int isPrime(int num)
{
    if (num == 1 || num == 0) return 0; // 1 and 0 are not prime
    for(int i=2; i<=num/2; i++) {
        if(num%i == 0) return 0;
    }
    return 1;
}

int main()
{
    int matrix[ROWS][COLS];
    srand(time(NULL)); // seed random number generator

    // generate random numbers and fill the matrix
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int num = rand() % 100; // generates random number between 0 to 99
            matrix[i][j] = num;

            // check if the number is prime and print it in red
            if (isPrime(num)) {
                printf("\033[31m"); // sets color to red
                printf("%d ", num);
                printf("\033[0m"); // resets color
            }
            else {
                printf("%d ", num);
            }
        }
        printf("\n");
    }

    // print the matrix
    printf("Original matrix:\n");
    printMatrix(matrix);

    // flip the matrix horizontally
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS/2; j++) { // swap only half of the columns
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][COLS-j-1];
            matrix[i][COLS-j-1] = temp;
        }
    }

    // print the modified matrix
    printf("Modified matrix:\n");
    printMatrix(matrix);

    return 0;
}