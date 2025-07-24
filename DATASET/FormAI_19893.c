//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int upper = 0, lower = 0, digit = 0, special = 0, length;

    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password: ");
    fgets(password, 100, stdin); //get password input from user

    length = strlen(password)-1; // subtracting 1 to exclude the newline character

    for(int i=0; i<length; i++)
    {
        if(isupper(password[i]))  //checking for uppercase letters
        {
            upper++;
        }
        else if(islower(password[i]))  //checking for lowercase letters
        {
            lower++;
        }
        else if(isdigit(password[i]))  //checking for digits
        {
            digit++;
        }
        else
        {
            special++;  //if a character is none of the above, it's considered a special character
        }
    }

    if(length < 8)  //if password length is less than 8, it is considered weak
    {
        printf("Your password is weak because it is less than 8 characters long.\n");
    }
    else if(upper == 0 || lower == 0 || digit == 0)  //if password doesn't contain at least one uppercase letter, one lowercase letter, and one digit, it is considered weak
    {
        printf("Your password is weak because it doesn't contain at least one uppercase letter, one lowercase letter, and one digit.\n");
    }
    else if(special == 0)  //if password doesn't contain any special characters, it is considered medium strength
    {
        printf("Your password is medium strength because it doesn't contain any special characters.\n");
    }
    else  //if password passes all the above conditions, it is considered strong
    {
        printf("Congratulations! Your password is strong!\n");
    }

    return 0;
}