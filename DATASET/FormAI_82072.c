//FormAI DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int age;

    printf("Enter your age:");
    if (scanf("%d", &age) != 1) {
        printf("Invalid age entered. Please enter a valid age.\n");
        exit(1);
    }

    if (age < 0 || age > 120) {
        printf("Invalid age entered. Please enter a valid age between 0 and 120.\n");
        exit(1);
    }

    printf("You are %d years old.\n", age);

    return 0;
}