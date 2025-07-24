//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    printf("Welcome to the C Secure Password Generator!\n");

    // ask user for password length
    int length;
    printf("Please enter the desired password length: ");
    scanf("%d", &length);

    // create character arrays for possible characters used in password
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_-+=[]{}|;:,.<>?";

    // concatenate arrays into a single character array
    char allChars[strlen(lowercase) + strlen(uppercase) + 
                  strlen(numbers) + strlen(symbols)];
    strcpy(allChars, lowercase);
    strcat(allChars, uppercase);
    strcat(allChars, numbers);
    strcat(allChars, symbols);

    // generate random number seed
    srand(time(NULL));

    // create password character array
    char password[length + 1];

    // loop through password character array and assign
    // a random character from allChars to each position
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % strlen(allChars);
        password[i] = allChars[randomIndex];
    }

    // add null terminating character to end of password character array
    password[length] = '\0';

    printf("Your new secure password is: %s\n", password);

    return 0;
}