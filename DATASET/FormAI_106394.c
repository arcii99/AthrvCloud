//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    printf("Enter password length: ");
    int passwordLength;
    scanf("%d", &passwordLength);

    char password[passwordLength + 1];
    const char* symbols = "!@#$%^&*()_-+=[]{}\\/.,<>?;:\"'`~";
    int symbolsLength = strlen(symbols);

    for(int i=0; i<passwordLength; i++) {
        if(i % 4 == 0) {
            password[i] = symbols[rand() % symbolsLength];
        } else if(i % 4 == 1) {
            password[i] = toupper('a' + rand() % 26);
        } else if(i % 4 == 2) {
            password[i] = 'A' + rand() % 26;
        } else {
            password[i] = '0' + rand() % 10;
        }
    }

    password[passwordLength] = '\0'; // Add null terminator to end of string

    printf("Generated password: %s\n", password);

    return 0;
}