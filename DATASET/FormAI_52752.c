//FormAI DATASET v1.0 Category: Data validation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    char input[100];
    int age;
    bool valid = false;

    printf("Please enter your age: ");
    fgets(input, 100, stdin);

    // Remove trailing newline
    input[strcspn(input, "\n")] = 0;

    // Check if input is a number
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            printf("Error: Please enter a valid number.\n");
            return 1;
        }
    }

    // Convert input to integer
    age = atoi(input);

    // Validate age
    if (age < 18 || age > 99) {
        printf("Error: Please enter an age between 18 and 99.\n");
        return 1;
    }

    printf("Thank you for entering a valid age.\n");
    valid = true;

    // Do something with the valid input...
    
    return 0;
}