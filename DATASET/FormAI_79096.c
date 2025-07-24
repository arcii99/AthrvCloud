//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define TRUE 1

int main() {

    char password[PASSWORD_LENGTH+1];
    int i, random, upper, lower, num, special;
    srand(time(NULL));   // Seed random number generator

    // Password generation loop
    do {
        upper = lower = num = special = 0;  // Reset counters
        for (i = 0; i < PASSWORD_LENGTH; i++) {
            random = rand() % 4;  // Generate a random number between 0 and 3

            // Add a random character to the password based on the random number
            switch (random) {
                case 0:     // Upper case letter
                    password[i] = rand() % 26 + 'A';
                    upper++;
                    break;
                case 1:     // Lower case letter
                    password[i] = rand() % 26 + 'a';
                    lower++;
                    break;
                case 2:     // Number
                    password[i] = rand() % 10 + '0';
                    num++;
                    break;
                case 3:     // Special character
                    password[i] = rand() % 15 + 33;  // 33-47 ASCII range
                    special++;
                    break;
            }
        }
    } while (upper < 2 || lower < 2 || num < 2 || special < 2);   // Repeat until at least 2 of each character type exist

    password[PASSWORD_LENGTH] = '\0';  // Terminate password string

    printf("Your secure password is:\n%s\n", password);   // Display password to user

    return 0;
}