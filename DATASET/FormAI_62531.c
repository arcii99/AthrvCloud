//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10 // set password length constant

int main(void)
{
    char password[PASSWORD_LENGTH+1]; // array of chars for storing password
    int i, rand_num; // iteration and random number variables
    srand(time(NULL)); // seed for the random number generator
    
    for(i = 0; i < PASSWORD_LENGTH; i++) // loop for generating the password
    {
        rand_num = rand() % 3; // random number between 0 and 2
        
        switch(rand_num) // switch statement for determining character type
        {
            case 0: // uppercase letters
                password[i] = 'A' + rand() % 26; 
                break;
            case 1: // lowercase letters
                password[i] = 'a' + rand() % 26;
                break;
            case 2: // digits
                password[i] = '0' + rand() % 10;
                break;
        }
    }
    
    password[PASSWORD_LENGTH] = '\0'; // add null terminator to the end of password
    
    printf("Your secure password is: %s\n", password); // print the password
    
    return 0; // return 0 to indicate successful program completion
}