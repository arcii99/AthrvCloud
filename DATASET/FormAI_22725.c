//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function to check if the given string is a palindrome or not
int isPalindrome(char str[])
{
    int length = strlen(str);
    
    // check if the given string is empty
    if (length == 0)
        return 0;
    
    // initialize left and right positions
    int left = 0, right = length - 1;
    
    // loop through the string and compare the left and right characters
    while (left <= right)
    {
        // ignore non-alphanumeric characters from the left
        while (left < length && !(isalnum(str[left])))
            left++;
        
        // ignore non-alphanumeric characters from the right
        while (right >= 0 && !(isalnum(str[right])))
            right--;
        
        // check if the left and right characters are equal
        if (left < length && right >= 0 && tolower(str[left]) != tolower(str[right]))
            return 0;
        
        // move left and right positions
        left++;
        right--;
    }
    
    // the string is a palindrome
    return 1;
}

// main function
int main()
{
    char str[100];
    
    // read the input string from the user
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    // remove the newline character from the end of the input string
    str[strcspn(str, "\n")] = 0;
    
    // check if the string is a palindrome
    if (isPalindrome(str))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);
    
    return 0;
}