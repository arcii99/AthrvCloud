//FormAI DATASET v1.0 Category: Data validation ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char name[20];
    int age;
    float bp;
    bool is_valid = true;

    // Taking input from user
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your Blood Pressure: ");
    scanf("%f", &bp);

    // Validating user input
    if (strlen(name) < 2 || strlen(name) > 20) {
        is_valid = false;
        printf("Error: Name should be between 2 and 20 characters.\n");
    }

    if (age < 18 || age > 60) {
        is_valid = false;
        printf("Error: Age should be between 18 and 60.\n");
    }

    if (bp < 60 || bp > 140) {
        is_valid = false;
        printf("Error: Blood Pressure should be between 60 and 140.\n");
    }

    // Printing user input and validation status
    if (is_valid) {
        printf("Name: %s\n", name);
        printf("Age: %d\n", age);
        printf("Blood Pressure: %.2f\n", bp);
        printf("Data is valid!\n");
    }

    return 0;
}