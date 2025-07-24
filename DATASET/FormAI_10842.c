//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 /* Maximum string size */

int main()
{
    char str[MAX_SIZE];
    int i, len, flag = 0;
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for(i=0;i < len ;i++)
    {
        if(str[i] != str[len-i-1])
        {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("%s is not a palindrome\n", str);
    }    
    else {
        printf("%s is a palindrome\n", str);
    }    

    return 0;
}