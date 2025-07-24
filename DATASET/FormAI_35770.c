//FormAI DATASET v1.0 Category: String manipulation ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {

    printf("Hello! Let's play with strings!\n\n");

    char first_name[20], last_name[20];
    char full_name[40];
    int name_length;

    printf("What is your first name?\n");
    scanf("%s", first_name);
    printf("Great! What is your last name?\n");
    scanf("%s", last_name);

    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);

    name_length = strlen(full_name);

    printf("\nYour full name is %s\n", full_name);
    printf("The length of your full name is %d characters\n\n", name_length);

    char secret[50], guess[50];

    printf("Let's play a guessing game!\n");
    printf("Enter a secret word or phrase (up to 50 characters):\n");
    scanf("%s", secret);

    printf("Great! Now try to guess the secret word or phrase:\n");
    scanf("%s", guess);

    if (strcmp(secret, guess) == 0) {
        printf("\nCongratulations! You guessed correctly!\n");
    } else {
        printf("\nSorry, your guess was incorrect.\n");
        printf("The secret word or phrase was: %s\n", secret);
    }

    return 0;
}