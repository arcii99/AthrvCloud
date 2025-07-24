//FormAI DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], output[100], temp;
    int i, j, len;

    printf("Enter the input string: ");
    fgets(input, 100, stdin);

    // Reversing the input string
    len = strlen(input) - 1; // Ignoring the newline character from fgets
    for(i=0, j=len-1; i<len/2; i++, j--)
    {
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }

    // Removing the vowels from the reversed string
    j = 0;
    for(i=0; i<len; i++)
    {
        if(input[i]!='a' && input[i]!='e' && input[i]!='i' && input[i]!='o' && input[i]!='u' &&
           input[i]!='A' && input[i]!='E' && input[i]!='I' && input[i]!='O' && input[i]!='U')
        {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0'; // Adding null character at the end of output string

    // Reversing the output string
    len = strlen(output);
    for(i=0, j=len-1; i<len/2; i++, j--)
    {
        temp = output[i];
        output[i] = output[j];
        output[j] = temp;
    }

    printf("Output string: %s\n", output);

    return 0;
}