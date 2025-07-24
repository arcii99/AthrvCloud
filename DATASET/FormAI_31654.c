//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid_name(char *name) {
    int i;

    for (i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return 0;
        }
    }
    return 1;
}

int is_valid_age(char *age) {
    int i;

    for (i = 0; i < strlen(age); i++) {
        if (!isdigit(age[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char name[100];
    char age[10];

    printf("Please enter your name: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    while (!is_valid_name(name)) {
        printf("Invalid input. Please enter a valid name: ");
        fgets(name, 100, stdin);
        name[strcspn(name, "\n")] = 0;
    }

    printf("Please enter your age: ");
    fgets(age, 10, stdin);
    age[strcspn(age, "\n")] = 0;

    while (!is_valid_age(age)) {
        printf("Invalid input. Please enter a valid age: ");
        fgets(age, 10, stdin);
        age[strcspn(age, "\n")] = 0;
    }

    printf("Hello %s! You are %s years old.\n", name, age);

    return 0;
}