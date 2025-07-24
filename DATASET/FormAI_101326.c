//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[50];
    int length, numCount, upperCount, lowerCount, specialCount = 0;
    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    //Check for length
    if (length < 8) {
        printf("Your password is too short!\n");
        printf("Please enter a password that is at least 8 characters long.\n");
        return 0;
    }

    //Check for uppercase letters, lowercase letters, numbers and special characters
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            numCount++;
        }
        else if (isupper(password[i])) {
            upperCount++;
        }
        else if (islower(password[i])) {
            lowerCount++;
        }
        else {
            specialCount++;
        }
    }

    //Check for number of occurrences
    if (numCount < 2 || upperCount == 0 || lowerCount == 0 || specialCount == 0) {
        printf("Your password is not strong enough!\n");
        printf("Please enter a password that contains at least 2 digits, 1 uppercase letter, 1 lowercase letter and 1 special character.\n");
        return 0;
    }

    printf("Your password is strong!\n");
    return 0;
}