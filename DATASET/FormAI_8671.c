//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: portable
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int i,j,length,isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", input);

    length = strlen(input);

    for(i=0,j=length-1;i<length/2;i++,j--)
    {
        if(input[i] != input[j])
        {
            isPalindrome = 0;
            break;
        }
    }

    if(isPalindrome)
    {
        printf("\n%s is a palindrome!\n", input);
    }
    else
    {
        printf("\n%s is not a palindrome\n", input);
    }

    return 0;

}