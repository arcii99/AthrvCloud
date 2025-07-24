//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

int main() {
    char password[PASSWORD_LENGTH+1];
    int i;
    srand(time(0)); // seed random number generator with current time
    
    // generate random password
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        int randomChar = rand() % 74 + 48; // ASCII values 48 to 122 are valid password characters
        // exclude characters with special meaning in C strings
        if (randomChar == 47 || randomChar == 92 || randomChar == 34 || randomChar == 39 || randomChar == 32) {
            i--; // try again with a different character
        } else {
            password[i] = (char) randomChar;
        }
    }
    password[PASSWORD_LENGTH] = '\0'; // add null terminator to the end of the password
    
    // print generated password
    printf("Your secure password is: %s\n", password);
    
    return 0;
}