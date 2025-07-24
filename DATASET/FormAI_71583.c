//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*This program checks if a given string is a palindrome or not. A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward as forward, ignoring spaces, punctuation, and capitalization.*/

/*Function to check if a given character is an alphabet*/
bool isAlphabet(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/*Function to convert a given character to lowercase*/
char toLowercase(char c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

/*Function to check if a given string is a palindrome*/
bool isPalindrome(char* str)
{
    /*Initializes left pointer to the start of the string*/
    int left = 0;

    /*Initializes right pointer to the end of the string*/
    int right = strlen(str) - 1;

    /*Loops until left pointer is less than or equal to right pointer*/
    while (left <= right) {
        /*Skips non-alphabet characters from left*/
        if (!isAlphabet(str[left])) {
            left++;
        }
        /*Skips non-alphabet characters from right*/
        else if (!isAlphabet(str[right])) {
            right--;
        }
        /*If both characters are alphabets*/
        else {
            /*Converts characters to lowercase and checks equality*/
            if (toLowercase(str[left]) != toLowercase(str[right])) {
                /*Returns false if characters are not equal*/
                return false;
            }
            /*Moves left pointer one position forward*/
            left++;
            /*Moves right pointer one position backward*/
            right--;
        }
    }
    /*Returns true if given string is palindrome*/
    return true;
}

/*Main Function*/
int main() {
    char input[100];

    printf("Enter a string to check if it is a palindrome: ");
    /*Taking user input*/
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;

    /*Calls the isPalindrome() function and prints the result*/
    if(isPalindrome(input)) {
        printf("%s is a palindrome.", input);
    } else {
        printf("%s is not a palindrome.", input);
    }

    return 0;
}