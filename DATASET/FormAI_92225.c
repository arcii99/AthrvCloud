//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

//Function to generate random password of desired length
void generatePassword(int length, char password[]) {
    srand(time(NULL)); //Setting the seed for random number generator
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    int i;
    for (i = 0; i < length; i++) {
        password[i] = characters[rand() % (sizeof(characters) - 1)];
    }
    password[length] = '\0'; //Adding null terminator at the end
}

int main() {
    int passwordLength;
    char password[MAX_PASSWORD_LENGTH + 1];

    printf("Welcome to Secure Password Generator!\n\n");

    while(1) {
        printf("Enter desired password length (between %d and %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &passwordLength);
        if (passwordLength < MIN_PASSWORD_LENGTH || passwordLength > MAX_PASSWORD_LENGTH) {
            printf("Invalid length! Please enter password length between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        } else {
            break;
        }
    }

    generatePassword(passwordLength, password);

    printf("\nYour random secure password of %d characters is: %s\n", passwordLength, password);

    return 0;
}