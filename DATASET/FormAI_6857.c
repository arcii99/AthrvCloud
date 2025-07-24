//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 64

/* Function prototypes */
void generate_password(int length, char alphabet[]);
int check_character(char c, char arr[], int size);

/* Main function */
int main(void) {

    /* Declare variables */
    int length;
    char alphabet[] = "0123456789abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-=";

    /* Determine the password length from user */
    printf("Please enter the length of the password: ");
    scanf("%d", &length);

    /* Validate user input */
    if (length < 6 || length > MAX_LENGTH) {
        printf("Error: Password length should be between 6 and %d.\n", MAX_LENGTH);
        return 1;
    }

    /* Generate the password */
    generate_password(length, alphabet);

    return 0;
}

/* Function that generates the password */
void generate_password(int length, char alphabet[]) {

    /* Seed the random number generator */
    srand(time(NULL));

    /* Declare variables */
    int i, index;
    char password[MAX_LENGTH] = "";

    /* Loop through the length of the password */
    for (i = 0; i < length; i++) {

        /* Generate a random character and check if it has already been used in the password */
        do {
            index = rand() % (sizeof(alphabet) - 1);
        } while (check_character(alphabet[index], password, i) == 0);

        /* Add the character to the password */
        password[i] = alphabet[index];
    }

    /* Print the password */
    printf("Your new password is:\n%s\n", password);
}

/* Function that checks if a character has already been used in the password */
int check_character(char c, char arr[], int size) {

    /* Declare variables */
    int i;

    /* Loop through the previous characters in the password */
    for (i = 0; i < size; i++) {
        if (c == arr[i]) {
            /* Character already present in password */
            return 0;
        }
    }

    /* Character not present in password yet */
    return 1;
}