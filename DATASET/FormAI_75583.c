//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[1000];
    int i, j, len;
    int flag = 1; // Flag to keep track of whether string is palindrome or not

    printf("Enter a string: ");
    fgets(str, 1000, stdin); // Read input string from user

    len = strlen(str); 

    // Loop through the string from both ends and compare the characters
    for(i=0, j=len-1; i<j; i++,j--)
    {
        // Ignore non-alphanumeric characters
        while(!isalnum(str[i]))
            i++;
        
        while(!isalnum(str[j]))
            j--;
        
        if(tolower(str[i]) != tolower(str[j])) // Compare ignoring case
        {
            flag = 0; // If characters don't match, mark string as not a palindrome
            break;
        }
    }

    if(flag == 1)
        printf("The entered string is a palindrome\n");
    else
        printf("The entered string is not a palindrome\n");

    return 0;
}