//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12
#define MIN_UPPERCASE 2
#define MIN_LOWERCASE 2
#define MIN_DIGIT 2
#define MIN_SPECIAL 2

/* Function to check if a character is a special character */
bool isSpecialChar(char c) {
    char specialChars[] = "!@#$%^&*()_+{}[]-=';:/?.>,<|";
    for(int i=0; i<strlen(specialChars); i++) {
        if(c == specialChars[i]) {
            return true;
        }
    }
    return false;
}

/* Function to generate a random uppercase letter */
char generateUppercase() {
    return rand() % 26 + 'A';
}

/* Function to generate a random lowercase letter */
char generateLowercase() {
    return rand() % 26 + 'a';
}

/* Function to generate a random digit */
char generateDigit() {
    return rand() % 10 + '0';
}

/* Function to generate a random special character */
char generateSpecial() {
    char specialChars[] = "!@#$%^&*()_+{}[]-=';:/?.>,<|";
    return specialChars[rand() % strlen(specialChars)];
}

/* Function to generate a secure password */
void generatePassword(char* password) {
    int numUppercase = 0, numLowercase = 0, numDigit = 0, numSpecial = 0;
    for(int i=0; i<PASSWORD_LENGTH; i++) {
        char c;
        switch(rand() % 4) {
            case 0:
                c = generateUppercase();
                numUppercase++;
                break;
            case 1:
                c = generateLowercase();
                numLowercase++;
                break;
            case 2:
                c = generateDigit();
                numDigit++;
                break;
            case 3:
                c = generateSpecial();
                numSpecial++;
                break;
        }
        password[i] = c;
    }
    /* Add missing characters to meet criteria */
    while(numUppercase < MIN_UPPERCASE) {
        int i = rand() % PASSWORD_LENGTH;
        if(islower(password[i])) {
            password[i] = generateUppercase();
            numUppercase++;
        }
    }
    while(numLowercase < MIN_LOWERCASE) {
        int i = rand() % PASSWORD_LENGTH;
        if(isupper(password[i])) {
            password[i] = generateLowercase();
            numLowercase++;
        }
    }
    while(numDigit < MIN_DIGIT) {
        int i = rand() % PASSWORD_LENGTH;
        if(!isdigit(password[i])) {
            password[i] = generateDigit();
            numDigit++;
        }
    }
    while(numSpecial < MIN_SPECIAL) {
        int i = rand() % PASSWORD_LENGTH;
        if(!isSpecialChar(password[i])) {
            password[i] = generateSpecial();
            numSpecial++;
        }
    }
}

int main() {
    srand(time(NULL));
    char password[PASSWORD_LENGTH + 1];
    generatePassword(password);
    printf("Secure Password: %s\n", password);
    return 0;
}