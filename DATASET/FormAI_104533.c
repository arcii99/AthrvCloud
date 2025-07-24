//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASS_LENGTH 8
#define MAX_PASS_LENGTH 16

int check_password_strength(char *password);

int main()
{
    char password[MAX_PASS_LENGTH+1];
    int strength;

    printf("Enter your desired password: ");
    fgets(password, MAX_PASS_LENGTH+1, stdin);

    // remove newline character from password
    password[strcspn(password, "\n")] = 0;

    strength = check_password_strength(password);

    switch(strength)
    {
        case 1:
            printf("The password is weak.\n");
            break;
        case 2:
            printf("The password is moderate.\n");
            break;
        case 3:
            printf("The password is strong.\n");
            break;
        default:
            printf("Invalid password\n");
    }

    return 0;
}

int check_password_strength(char *password)
{
    int length = strlen(password);
    int uppercase = 0, lowercase = 0, digit = 0, special_char = 0;
    int i;

    // check password length
    if(length < MIN_PASS_LENGTH || length > MAX_PASS_LENGTH)
    {
        return 0;
    }

    // check if password contains uppercase letters, lowercase letters, digits, and special characters
    for(i=0; i<length; i++)
    {
        if(isupper(password[i]))
        {
            uppercase = 1;
        }
        else if(islower(password[i]))
        {
            lowercase = 1;
        }
        else if(isdigit(password[i]))
        {
            digit = 1;
        }
        else if(!isalnum(password[i]))
        {
            special_char = 1;
        }
    }

    // calculate password strength based on requirements
    if(uppercase && lowercase && digit && special_char)
    {
        return 3;   // strong password
    }
    else if((uppercase && lowercase && digit) || (lowercase && digit && special_char))
    {
        return 2;   // moderate password
    }
    else
    {
        return 1;   // weak password
    }
}