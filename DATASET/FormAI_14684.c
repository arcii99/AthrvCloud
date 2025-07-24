//FormAI DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void racecondition(int age);    // Function prototype

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if(age < 0) {
        printf("Error: Age cannot be negative.\n");
        exit(0);    // Exit the program gracefully
    }
    racecondition(age);    // Function call
    return 0;
}

void racecondition(int age) {
    int reducedAge;

    if(age >= 18) {
        printf("You are eligible to vote.\n");
        reducedAge = age - 18;
        printf("You could have voted for %d years now.\n", reducedAge);
    } else {
        printf("You are not eligible to vote.\n");
        reducedAge = 18 - age;
        printf("You can vote after %d more years.\n", reducedAge);
    }
}