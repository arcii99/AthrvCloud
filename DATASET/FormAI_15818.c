//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//define the minimum and maximum length for the generated password
#define MIN_LENGTH 8
#define MAX_LENGTH 20

//define the character sets for each type of character
const char LOWERCASE_CHARS[] = "abcdefghijklmnopqrstuvwxyz";
const char UPPERCASE_CHARS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char NUMERIC_CHARS[] = "0123456789";
const char SPECIAL_CHARS[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

//function to generate a secure password
void generatePassword(int length, char* password) {
    
    //initialize the random number generator with the current time
    srand((unsigned int)time(NULL));

    //initialize counters and flags
    int lowercaseCount = 0;
    int uppercaseCount = 0;
    int numericCount = 0;
    int specialCount = 0;
    int totalCount = 0;
    int hasLowercase = 0;
    int hasUppercase = 0;
    int hasNumeric = 0;
    int hasSpecial = 0;

    //loop until the password meets the minimum length requirement and contains characters from each character set
    while(totalCount < MIN_LENGTH || (!hasLowercase || !hasUppercase || !hasNumeric || !hasSpecial)) {
        
        //clear the password buffer
        memset(password, 0, MAX_LENGTH + 1);

        //loop to generate each character of the password
        for(int i = 0; i < length; i++) {
            
            //generate a random number between 1 and 4 to determine which character set to use
            int charSet = rand() % 4 + 1;

            //generate a random character from the selected character set
            char newChar = '\0';
            switch(charSet) {
                case 1:
                    newChar = LOWERCASE_CHARS[rand() % 26];
                    lowercaseCount++;
                    break;
                case 2:
                    newChar = UPPERCASE_CHARS[rand() % 26];
                    uppercaseCount++;
                    break;
                case 3:
                    newChar = NUMERIC_CHARS[rand() % 10];
                    numericCount++;
                    break;
                case 4:
                    newChar = SPECIAL_CHARS[rand() % 29];
                    specialCount++;
                    break;
            }

            //add the new character to the password buffer
            password[i] = newChar;
        }

        //update the counters and flags
        totalCount = length;
        hasLowercase = lowercaseCount > 0 ? 1 : 0;
        hasUppercase = uppercaseCount > 0 ? 1 : 0;
        hasNumeric = numericCount > 0 ? 1 : 0;
        hasSpecial = specialCount > 0 ? 1 : 0;
    }
}

int main(void) {
    char password[MAX_LENGTH + 1]; //+1 for the null terminator
    generatePassword(MAX_LENGTH, password);
    printf("Generated Password: %s\n", password);
    return 0;
}