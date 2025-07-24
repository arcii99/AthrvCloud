//FormAI DATASET v1.0 Category: Error handling ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10

void handleError(const char* message, int errorCode);

int main() {
    int arr[MAX_SIZE];
    int i;
    char input[MAX_SIZE];

    printf("Enter %d values separated by space: ", MAX_SIZE);

    if (fgets(input, sizeof(input), stdin) == NULL) {
        handleError("Error reading input.", 1);
    }

    char *ptr = strtok(input, " ");
    for (i = 0; i < MAX_SIZE; i++) {
        if (ptr == NULL) {
            handleError("Not enough input provided.", 2);
        }
        arr[i] = atoi(ptr);
        ptr = strtok(NULL, " ");
    }

    int sum = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        if (arr[i] < 0 || arr[i] > 100) {
            handleError("Invalid input provided.", 3);
        }
        sum += arr[i];
    }

    printf("The sum of provided inputs is: %d\n", sum);

    return 0;
}

void handleError(const char* message, int errorCode) {
    printf("\033[1m\033[31m[ERROR]\033[0m %s\n", message);
    exit(errorCode);
}