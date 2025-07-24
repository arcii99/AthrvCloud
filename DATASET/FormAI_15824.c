//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void clearScreen() {
    printf("\033[H\033[J"); // clears the terminal screen
}

void fibonacci(int n) {
    long long int a = 0, b = 1, c;
    
    for(int i=0; i<n; i++) {
        printf("%lld%c", a, (i==n-1)?'\n':' ');
        c = a+b;
        a = b;
        b = c;
        usleep(250000); // Wait for 0.25 seconds or 250 ms
    }
}

int main(int argc, char* argv[]) {
    if(argc != 2) { // invalid arguments
        printf("Usage: ./fibonacci <count>");
        exit(1);
    }
    
    int n = atoi(argv[1]); // convert string to integer
        
    if(n <= 0) { // non-positive count
        printf("Invalid count: %d (Count must be greater than 0)\n", n);
        exit(1);
    }
    
    clearScreen();
    printf("\nFibonacci Sequence with %d terms:\n", n);
    printf("-----------------------------------------\n\n");
    fibonacci(n);
    
    return 0;
}