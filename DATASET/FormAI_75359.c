//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_PASS 30

int main() {
    char* alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{};:<>,.?/|\\";
    int alpha_len = strlen(alphabet);
    int pass_len = 0; // the length of the password
    char password[MAX_PASS + 1]; // create a char array with one extra spot for the null terminator

    // seed the random number generator with the time
    srand(time(NULL));

    // ask the user for the length of the password they want
    printf("How long do you want your password to be? ");
    scanf("%d", &pass_len);

    // check that the password length is within the bounds of the array
    if (pass_len <= 0 || pass_len > MAX_PASS) {
        printf("Invalid password length");
        return 1;
    }

    // generate the password by randomly choosing characters from the alphabet
    for (int i = 0; i < pass_len; i++) {
        password[i] = alphabet[rand() % alpha_len];
    }

    // add the null terminator to the end of the password string
    password[pass_len] = '\0';

    // print the password
    printf("Your secure password is: %s", password);

    return 0;
}