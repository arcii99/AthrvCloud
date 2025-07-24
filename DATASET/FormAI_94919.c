//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number within a range
int generateRand(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate random lowercase letter
char getRandLowercase() {
    return (char) generateRand(97, 122);
}

// Function to generate random uppercase letter
char getRandUppercase() {
    return (char) generateRand(65, 90);
}

// Function to generate random digit
char getRandDigit() {
    return (char) generateRand(48, 57);
}

// Function to generate random symbol
char getRandSymbol() {
    int symbolSetSize = 6;
    char symbolSet[symbolSetSize];
    symbolSet[0] = '!';
    symbolSet[1] = '@';
    symbolSet[2] = '#';
    symbolSet[3] = '$';
    symbolSet[4] = '%';
    symbolSet[5] = '^';
    int index = generateRand(0, symbolSetSize-1);
    return symbolSet[index];
}

// Function to generate password
void generatePassword(int passwordLength, char *password) {
    srand(time(NULL));
    for (int i = 0; i < passwordLength; i++) {
        int randType = generateRand(1, 4);
        switch (randType) {
            case 1:
                password[i] = getRandLowercase();
                break;
            case 2:
                password[i] = getRandUppercase();
                break;
            case 3:
                password[i] = getRandDigit();
                break;
            case 4:
                password[i] = getRandSymbol();
                break;
            default:
                break;
        }
    }
}

int main() {
    char password[20];
    generatePassword(16, password);
    printf("Your secure medieval-style password is: %s\n", password);
    return 0;
}