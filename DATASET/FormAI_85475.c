//FormAI DATASET v1.0 Category: Data validation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[50];
    int age;

    printf("Please enter your age: ");
    fgets(input, 50, stdin); // use fgets to read user input

    // convert input to integer
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) { // check if input contains non-digit characters
            printf("I'm sorry, that's not a valid age.\n");
            return -1;
        }
    }
    age = atoi(input);

    // check if age is within valid range
    if (age >= 0 && age <= 120) {
        printf("Thank you for entering a valid age of %d years.\n", age);
    } else {
        printf("I'm sorry, that's not a valid age.\n");
        return -1;
    }

    // example of validating a string input
    char name[50];
    printf("Please enter your name: ");
    fgets(name, 50, stdin);
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && !isspace(name[i])) { // check if input contains non-letter or non-space characters
            printf("I'm sorry, that's not a valid name.\n");
            return -1;
        }
    }
    printf("Thank you for entering a valid name.\n");

    // example of validating a float input
    char input2[50];
    float price;
    printf("Please enter the price: ");
    fgets(input2, 50, stdin);
    for (int i = 0; input2[i] != '\0'; i++) {
        if (!isdigit(input2[i]) && input2[i] != '.' && input2[i] != '-') { // check if input contains non-digit, non-decimal, or non-negative characters
            printf("I'm sorry, that's not a valid price.\n");
            return -1;
        }
    }
    price = atof(input2);
    if (price >= 0) {
        printf("Thank you for entering a valid price of $%.2f.\n", price);
    } else {
        printf("I'm sorry, that's not a valid price.\n");
        return -1;
    }

    return 0;
}