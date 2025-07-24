//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: automated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[50];
    int length, upperCount = 0, lowerCount = 0, digitsCount = 0, specialCount = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for(int i=0; i<length; i++)
    {
        if(isupper(password[i]))
            upperCount++;
        else if(islower(password[i]))
            lowerCount++;
        else if(isdigit(password[i]))
            digitsCount++;
        else
            specialCount++;
    }

    if(length >= 8 && (upperCount > 0 && lowerCount > 0 && digitsCount > 0 && specialCount > 0))
        printf("Strong");
    else if(length >= 6 && (upperCount > 0 || lowerCount > 0) && digitsCount > 0)
        printf("Moderate");
    else
        printf("Weak");

    return 0;
}