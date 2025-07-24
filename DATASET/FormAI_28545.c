//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *string);

int main()
{
    char inputString[1000];
    printf("Enter a string: ");
    fgets(inputString, 1000, stdin);

    //convert input string to lowercase
    for (int i = 0; inputString[i]; i++) {
        inputString[i] = tolower(inputString[i]);
    }

    if (isPalindrome(inputString)) {
        printf("%s is a palindrome.\n", inputString);
    } else {
        printf("%s is NOT a palindrome.\n", inputString);
    }

    //exit program
    return 0;
}

int isPalindrome(char *string)
{
    //variables for leftmost and rightmost indices
    int left = 0;
    int right = strlen(string) - 1;

    //iterate through string from both ends, comparing characters
    while (right > left) {
        //skip spaces and non-alphanumeric characters
        while (!isalnum(string[left]) && right > left) {
            left++;
        }
        while (!isalnum(string[right]) && right > left) {
            right--;
        }

        //compare lowercase characters
        if (tolower(string[left++]) != tolower(string[right--])) {
            return 0; //not a palindrome
        }
    }

    return 1; //is a palindrome
}