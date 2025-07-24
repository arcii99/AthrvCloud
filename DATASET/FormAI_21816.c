//FormAI DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = "Linus Torvalds is the creator of Linux!";
    int len = strlen(str);

    printf("Original string: %s\n", str);

    // Reverse the string
    for (int i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }

    printf("Reversed string: %s\n", str);

    // Replace all occurrences of 'i' with '1'
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'i')
        {
            str[i] = '1';
        }
    }

    printf("Replacing 'i' with '1': %s\n", str);

    // Add 'Linus Torvalds says: ' to the beginning of the string
    char prefix[20] = "Linus Torvalds says: ";
    len = strlen(str);
    for (int i = len-1; i >= 0; i--)
    {
        str[i+strlen(prefix)] = str[i];
    }
    for (int i = 0; i < strlen(prefix); i++)
    {
        str[i] = prefix[i];
    }

    printf("Adding prefix: %s\n", str);

    // Remove all occurrences of 'o'
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'o')
        {
            for (int j = i; j < len; j++)
            {
                str[j] = str[j+1];
            }
            len--;
            i--;
        }
    }

    printf("Removing 'o': %s\n", str);

    return 0;
}