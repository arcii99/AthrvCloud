//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: brave
#include <stdio.h> 

// Function to check a string is palindrome or not 
int isPalindrome(char str[]) { 
    int len = 0;
    // Calculating the length of the string
    while (str[len] != '\0')
    {
        len++;
    }

    // Iterating half of the length of the string to check
    for (int i = 0, j = len-1; i < len/2; i++, j--)
    {
        if (str[i] != str[j])
        {
            // Return 0 if string is not palindrome
            return 0;
        }
    }
    // Return 1 if string is palindrome
    return 1; 
} 

int main() 
{ 
    char str[1000];
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);

    // check if the string is a palindrome 
    if (isPalindrome(str)) 
        printf("%s is a palindrome", str); 
    else
        printf("%s is not a palindrome", str); 

    return 0; 
}