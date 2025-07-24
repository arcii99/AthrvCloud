//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* function prototypes */
void generatePassword(int length, char* password);

int main()
{
    /* initialize variables */
    int passwordLength = 8;
    char password[100];

    /* seed random number generator */
    srand(time(NULL));

    /* generate password */
    generatePassword(passwordLength, password);
    
    /* print generated password */
    printf("Generated Password: %s\n", password);

    return 0;
}

/*
 * This function generates a secure password
 * of the given length using a mathematical approach
 */
void generatePassword(int length, char* password)
{
    /* initialize variables */
    int i, j, k, randNum;
    char lowerLetters[] = "abcdefghijklmnopqrstuvwxyz";
    char upperLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char symbols[] = "!@#$%^&*(){}[]<>?/\\=~+";

    /* generate random password */
    for(i = 0; i < length; i++)
    {
        /* generate a random number (0 to 3) to determine character type */
        randNum = rand() % 4;

        /* generate a character based on the random number */
        switch(randNum)
        {
            /* lowercase letter */
            case 0:
                password[i] = lowerLetters[rand() % strlen(lowerLetters)];
                break;

            /* uppercase letter */
            case 1:
                password[i] = upperLetters[rand() % strlen(upperLetters)];
                break;

            /* digit */
            case 2:
                password[i] = digits[rand() % strlen(digits)];
                break;

            /* symbol */
            case 3:
                password[i] = symbols[rand() % strlen(symbols)];
                break;
        }
    }

    /* null terminate password */
    password[length] = '\0';
}