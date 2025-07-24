//FormAI DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LENGTH 32

void *binary_converter(void *arg);

int main(void) {
    char input[MAX_LENGTH];
    pthread_t tid;

    printf("Enter a decimal number: ");
    fgets(input, MAX_LENGTH, stdin);

    // Create thread to convert to binary
    if (pthread_create(&tid, NULL, binary_converter, input) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Wait for thread to finish
    if (pthread_join(tid, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void *binary_converter(void *arg) {
    int decimal = atoi((char *) arg);
    int remainder, binary = 0, base = 1;

    // Convert decimal to binary
    while (decimal > 0) {
        remainder = decimal % 2;
        binary += remainder * base;
        base *= 10;
        decimal /= 2;
    }

    printf("Binary conversion: %d\n", binary);

    pthread_exit(NULL);
}