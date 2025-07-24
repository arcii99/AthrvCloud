//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: distributed
#include <stdio.h>
#include <string.h>

// Function to check if a string is palindrome
int isPalindrome(char *str)
{
    int len = strlen(str);
    int i;
    for(i = 0; i < len/2; i++)
    {
        if(str[i] != str[len-i-1])
            return 0;
    }
    return 1;
}

// Function to split a string into two halves
void splitString(char *str, char *firstHalf, char *secondHalf)
{
    int len = strlen(str);
    int half = len/2;
    strncpy(firstHalf, str, half);
    strncpy(secondHalf, str+half, len-half);
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // remove newline character from input
    printf("You entered: %s\n", str);
    char firstHalf[50];
    char secondHalf[50];
    splitString(str, firstHalf, secondHalf);
    // Check if first half is equal to reverse of second half
    if(isPalindrome(firstHalf) && isPalindrome(secondHalf))
        printf("%s is a palindrome with two equal halves.\n", str);
    else
        printf("%s is not a palindrome with two equal halves.\n", str);
    return 0;
}