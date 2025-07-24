//FormAI DATASET v1.0 Category: Error handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* input = (char*) malloc(sizeof(char) * 10);

    printf("Enter a number: ");
    scanf("%s", input);
    int num = atoi(input);

    if (num == 0) {
        perror("Error: Invalid input. Please enter a number.");
        exit(1);
    } else {
        printf("Your number is: %d\n", num);
    }

    strncpy(input, "abcdefghij", 5);

    if (strlen(input) > 5) {
        fprintf(stderr, "Error: Input length must be less than or equal to 5.\n");
        exit(1);
    } else {
        printf("Your input is: %s\n", input);
    }

    char* ptr = NULL;
    ptr = (char*) malloc(sizeof(char) * 10);

    if (ptr == NULL) {
        perror("Error: Out of memory.");
        exit(1);
    } else {
        printf("Memory allocated successfully.\n");
    }

    free(input);
    free(ptr);

    return 0;
}