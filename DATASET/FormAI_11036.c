//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 20

// function to generate a random integer between min and max values
int getRandomNumber(int min, int max) {
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}

// function to generate a random uppercase alphabet
char getRandUpperChar() {
    return getRandomNumber(65, 90);
}

// function to generate a random lowercase alphabet
char getRandLowerChar() {
    return getRandomNumber(97, 122);
}

// function to generate a random numeric digit
char getRandNumber() {
    return getRandomNumber(48, 57);
}

int main() {
    char password[MAX_LENGTH + 1];
    int length, i;
    printf("Enter the length of the password (max length: %d): ", MAX_LENGTH);
    scanf("%d", &length);
    if (length > MAX_LENGTH)
        length = MAX_LENGTH;
    printf("Generating a secure password of length %d...\n", length);
    for (i = 0; i < length; i++) {
        int characterType = getRandomNumber(1, 3); // generate a random number between 1 and 3 to choose the character type
        if (characterType == 1)
            password[i] = getRandUpperChar();
        else if (characterType == 2)
            password[i] = getRandLowerChar();
        else
            password[i] = getRandNumber();
    }
    password[length] = '\0';
    printf("Generated password is: %s\n", password);
    return 0;
}