//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 50

// This function generates the Fibonacci sequence and stores it in an array
void generate_fibonacci_sequence(int *sequence, int terms)
{
    int i;
    sequence[0] = 0;
    sequence[1] = 1;
    for (i = 2; i < terms; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
}

// This function prints the Fibonacci sequence as a visualizer
void print_fibonacci_visualizer(int *sequence, int terms)
{
    int i, j;
    for (i = 0; i < terms; i++) {
        for (j = 0; j < sequence[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int sequence[MAX_TERMS];
    int terms;

    printf("Enter the number of terms you want in the Fibonacci sequence (maximum 50): ");
    scanf("%d", &terms);
  
    if (terms < 1 || terms > MAX_TERMS) {
        printf("Invalid input, please enter a number between 1 and 50\n");
        return 1;
    }

    generate_fibonacci_sequence(sequence, terms);
    print_fibonacci_visualizer(sequence, terms);

    return 0;
}