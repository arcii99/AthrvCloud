//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to generate random integers within a given range
int randomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to clear the console screen
void clearScreen() {
    printf("\033[2J\033[H");
}

// Function to sleep for a given number of milliseconds
void sleepMilliseconds(int milliseconds) {
    usleep(milliseconds * 1000);
}

// Function to generate the fibonacci sequence up to a given number of terms
void generateFibonacciSequence(unsigned int terms) {
    unsigned long long int prevprev = 0, prev = 1, current;
    printf("%llu %llu ", prevprev, prev);
    for (unsigned int i = 2; i < terms; i++) {
        current = prevprev + prev;
        printf("%llu ", current);
        prevprev = prev;
        prev = current;
    }
}

// Function to visualize the fibonacci sequence using terminal ASCII art
void visualizeFibonacciSequence(unsigned int terms) {
    printf("Generating Fibonacci Sequence...\n");
    sleepMilliseconds(1000);
    clearScreen();
    generateFibonacciSequence(terms);
    printf("\n\n");

    // Define the character used to represent each step in the sequence
    char symbol = '*';

    // Define the number of spaces between each step in the sequence
    int spacing = 3;

    // Define the number of milliseconds to wait between each step in the sequence
    int delay = 100;

    printf("Visualizing Fibonacci Sequence...\n");
    sleepMilliseconds(1000);
    clearScreen();
    printf("\n");

    // Loop through each step in the sequence and visualize it
    unsigned long long int prevprev = 0, prev = 1, current;
    printf("%llu %c\n", prevprev, symbol);
    sleepMilliseconds(delay);
    printf("%llu %c\n", prev, symbol);
    sleepMilliseconds(delay);
    for (unsigned int i = 2; i < terms; i++) {
        current = prevprev + prev;
        for (unsigned int j = 0; j < current; j++) {
            printf(" ");
        }
        printf("%c\n", symbol);
        sleepMilliseconds(delay);
        prevprev = prev;
        prev = current;
    }
}

int main() {
    srand(time(NULL));
    unsigned int terms = randomInt(10, 20);
    visualizeFibonacciSequence(terms);
    return 0;
}