//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 16 //can be changed to any desired length

void generatePassword(char *password);

int main()
{
    char password[PASSWORD_LENGTH+1];

    //seed the random number generator with the current time
    srand(time(NULL));

    printf("Your new secure password is:\n");
    generatePassword(password);

    //print the password for the user to see
    printf("%s\n", password);

    return 0;
}

void generatePassword(char *password)
{
    //populate the password array with random characters
    for(int i = 0; i < PASSWORD_LENGTH; i++)
    {
        int randomNum = rand() % 93 + 33; //generates a random number between 33 and 126
        password[i] = (char)randomNum;
    }

    //add a null terminator to the end of the password string
    password[PASSWORD_LENGTH] = '\0';

    //check the password for common mistakes (i.e. consecutive characters, repeating characters)
    int consecutiveChars = 0;
    int repeatingChars = 0;
    for(int i = 0; i < PASSWORD_LENGTH-1; i++)
    {
        if(password[i] == password[i+1]) repeatingChars++;

        if((int)password[i] == ((int)password[i+1]-1) || (int)password[i] == ((int)password[i+1]+1)) consecutiveChars++;
    }
    if(consecutiveChars > 2 || repeatingChars > 2) generatePassword(password); //regenerate the password if there are common mistakes
}