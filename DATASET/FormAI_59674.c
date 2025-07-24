//FormAI DATASET v1.0 Category: Bitwise operations ; Style: distributed
#include <stdio.h>

// Function to perform bitwise OR operation
void bitwiseOR(int data[], int n) {
    int result = data[0];

    for (int i = 1; i < n; i++) {
        result |= data[i];
    }

    printf("Bitwise OR result: %d\n", result);
}

// Function to perform bitwise AND operation
void bitwiseAND(int data[], int n) {
    int result = data[0];

    for (int i = 1; i < n; i++) {
        result &= data[i];
    }

    printf("Bitwise AND result: %d\n", result);
}

// Function to perform bitwise XOR operation
void bitwiseXOR(int data[], int n) {
    int result = data[0];

    for (int i = 1; i < n; i++) {
        result ^= data[i];
    }

    printf("Bitwise XOR result: %d\n", result);
}

int main() {
    int data[] = {8, 4, 12, 6, 2};
    int n = sizeof(data) / sizeof(data[0]);

    // Using 2 child processes to perform bitwise operations in parallel
    int pid1 = fork();

    if (pid1 == -1) {
        printf("Error creating 1st child process\n");
    } else if (pid1 == 0) {
        bitwiseOR(data, n); // Child process 1 performs bitwise OR operation
    } else {
        int pid2 = fork();

        if (pid2 == -1) {
            printf("Error creating 2nd child process\n");
        } else if (pid2 == 0) {
            bitwiseAND(data, n); // Child process 2 performs bitwise AND operation
        } else {
            bitwiseXOR(data, n); // Parent process performs bitwise XOR operation
            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}