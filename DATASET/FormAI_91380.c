//FormAI DATASET v1.0 Category: Text processing ; Style: authentic
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverse(char *str)
{
    int len = strlen(str);
    int i, j;
    char temp;

    for(i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    // Reversing the string
    reverse(str);

    printf("The reversed string is: %s\n", str);

    return 0;
}