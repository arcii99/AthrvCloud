//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: curious
#include <stdlib.h>
#include <stdio.h>

/* Curious Simulator */
int curiousSimulator(int input) {
    int output = 0;
    int circuits[10] = {1, 0, 1, 1, 0, 1, 0, 1, 0, 1};
    
    // Curious circuit logic
    for (int i = 0; i < 10; i++) {
        if (input == circuits[i]) {
            output = circuits[i-1];
            break;
        }
    }
    
    return output;
}

int main() {
    // Test cases
    int testCases[4][2] = {{0, 1}, {1, 0}, {1, 1}, {0, 0}};
    
    printf("Curious Circuit Simulator\n");
    
    for (int i = 0; i < 4; i++) {
        int input = testCases[i][0];
        int expectedOutput = testCases[i][1];
        
        int output = curiousSimulator(input);
        
        printf("Input: %d, Expected Output: %d, Output: %d\n", input, expectedOutput, output);
        
        if (output != expectedOutput) {
            printf("Test case failed!\n");
            return 1;
        }
    }
    
    printf("All test cases passed.\n");
    
    return 0;
}