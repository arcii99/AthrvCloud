//FormAI DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100], output[100];
    int i, j, len;

    printf("Enter a string: ");
    scanf("%[^\n]", input);
    len = strlen(input);

    // Remove spaces
    j = 0;
    for(i = 0; i < len; i++)
    {
        if(input[i] != ' ')
            output[j++] = input[i];
    }
    output[j] = '\0';

    // Convert to uppercase
    len = strlen(output);
    for(i = 0; i < len; i++)
    {
        if(output[i] >= 'a' && output[i] <= 'z')
            output[i] = output[i] - 32;
    }

    // Reverse the string
    len = strlen(output);
    for(i = 0; i < len / 2; i++)
    {
        char temp = output[i];
        output[i] = output[len - i - 1];
        output[len - i - 1] = temp;
    }

    printf("Processed string: %s\n", output);

    return 0;
}