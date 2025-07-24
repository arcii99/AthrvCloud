//FormAI DATASET v1.0 Category: Data validation ; Style: happy
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char user_input[50];

    printf("Welcome to the happiest data validation program ever!\n");
    printf("Please enter your name: ");
    fgets(user_input, 50, stdin);

    for (int i = 0; i < 50; i++) {
        if (isspace(user_input[i])) {
            user_input[i] = '\0';
            break;
        }
    }

    printf("Hello %s!\n", user_input);
    printf("Let's check that your age is valid!\n");
    printf("Please enter your age: ");
    fgets(user_input, 50, stdin);

    for (int i = 0; i < 50; i++) {
        if (isspace(user_input[i])) {
            user_input[i] = '\0';
            break;
        }
    }

    int age = atoi(user_input);

    if (age > 0 && age < 120) {
        printf("Great! %d is a valid age.\n", age);
    } else {
        printf("Sorry, %d is an invalid age.\n", age);
    }

    printf("Now let's check your favorite number!\n");
    printf("Please enter a number between 1 and 10: ");
    fgets(user_input, 50, stdin);

    for (int i = 0; i < 50; i++) {
        if (isspace(user_input[i])) {
            user_input[i] = '\0';
            break;
        }
    }

    int number = atoi(user_input);

    if (number > 0 && number <= 10) {
        printf("Amazing! %d is a valid number.\n", number);
    } else {
        printf("Oh no! %d is an invalid number.\n", number);
    }

    printf("Congratulations, you have successfully passed the happiest data validation!\n");

    return 0;
}