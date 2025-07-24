//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define PASSWORD_LENGTH 12

// Function to generate secure random password
void generatePassword(char* password, int length) {
    srand(time(NULL));  // Seed the random number generator with current time
    const char alphaNumeric[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;
    for(i=0; i<length; i++) {
        int j = rand()%strlen(alphaNumeric);   // Generate random index from 0 to length of alphaNumeric string
        password[i] = alphaNumeric[j];  // Assign random character to password
    }
    password[length] = '\0';   // Add null terminator to the end of password
}

int main() {
    char password[PASSWORD_LENGTH+1];
    generatePassword(password, PASSWORD_LENGTH);
    printf("Generated secure password: %s\n", password);
    return 0;
}