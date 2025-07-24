//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

char generateRandomCharacter() {
    int randomAsciiValue = rand() % 94 + 33; // Random value between 33 and 126
    return (char) randomAsciiValue;
}

char* generatePassword(int passwordLength) {
    char* password = malloc((passwordLength+1) * sizeof(char));
    for (int i=0; i<passwordLength; i++) {
        password[i] = generateRandomCharacter();
    }
    password[passwordLength] = '\0';
    return password;
}

int main() {
    srand(time(NULL));
    
    printf("\n\t********* C Secure Password Generator *********\n");

    // Take input for password length
    int passwordLength;
    printf("\nEnter the length of the desired password (max %d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &passwordLength);
    if (passwordLength < 1 || passwordLength > MAX_PASSWORD_LENGTH) {
        printf("\nInvalid password length. Please enter a value between 1 and %d.\n", MAX_PASSWORD_LENGTH);
        return 0;
    }
    
    // Generate password
    char* password = generatePassword(passwordLength);

    printf("\nHere is your generated password:\n\n\t%s\n\n", password);

    // Securely erase password from memory
    memset(password, 0, strlen(password));
    free(password);

    printf("\nPassword erased from memory.\n\n");

    return 0;
}