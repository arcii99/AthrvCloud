//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: interoperable
#include<stdio.h>
#include<string.h>
#define MAX 100

typedef enum {false, true} bool;

bool is_palindrome(char arr[])
{
    int len = strlen(arr);
    for(int i=0; i<len/2; i++)
    {
        if(arr[i] != arr[len-i-1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char arr[MAX];
    printf("Enter a string: ");
    scanf("%[^\n]s", arr);

    if(is_palindrome(arr))
    {
        printf("%s is a palindrome", arr);
    }
    else
    {
        printf("%s is not a palindrome", arr);
    }

    return 0;
}