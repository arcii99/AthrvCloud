//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12

int main() {
    srand(time(NULL));
    char password[PASSWORD_LENGTH+1];
    int i, randomNum;
    int uppercaseCount = 0, lowercaseCount = 0, digitCount = 0, specialCharCount = 0;
    const char *uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const char *digitChars = "0123456789";
    const char *specialChars = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    // Generate initial password with random characters
    for(i = 0; i < PASSWORD_LENGTH; i++) {
        randomNum = rand() % 4;
        switch(randomNum) {
            case 0:
                password[i] = uppercaseChars[rand() % 26];
                uppercaseCount++;
                break;
            case 1:
                password[i] = lowercaseChars[rand() % 26];
                lowercaseCount++;
                break;
            case 2:
                password[i] = digitChars[rand() % 10];
                digitCount++;
                break;
            case 3:
                password[i] = specialChars[rand() % 31];
                specialCharCount++;
                break;
        }
    }

    // Ensure password meets requirements
    while(uppercaseCount < 2 || lowercaseCount < 2 || digitCount < 2 || specialCharCount < 2) {
        for(i = 0; i < PASSWORD_LENGTH; i++) {
            if(uppercaseCount < 2 && isupper(password[i])) {
                password[i] = lowercaseChars[rand() % 26];
                uppercaseCount--;
                lowercaseCount++;
            }
            if(lowercaseCount < 2 && islower(password[i])) {
                password[i] = uppercaseChars[rand() % 26];
                lowercaseCount--;
                uppercaseCount++;
            }
            if(digitCount < 2 && isdigit(password[i])) {
                password[i] = specialChars[rand() % 31];
                digitCount--;
                specialCharCount++;
            }
            if(specialCharCount < 2 && ispunct(password[i])) {
                password[i] = digitChars[rand() % 10];
                specialCharCount--;
                digitCount++;
            }
        }
    }
    password[PASSWORD_LENGTH] = '\0';

    printf("Generated password: %s\n", password);

    return 0;
}