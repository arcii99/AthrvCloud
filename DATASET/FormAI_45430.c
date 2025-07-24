//FormAI DATASET v1.0 Category: Funny ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int num;
    printf("Welcome to the satisfied program! Please enter a number: ");
    fgets(input, 100, stdin);
    num = atoi(input);

    printf("You have entered the number %d. \n", num);
    printf("Now let's show our satisfaction by printing %d lines of 'I am satisfied!' \n", num);

    for (int i = 0; i < num; i++) {
        printf("I am satisfied! \n");
    }

    printf("Now let's show off our unique coding skills by doubling the number %d and printing it: \n", num);

    num *= 2;

    printf("The new number is %d \n", num);

    printf("Let's see if our program can handle long inputs. Enter a long word or phrase: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // removes newline character

    printf("You entered: %s", input);

    return 0;
}