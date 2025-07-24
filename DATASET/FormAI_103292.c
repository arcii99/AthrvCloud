//FormAI DATASET v1.0 Category: Data validation ; Style: statistical
/* 
Program: Data Validation in C
Author: Your Name
Description: Program to validate user input data
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

// Function to check if string is numeric or not
int isNumeric(char input[]) {
    int i = 0;
    while(input[i] != '\0') {
        if(!isdigit(input[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    // Declare Variables
    char input[MAX_INPUT_LENGTH];
    int age = 0;
    float salary = 0.00;
    int isValid = 0;

    // Ask user to input age
    printf("Enter your age: ");
    while(!isValid) {
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        // Check if age is numeric and within valid range
        if(isNumeric(input)) {
            age = atoi(input);
            if(age >= 18 && age <= 65) {
                isValid = 1;
            } else {
                printf("Age should be between 18 and 65. Please enter a valid age: ");
            }
        } else {
            printf("Age should be numeric. Please enter a valid age: ");
        }
    }

    // Reset isValid variable for salary input validation
    isValid = 0;

    // Ask user to input salary
    printf("Enter your salary: ");
    while(!isValid) {
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        // Check if salary is numeric and within valid range
        if(isNumeric(input)) {
            salary = atof(input);
            if(salary >= 0 && salary <= 99999.99) {
                isValid = 1;
            } else {
                printf("Salary should be between 0 and 99999.99. Please enter a valid salary: ");
            }
        } else {
            printf("Salary should be numeric. Please enter a valid salary: ");
        }
    }

    // Display user input
    printf("\nAge: %d\n", age);
    printf("Salary: %.2f\n", salary);

    return 0;
}