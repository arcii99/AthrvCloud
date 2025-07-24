//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char input[100];
    int i, j, length, flag = 0;
    
    printf("Enter a string: ");
    scanf("%s", input);
    
    length = strlen(input);
    
    for(i = 0, j = length-1; i <= j; i++, j--)
    {
        if(input[i] != input[j])
        {
            flag = 1;
            break;
        }
    }
    
    if (flag == 1)
        printf("The string is not a palindrome\n");
    else
        printf("The string is a palindrome\n");
 
    return 0;
}