//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main()
{
    char inputStr[100]; // define a char array to store the input string
    int i, j, len, flag = 0; // declare some variables to be used later

    printf("Welcome to the Palindrome Checker Program!\n\n");
    printf("Please enter a string to check if it's a palindrome or not:\n");
    scanf("%s", inputStr); // read the input string from the user

    len = strlen(inputStr);

    // iterate over the first half of the string
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        // check if the i-th character is equal to the j-th character
        if (inputStr[i] != inputStr[j]) {
            flag = 1; // set the flag to indicate the string is not a palindrome
            break;
        }
    }

    if (flag) {
        printf("\nSorry, the input string '%s' is not a palindrome.\n", inputStr);
    } else {
        printf("\nGreat news, the input string '%s' is indeed a palindrome!\n", inputStr);
    }

    return 0;
}