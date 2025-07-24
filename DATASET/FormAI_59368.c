//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

char * generatePassword(){
    // array of characters that can be used to create a password 
    char passwordSet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // Find number of possible characters for password
    int passwordSetLength = strlen(passwordSet);

    // Initialize random seed
    srand(time(NULL));

    // Allocate memory for the password
    char *password = (char*)malloc(MAX_PASSWORD_LENGTH + 1);

    // Generate random password
    for(int i=0; i<MAX_PASSWORD_LENGTH; i++){
        password[i] = passwordSet[rand() % passwordSetLength];
    }
    password[MAX_PASSWORD_LENGTH] = '\0';
    
    return password;
}

void main(){
    char *password = generatePassword();
    printf("Your password is: %s\n", password);
    free(password);
}