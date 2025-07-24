//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[100];
    int length, i, j, flag = 1;
    
    printf("Welcome to the Palindrome Checker program!\n\n");
    printf("Please enter a string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    
    length = strlen(input);
    
    // Remove punctuations, spaces and convert to lowercase
    for (i = 0, j = 0; i < length; i++)
    {
        if (!ispunct(input[i]) && !isspace(input[i]))
        {
            input[j] = tolower(input[i]);
            j++;
        }
    }
    input[j] = '\0';
    
    length = strlen(input);
    
    // Check if the string is a palindrome or not
    for (i = 0; i < length/2; i++)
    {
        if (input[i] != input[length-i-1])
        {
            flag = 0;
            break;
        }
    }
    
    if (flag)
    {
        printf("\n%s is a palindrome!", input);
    }
    else
    {
        printf("\n%s is not a palindrome.", input);
    }
    
    return 0;
}