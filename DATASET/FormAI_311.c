//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12 // define the length of the password you want

// function to generate a secure random password
void generatePassword(char *password, int length)
{
    // declare variables
    int i, random;
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+";
    
    // use time as the seed for the random number generator
    srand((unsigned int) time(NULL));
    
    // generate random characters
    for (i = 0; i < length; i++) {
        random = rand() % sizeof(characters);
        password[i] = characters[random];
    }
    
    // add null terminator to the end of the string
    password[length] = '\0';
}

int main()
{
    char password[PASSWORD_LENGTH + 1]; // declare password string with length + 1 for null terminator
    
    generatePassword(password, PASSWORD_LENGTH); // call the function to generate the password
    
    printf("Your new secure password is: %s\n", password); // output the generated password
    
    return 0;
}