//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// function to generate random password
void generatePassword(int length, char* password) {
    // define the characters to use in password
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+~`|}{[]:;?><,./-=";
    // calculate number of characters in defined set
    int charCount = strlen(characters);

    // seed the random number generator
    srand(time(NULL));

    // generate a random character for each position in password string
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % charCount;
        password[i] = characters[randomIndex];
    }

    // add null character to end of string
    password[length] = '\0';
}

int main() {
    // get user input for the length of password
    int length;
    printf("Enter the desired length for your password (minimum 8):\n");
    scanf("%d", &length);

    // check for minimum password length requirement
    if (length < 8) {
        printf("Error: password length must be at least 8 characters.\n");
        return 1;
    }

    // declare a char array to hold generated password
    char password[length+1];

    // call function to generate password
    generatePassword(length, password);

    // output generated password to console
    printf("Your password is: %s\n", password);

    return 0;
}