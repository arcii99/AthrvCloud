//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERMS 50

void clearScreen();
void printFibonacci(int* sequence, int numOfTerms);
void drawGraph(int* sequence, int numOfTerms);

int main() {
    int numOfTerms;
    int sequence[MAX_TERMS];

    printf("How many Fibonacci terms would you like to generate? (1-50): ");
    scanf("%d", &numOfTerms);

    // Generate Fibonacci sequence
    sequence[0] = 0;
    sequence[1] = 1;

    for(int i = 2; i < numOfTerms; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }

    clearScreen();

    // Print Fibonacci sequence
    printf("Generated Fibonacci Sequence:\n\n");
    printFibonacci(sequence, numOfTerms);

    printf("\n");

    // Draw graph of Fibonacci sequence
    drawGraph(sequence, numOfTerms);

    return 0;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printFibonacci(int* sequence, int numOfTerms) {
    for(int i = 0; i < numOfTerms; i++) {
        printf("%d ", sequence[i]);
    }
}

void drawGraph(int* sequence, int numOfTerms) {
    int barHeight;

    printf("Graph of Fibonacci Sequence:\n\n");

    for(int i = 0; i < numOfTerms; i++) {
        barHeight = sequence[i] / 10;
        printf("%2d | ", sequence[i]);

        for(int j = 0; j < barHeight; j++) {
            printf("*");
        }

        printf("\n");
    }
}