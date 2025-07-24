//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include <stdio.h>

#define MAX_CIRCUIT_SIZE 10

int simulate(int circuit[MAX_CIRCUIT_SIZE], int input) {
    if (circuit[0] == -1) {
        return input;
    } else if (circuit[0] == 0) {
        return simulate(&circuit[1], input);
    } else if (circuit[0] == 1) {
        return simulate(&circuit[1], !input);
    } else if (circuit[0] == 2) {
        int result1 = simulate(&circuit[1], input);
        int result2 = simulate(&circuit[result1 + 1], input);
        return simulate(&circuit[result1 + result2 + 2], result1 && result2);
    } else if (circuit[0] == 3) {
        int result1 = simulate(&circuit[1], input);
        int result2 = simulate(&circuit[result1 + 1], input);
        return simulate(&circuit[result1 + result2 + 2], result1 || result2);
    } else {
        printf("Invalid circuit code: %d\n", circuit[0]);
        return -1;
    }
}

int main() {
    int circuit[MAX_CIRCUIT_SIZE] = {2, 0, 3, -1, 2, 0, 1, -1, 2, 1, 1, -1};
    int input = 1;
    int result = simulate(circuit, input);
    printf("Input: %d\nOutput: %d\n", input, result);
    return 0;
}