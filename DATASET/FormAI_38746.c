//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTER_COUNT 15

void checkStrength(char *password);
//function declaration

int main()
{
    char password[MAX_CHARACTER_COUNT];
    printf("Enter the password: ");
    fgets(password, MAX_CHARACTER_COUNT, stdin);//scanning the input

    checkStrength(password);//calling the function
    return 0;
}
//function definition
void checkStrength(char *password)
{
    int digit = 0, upper = 0, lower = 0, special = 0, length = 0, strength = 0;

    //calculating strength
    length = strlen(password) - 1;

    for (int i = 0; i < length; i++)
    {
        if (isdigit(*(password + i)))
            digit = 1;
        else if (isupper(*(password + i)))
            upper = 1;
        else if (islower(*(password + i)))
            lower = 1;
        else
            special = 1;
    }

    if (length < 6) //minimum length of password is 6
    {
        printf("\nWeak Password!! Length should be minimum 6 characters long.");
        exit(0);
    }

    if (digit && upper && lower && special)
        strength = 4;
    else if ((digit && upper && lower) || (upper && lower && special) || (digit && upper && special) || (digit && lower && special))
        strength = 3;
    else if ((digit && upper) || (upper && lower) || (digit && lower) || (upper && special) || (lower && special) || (digit && special))
        strength = 2;
    else if (digit || upper || lower || special)
        strength = 1;

    //prints password strength
    switch (strength)
    {
    case 1:
        printf("\nWeak Password!! Try using combination of digits, special characters and both upper as well as lower case letters.");
        break;
    case 2:
        printf("\nMedium Password!! Try adding more complexity by using digits and special characters.");
        break;
    case 3:
        printf("\nGood Password!! Try adding more special characters to enhance its strength.");
        break;
    case 4:
        printf("\nStrong Password!! Keep it safe!!");
        break;
    default:
        printf("\nInvalid Password!!");
    }
}