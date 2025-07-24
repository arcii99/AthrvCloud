//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random upper and lower case letters
char generateRandomLetter() {
    int randomNum = rand() % 2;
    char c;
    if (randomNum == 0) {
        c = rand() % 26 + 65; //Upper case letter
    } else {
        c = rand() % 26 + 97; //Lower case letter
    }
    return c;
}

//Function to generate random numbers
int generateRandomNumber() {
    return rand() % 10; //Number between 0-9
}

//Function to generate random special characters
char generateRandomSpecialChar() {
    char specialChars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '='};
    return specialChars[rand() % 14];
}

int main() {
    int passwordLength = 0;
    printf("Enter desired password length: ");
    scanf("%d", &passwordLength);
    char password[passwordLength];
    srand(time(NULL));
    for (int i = 0; i < passwordLength; i++) {
        int randomNum = rand() % 3; //Random number between 0 and 2
        if (randomNum == 0) {
            password[i] = generateRandomLetter();
        } else if (randomNum == 1) {
            password[i] = generateRandomNumber();
        } else {
            password[i] = generateRandomSpecialChar();
        }
    }
    password[passwordLength] = '\0';
    printf("Your password is: %s", password);
    return 0;
}