//FormAI DATASET v1.0 Category: Data validation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char name[20], city[20], age[3];

    printf("Hi there! I'm a happy chatbot. What's your name?\n");
    fgets(name, 20, stdin);

    // Strip newline character from user input
    name[strcspn(name, "\n")] = 0;

    // Validate that name is all letters
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            printf("Oops! I'm a cheerful chatbot, but I can't accept digits or special characters for names. Please enter only letters. \n");
            return 1;
        }
    }

    printf("Great %s! And where are you from?\n", name);
    fgets(city, 20, stdin);

    // Strip newline character from user input
    city[strcspn(city, "\n")] = 0;

    // Validate that city is all letters
    for (int i = 0; i < strlen(city); i++) {
        if (!isalpha(city[i])) {
            printf("Oops! I'm a cheerful chatbot, but I can't accept digits or special characters for city names. Please enter only letters. \n");
            return 1;
        }
    }

    printf("Awesome! And how old are you, %s?\n", name);
    fgets(age, 3, stdin);

    // Strip newline character from user input
    age[strcspn(age, "\n")] = 0;

    // Validate that age is a positive integer
    for (int i = 0; i < strlen(age); i++) {
        if (!isdigit(age[i])) {
            printf("Oops! I'm a cheerful chatbot, but I need a positive integer for age. Please enter only digits. \n");
            return 1;
        }
    }

    int age_num = atoi(age);
    if (age_num <= 0) {
        printf("Oops! I'm a cheerful chatbot, but I need a non-zero, positive integer for age. Please enter a valid age. \n");
        return 1;
    }

    printf("Wow, %s from %s -- and you're %d years young! You made it through my validation - congratulations! \n", name, city, age_num);

    return 0;
}