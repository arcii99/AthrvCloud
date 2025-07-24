//FormAI DATASET v1.0 Category: Matrix operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 3

int matrix[MATRIX_SIZE][MATRIX_SIZE];

void initialize_matrix();
void print_matrix();
void print_operation(char *operation);
void paranoid_operation();

int main() {
    initialize_matrix();
    print_matrix();
    paranoid_operation();
    return 0;
}

void initialize_matrix() {
    srand(time(0));
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void print_matrix() {
    printf("Original Matrix: \n");
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_operation(char *operation) {
    printf("\nParanoid about %s operation...\n", operation);
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", rand() % 10);
        }
        printf("\n");
    }
}

void paranoid_operation() {
    print_operation("addition");
    int paranoid_matrix[MATRIX_SIZE][MATRIX_SIZE];
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            paranoid_matrix[i][j] = rand() % 10;
        }
    }
    printf("\nParanoid Matrix: \n");
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", paranoid_matrix[i][j]);
        }
        printf("\n");
    }
    print_operation("subtraction");
    print_operation("multiplication");
    print_operation("division");
}