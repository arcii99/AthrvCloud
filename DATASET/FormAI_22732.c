//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is palindrome
bool isPalindrome(char str[])
{
    int len = strlen(str);
  
    // Compare character by character from both ends
    for (int i = 0; i < len/2; i++)
        if (str[i] != str[len-i-1])
            return false;
  
    return true;
}

int main()
{
    char str[100];
    printf("Enter a string to check if it is a palindrome: ");
    scanf("%s", str);

    if (isPalindrome(str))
        printf("The string is a palindrome!\n");
    else
        printf("The string is not a palindrome...\n");

    return 0;
}