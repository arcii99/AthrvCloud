//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: complete
#include <stdio.h>

// function to calculate the output of the circuit given the input values
int calculateOutput(int input1, int input2) {
    int output;
    // boolean operation: AND
    output = input1 & input2;
    // boolean operation: NOT
    output = ~output;
    // return the output value
    return output;
}

int main() {
    int input1, input2, output;

    // prompt the user for the input values
    printf("Enter the value of input 1 (0 or 1): ");
    scanf("%d", &input1);
    printf("Enter the value of input 2 (0 or 1): ");
    scanf("%d", &input2);

    // calculate the output of the circuit
    output = calculateOutput(input1, input2);

    // display the output of the circuit
    printf("The output of the circuit for inputs %d and %d is %d\n", input1, input2, output);

    return 0;
}