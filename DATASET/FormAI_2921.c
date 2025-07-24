//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Post-apocalyptic style secure password generator */
/* Generates a password of length 8-16 consisting of upper and lowercase letters, numbers, and special characters*/

int main() {
    srand(time(NULL)); // Initialize random seed based on current time
    int length = rand() % 9 + 8; // Generate random length between 8 and 16
    char password[length+1]; // Declare character array to store password
    password[length] = '\0'; // Set null terminator at end of password
    
    int i;
    for (i = 0; i < length; i++) {
        int type = rand() % 4; // Generate random number to determine character type
        
        if (type == 0) { // Generate uppercase letter
            password[i] = rand() % 26 + 'A';
        }
        else if (type == 1) { // Generate lowercase letter
            password[i] = rand() % 26 + 'a';
        }
        else if (type == 2) { // Generate number
            password[i] = rand() % 10 + '0';
        }
        else { // Generate special character
            char specialChars[] = {'!', '@', '#', '$', '%', '&', '*', '+', '-', '/', ':', ';', '<', '=', '>', '?', '^', '_', '|', '~'};
            int index = rand() % 20;
            password[i] = specialChars[index];
        }
    }
    
    printf("Your secure password is: %s\n", password); // Print password to user
    return 0;
}