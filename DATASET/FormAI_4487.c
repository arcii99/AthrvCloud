//FormAI DATASET v1.0 Category: String manipulation ; Style: recursive
#include<stdio.h>
#include<string.h>

// Recursive function to reverse a string
void reverse(char str[], int start, int end)
{
    if (start >= end)
        return;
  
    // Swap the first and last characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
  
    // Recursive function call
    reverse(str, start+1, end-1);
}

// Recursive function to check if a string is palindrome
int isPalindrome(char str[], int start, int end)
{
    // Base case
    if (start >= end)
        return 1;
  
    // If first and last characters are not same
    if (str[start] != str[end])
        return 0;
  
    // Recursive function call
    return isPalindrome(str, start+1, end-1);
}

// Recursive function to count the occurrence of a substring in a string
int countSubstring(char str[], char sub[], int start, int count)
{
    int sub_len = strlen(sub);
    int j;

    // Base case
    if (start >= strlen(str))
        return count;
  
    // If a substring is found
    if (strncmp(&str[start], sub, sub_len) == 0)
        count++;
            
    // Recursive function call
    return countSubstring(str, sub, start+1, count);
}

int main()
{
    char str[100], sub[100];
  
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    // Reverse the string
    reverse(str, 0, strlen(str)-1);
    printf("Reverse of the string: %s\n", str);
  
    // Check if the string is palindrome
    if (isPalindrome(str, 0, strlen(str)-1))
        printf("The string is palindrome.\n");
    else
        printf("The string is not palindrome.\n");

    printf("Enter a substring to search: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = '\0';
  
    // Count the occurrence of a substring
    int count = countSubstring(str, sub, 0, 0);
    printf("The substring '%s' occurs %d times in the string '%s'\n", sub, count, str);

    return 0;
}