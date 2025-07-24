//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: romantic
#include <stdio.h>

int main() {
    int input1, input2, output;
    printf("Enter logic inputs: ");
    scanf("%d %d", &input1, &input2);
    output = input1 & input2; // AND Gate
    printf("Output is: %d\n", output);
    return 0;
}