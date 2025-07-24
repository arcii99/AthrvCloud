//FormAI DATASET v1.0 Category: Data validation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char ageStr[4];
    int age;

    printf("Welcome to the Age Validator!\n");
    printf("Please enter your age: ");
    fgets(ageStr, 4, stdin);

    for(int i = 0; ageStr[i] != '\0'; i++) {
        if(!isdigit(ageStr[i])) {
            printf("Oops! That isn't a valid age. Please try again.\n");
            exit(1);
        }
    }

    age = atoi(ageStr);

    if(age < 0 || age > 150) {
        printf("Oops! Your age must be between 0 and 150. Please try again.\n");
        exit(1);
    } else {
        printf("Congratulations! You entered a valid age.\n");
    }

    return 0;
}