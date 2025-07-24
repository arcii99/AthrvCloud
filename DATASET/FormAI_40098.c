//FormAI DATASET v1.0 Category: Data validation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_valid_age(int age); // Function prototype

int main(void) {
    int age; // Variable to hold the user's input
    
    printf("Please enter your age: ");
    scanf("%d", &age); // Read input from the user
    
    if (is_valid_age(age)) {
        printf("Your age is valid!");
    } else {
        printf("Your age is not valid.");
    }
    
    return 0;
}

bool is_valid_age(int age) {
    if (age >= 0 && age <= 150) { // Age must be within the range 0 to 150 (inclusive)
        return true; // Age is valid
    }
    
    return false; // Age is not valid
}