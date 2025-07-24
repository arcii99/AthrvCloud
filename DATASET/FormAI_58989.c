//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: peaceful
#include<stdio.h>

// Function to evaluate the given circuit
void evaluateCircuit(int A, int B, int C) {
    int output;

    if(A == 1 && B == 1 && C == 1) {
        output = 1;
    } else if(A == 1 && B == 1 && C == 0) {
        output = 0;
    } else if(A == 1 && B == 0 && C == 1) {
        output = 0;
    } else if(A == 1 && B == 0 && C == 0) {
        output = 1;
    } else if(A == 0 && B == 1 && C == 1) {
        output = 0;
    } else if(A == 0 && B == 1 && C == 0) {
        output = 1;
    } else if(A == 0 && B == 0 && C == 1) {
        output = 1;
    } else {
        output = 0;
    }

    printf("Output for input combination (%d, %d, %d) : %d\n", A, B, C, output);
}

int main() {
    printf("Welcome to Classical Circuit Simulator!\n");
    printf("This program evaluates the output of a classical circuit for different input combinations.\n");

    // Loop through all 8 input combinations
    for(int i=0; i<8; i++) {
        int A = (i / 4) % 2;
        int B = (i / 2) % 2;
        int C = i % 2;

        evaluateCircuit(A, B, C);
    }

    printf("Thanks for using Classical Circuit Simulator!\n");
    return 0;
}