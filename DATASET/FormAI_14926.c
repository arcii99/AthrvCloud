//FormAI DATASET v1.0 Category: Text processing ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], output[100], temp[100];
    int i, j, k, l = 0;

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin); // input the sentence

    for (i = 0; i <= strlen(input); i++)
    {
        if (input[i] != ' ' && input[i] != '\0') // if the character is not a space or null value
        {
            temp[l++] = input[i];
        }
        else
        {
            temp[l] = '\0'; // add null value at the end of the string
            for (j = l - 1, k = 0; j >= 0; j--, k++) // reverse the string
            {
                output[k] = temp[j];
            }
            output[k] = '\0'; // add null value at the end of the string
            printf("%s ", output); // print the reversed string
            l = 0; // reset the length variable
        }
    }
    printf("\n");

    return 0;
}