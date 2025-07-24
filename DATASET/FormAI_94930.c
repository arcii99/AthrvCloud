//FormAI DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

void ConvertToBinary(int decimal) {
    int binary[32], i;
    for (i = 0; decimal > 0; i++) {
        binary[i] = decimal % 2;
        decimal /= 2;
    }
    printf("\nConverted binary number is: ");
    for (i = i - 1; i >= 0; i--)
        printf("%d", binary[i]);
}

int main() {
    int decimal, processID, numProcesses;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    printf("Enter the number of processes to use: ");
    scanf("%d", &numProcesses);
    int interval = decimal / numProcesses;
    int status;
    pid_t p;
    for (int i = 0; i < numProcesses; i++) {
        p = fork();
        if (p == 0) { // Child process
            printf("\nChild process %d: PID=%d ", i+1, getpid());
            if (i == numProcesses - 1) { // Last child process
                printf("\nWorking on interval: %d - %d", i * interval, decimal);
                ConvertToBinary(decimal);
            }
            else {
                printf("\nWorking on interval: %d - %d", i * interval, (i+1)*interval - 1);
                ConvertToBinary(interval);
            }
            exit(0);
        }
    }
    // Parent process
    for (int i = 0; i < numProcesses; i++) {
        wait(&status);
    }
    printf("\nParent process: All child processes have completed execution.");
    return 0;
}