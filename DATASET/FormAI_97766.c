//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FIB_NUM 50 // maximum number of fibonacci numbers to generate

// function to generate fibonacci numbers
void generate_fibonacci_sequence(int fib_sequence[]) {
    // initialize the first two numbers in the sequence
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;
    
    // generate the fibonacci numbers
    for (int i = 2; i < MAX_FIB_NUM; i++) {
        fib_sequence[i] = fib_sequence[i-1] + fib_sequence[i-2];
    }
}

// function to draw the fibonacci sequence
void draw_fibonacci_sequence(int fib_sequence[]) {
    for (int i = 0; i < MAX_FIB_NUM; i++) {
        // calculate the width of the fibonacci number
        int width = sprintf(NULL, "%d", fib_sequence[i]);
        
        // print the fibonacci number
        printf("%d", fib_sequence[i]);
        
        // add spaces to align the next number
        for (int j = 0; j < 6 - width; j++) {
            printf(" ");
        }
        
        // sleep for 100ms to create a visual delay
        usleep(100000);
    }
    
    printf("\n");
}

int main() {
    int fib_sequence[MAX_FIB_NUM];
    
    generate_fibonacci_sequence(fib_sequence);
    draw_fibonacci_sequence(fib_sequence);
    
    return 0;
}