//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 8 // minimum password length
#define MAX_LENGTH 16 // maximum password length
#define CHAR_SET_LENGTH 62 // total number of characters to choose from

int main()
{
    char charSet[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // character set to choose from
    int passwordLength, i;
    char password[MAX_LENGTH + 1]; // add 1 for null terminator
    srand(time(NULL)); // seed random number generator

    printf("Secure Password Generator\n");
    printf("========================\n\n");

    printf("How many characters long do you want the password to be? (min: %d, max: %d) ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &passwordLength);

    // check if password length is within the allowed bounds
    if (passwordLength < MIN_LENGTH || passwordLength > MAX_LENGTH)
    {
        printf("\nError: Password length should be between %d and %d characters long.", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    // generate random characters for password
    for (i = 0; i < passwordLength; i++)
    {
        int randomIndex = rand() % CHAR_SET_LENGTH; // get random index for character set
        password[i] = charSet[randomIndex]; // add random character to password
    }
    password[i] = '\0'; // add null terminator to end of password string

    printf("\nGenerated Password: %s\n", password);

    return 0;
}