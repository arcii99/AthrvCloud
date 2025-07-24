//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a secure password
void generatePassword(char* password) {
    int length, i;
    char characters[95] = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

    // Get random length between 15 and 20 characters
    length = rand() % 6 + 15;

    // Generate random password using characters string
    for(i = 0; i < length; i++) {
        password[i] = characters[rand() % 94];
    }

    // End the string with null character
    password[length] = '\0';
}

int main() {
    char password[21];
    int i, j, uppercase, lowercase, digit, special;

    srand(time(NULL));  // Initialize random number generator

    // Generate 10 unique passwords
    for(i = 0; i < 10; i++) {
        // Generate a password
        generatePassword(password);

        // Check password strength
        uppercase = lowercase = digit = special = 0;
        for(j = 0; j < strlen(password); j++) {
            if(password[j] >= 'A' && password[j] <= 'Z') {
                uppercase = 1;
            }
            else if(password[j] >= 'a' && password[j] <= 'z') {
                lowercase = 1;
            }
            else if(password[j] >= '0' && password[j] <= '9') {
                digit = 1;
            }
            else {
                special = 1;
            }
        }

        // If password meets requirements, print it out
        if(uppercase && lowercase && digit && special) {
            printf("Password %d: %s\n", i + 1, password);
        }
        else {  // Otherwise, regenerate password
            i--;
        }
    }

    return 0;
}