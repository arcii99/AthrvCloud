//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int length, i;
    char password[20];

    srand(time(NULL));  // initialize the random number generator

    printf("How many characters do you want in your password? (maximum 20): ");
    scanf("%d", &length);

    // Ensure that the password length is within bounds
    if (length > 20) {
        printf("Maximum password length is 20 characters.\n");
        return 0;
    }

    // Generate the password
    for (i = 0; i < length; i++) {
        int random_option = rand() % 4;  // generate a random number between 0 and 3

        if (random_option == 0) {
            // Generate lowercase letter
            password[i] = 'a' + rand() % 26;
        } else if (random_option == 1) {
            // Generate uppercase letter
            password[i] = 'A' + rand() % 26;
        } else if (random_option == 2) {
            // Generate digit
            password[i] = '0' + rand() % 10;
        } else {
            // Generate special character
            char special_chars[] = "!@#$%^&*()_+={}[]|\\:;\"<>,.?/~`";
            password[i] = special_chars[rand() % 32];
        }
    }

    // Add null character at the end of the string
    password[length] = '\0';

    printf("Your generated password is: %s\n", password);

    return 0;
}