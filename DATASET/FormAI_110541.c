//FormAI DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char name[10];
    int age;

    printf("Enter your name: ");
    fgets(name, 10, stdin);

    // Check if name contains only alphabetical characters
    for (int i = 0; i < 10; i++) {
        if (!isalpha(name[i])) {
            fprintf(stderr, "Error: Name can only contain alphabetical characters.\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) {
        fprintf(stderr, "Error: Invalid input for age.\n");
        exit(EXIT_FAILURE);
    }

    // Check if age is within valid range
    if (age < 0 || age > 120) {
        fprintf(stderr, "Error: Age must be between 0 and 120.\n");
        exit(EXIT_FAILURE);
    }

    printf("Hello, %s! You are %d years old.\n", name, age);

    return 0;
}