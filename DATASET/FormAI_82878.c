//FormAI DATASET v1.0 Category: String manipulation ; Style: recursive
#include <stdio.h>
#include <string.h>

void reverse(char* str, int start, int end);

int main()
{
    char myStr[100];

    printf("Enter a string: ");
    scanf("%s", myStr);

    printf("Original string: %s\n", myStr);

    reverse(myStr, 0, strlen(myStr)-1);

    printf("Reversed string: %s\n", myStr);

    return 0;
}

void reverse(char* str, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    // Swap the characters at start and end positions
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursively reverse the substring
    reverse(str, start+1, end-1);
}