//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 20     // Maximum password length
#define MIN_LENGTH 8      // Minimum password length
#define MAX_DIGIT 5       // Maximum number of digits
#define MAX_SPECIAL 3     // Maximum number of special characters
#define MAX_UPPER 3       // Maximum number of uppercase characters

char* generatePassword(int length, int digit, int special, int upper);

int main()
{
    int length, digit, special, upper;
    char* password;
    
    srand(time(NULL));  // Seed for random number generator
    
    printf("Welcome to the Peaceful Secure Password Generator Program. \n");
    printf("Enter the desired password length: ");
    scanf("%d", &length);
    while (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Password length must be between %d and %d characters. \n", MIN_LENGTH, MAX_LENGTH);
        printf("Enter the desired password length: ");
        scanf("%d", &length);
    }
    
    printf("Enter the number of digits: ");
    scanf("%d", &digit);
    while (digit > MAX_DIGIT) {
        printf("Password cannot have more than %d digits. \n", MAX_DIGIT);
        printf("Enter the number of digits: ");
        scanf("%d", &digit);
    }
    
    printf("Enter the number of special characters: ");
    scanf("%d", &special);
    while (special > MAX_SPECIAL) {
        printf("Password cannot have more than %d special characters. \n", MAX_SPECIAL);
        printf("Enter the number of special characters: ");
        scanf("%d", &special);
    }
    
    printf("Enter the number of uppercase characters: ");
    scanf("%d", &upper);
    while (upper > MAX_UPPER) {
        printf("Password cannot have more than %d uppercase characters. \n", MAX_UPPER);
        printf("Enter the number of uppercase characters: ");
        scanf("%d", &upper);
    }
    
    password = generatePassword(length, digit, special, upper);
    
    printf("\nGenerated password: %s", password);
    free(password);
    
    return 0;
}


char* generatePassword(int length, int digit, int special, int upper) {
    char* password = (char*) malloc((length+1) * sizeof(char));
    int i, j, k, digitCount = 0, specialCount = 0, upperCount = 0;
    int maxDigit = length / 2;   // Maximum number of digits allowed based on password length
    
    for (i = 0; i < length; i++) {  // Generate random password
        if (digitCount < digit && rand() % 2 == 0 && digitCount < maxDigit) {
            *(password+i) = rand() % 10 + 48;
            digitCount++;
        }
        else if (specialCount < special && rand() % 2 == 0) {
            switch (rand() % 5) {
                case 0:
                    *(password+i) = '!';
                    break;
                case 1:
                    *(password+i) = '@';
                    break;
                case 2:
                    *(password+i) = '#';
                    break;
                case 3:
                    *(password+i) = '$';
                    break;
                case 4:
                    *(password+i) = '%';
                    break;
            }
            specialCount++;
        }
        else if (upperCount < upper && rand() % 2 == 0) {
            *(password+i) = rand() % 26 + 65;
            upperCount++;
        }
        else {
            *(password+i) = rand() % 26 + 97;
            // lowercase character
        }
    }
    *(password+length) = '\0';
    
    // Shuffle the password array
    for (i = length-1; i >= 0; i--) {
        j = rand() % (i+1);
        k = *(password+i);
        *(password+i) = *(password+j);
        *(password+j) = k;
    }
    
    return password;
}