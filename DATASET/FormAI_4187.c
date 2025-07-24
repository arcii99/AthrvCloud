//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Secure Password Generator */

int main() {

    /* Seed the random number generator with the current time */
    srand(time(NULL));

    /* Define the characters we want to use to generate the password */
    const char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+=[]{};:,.<>?";
    
    int passwordLength, i;
    char password[100];

    /* Ask the user to enter the desired password length */
    printf("Welcome to the Secure Password Generator!\n\n");
    printf("Please enter the desired password length: ");
    scanf("%d", &passwordLength);

    /* Generate the password by randomly selecting characters from the chars array */
    for (i = 0; i < passwordLength; ++i) {
        password[i] = chars[rand() % (sizeof(chars) - 1)];
    }

    /* Null-terminate the password string*/
    password[passwordLength] = '\0';

    /* Print the password */
    printf("\nYour secure password is: %s\n\n", password);

    return 0;
}