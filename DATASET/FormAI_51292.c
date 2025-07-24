//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12

int main() {

    char password[PASSWORD_LENGTH+1];
    int i, randomDigit, randomLetter, randomSymbol;

    srand(time(NULL));

    // generate random digits
    for(i=0; i < 2; ++i) {
        randomDigit = rand() % 10;
        password[i] = randomDigit + '0';
    }

    // generate random uppercase letters
    for(i=2; i < 5; ++i) {
        randomLetter = rand() % 26;
        password[i] = randomLetter + 'A';
    }

    // generate random lowercase letters
    for(i=5; i < 8; ++i) {
        randomLetter = rand() % 26;
        password[i] = randomLetter + 'a';
    }

    // generate random symbols
    for(i=8; i < 10; ++i) {

        switch(rand() % 4) {
            case 0:
                randomSymbol = rand() % 16;
                password[i] = randomSymbol < 10 ? randomSymbol + '0' : randomSymbol + 'A' - 10;
                break;
            case 1:
                password[i] = '!';
                break;
            case 2:
                password[i] = '@';
                break;
            case 3:
                password[i] = '#';
                break;
        }
    }

    // add a random symbol from all ASCII symbols
    password[10] = rand() % (127 - 33) + 33;

    // terminate the string with null character
    password[PASSWORD_LENGTH] = '\0';

    // shuffle the characters randomly
    for(i=0; i < PASSWORD_LENGTH; ++i) {
        int j = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // validate the password
    int hasDigit = 0, hasLower = 0, hasUpper = 0, hasSymbol = 0;
    for(i=0; i < PASSWORD_LENGTH; ++i) {
        if(isdigit(password[i])) hasDigit = 1;
        else if(islower(password[i])) hasLower = 1;
        else if(isupper(password[i])) hasUpper = 1;
        else hasSymbol = 1;
    }

    // regenerate the password if it doesn't meet the requirements
    while(!hasDigit || !hasLower || !hasUpper || !hasSymbol) {

        // generate random digits
        for(i=0; i < 2; ++i) {
            randomDigit = rand() % 10;
            password[i] = randomDigit + '0';
        }

        // generate random uppercase letters
        for(i=2; i < 5; ++i) {
            randomLetter = rand() % 26;
            password[i] = randomLetter + 'A';
        }

        // generate random lowercase letters
        for(i=5; i < 8; ++i) {
            randomLetter = rand() % 26;
            password[i] = randomLetter + 'a';
        }

        // generate random symbols
        for(i=8; i < 10; ++i) {

            switch(rand() % 4) {
                case 0:
                    randomSymbol = rand() % 16;
                    password[i] = randomSymbol < 10 ? randomSymbol + '0' : randomSymbol + 'A' - 10;
                    break;
                case 1:
                    password[i] = '!';
                    break;
                case 2:
                    password[i] = '@';
                    break;
                case 3:
                    password[i] = '#';
                    break;
            }
        }

        // add a random symbol from all ASCII symbols
        password[10] = rand() % (127 - 33) + 33;

        // terminate the string with null character
        password[PASSWORD_LENGTH] = '\0';

        // shuffle the characters randomly
        for(i=0; i < PASSWORD_LENGTH; ++i) {
            int j = rand() % PASSWORD_LENGTH;
            char temp = password[i];
            password[i] = password[j];
            password[j] = temp;
        }

        // validate the new password
        hasDigit = 0, hasLower = 0, hasUpper = 0, hasSymbol = 0;
        for(i=0; i < PASSWORD_LENGTH; ++i) {
            if(isdigit(password[i])) hasDigit = 1;
            else if(islower(password[i])) hasLower = 1;
            else if(isupper(password[i])) hasUpper = 1;
            else hasSymbol = 1;
        }
    }

    // print the password
    printf("Your secure password is: %s", password);

    return 0;
}