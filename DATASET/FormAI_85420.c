//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: expert-level
#include<stdio.h>
#include<string.h>

int main()
{
    char input_string[1000];
    printf("Enter a string:\n");
    fgets(input_string, 1000, stdin);
    input_string[strlen(input_string)-1] = '\0'; //removes trailing newline character

    int is_palindrome = 1; //1 for true, 0 for false
    int length = strlen(input_string);

    for(int i=0; i<length/2; i++)
    {
        if(input_string[i]!=input_string[length-1-i])
        {
            is_palindrome = 0;
            break;
        }
    }

    if(is_palindrome)
    {
        printf("%s is a palindrome.", input_string);
    }
    else
    {
        printf("%s is not a palindrome.", input_string);
    }

    return 0;
}