//FormAI DATASET v1.0 Category: Compression algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using Run Length Encoding algorithm
// The output string should be smaller than the input string
char *compressString(char *inputString)
{
    int inputLength = strlen(inputString);
    int outputLength = 2 * inputLength + 1; // max size of output string
    char *outputString = malloc(sizeof(char) * outputLength);
    int count = 1;
    int outputIndex = 0;
    
    // loop through the input string and count repetitions
    for(int i = 0; i < inputLength; i++)
    {
        if(inputString[i] == inputString[i+1])
        {
            count++;
        }
        else
        {
            // append the count and character to the output string
            outputString[outputIndex++] = count + '0';
            outputString[outputIndex++] = inputString[i];
            count = 1;
        }
    }

    outputString[outputIndex] = '\0'; // terminate the output string
    return outputString;
}

int main()
{
    char inputString[50];
    printf("Enter the string to be compressed:");
    scanf("%[^\n]s", inputString);
    
    char *outputString = compressString(inputString);
    printf("The compressed string is: %s\n", outputString);
    free(outputString);
    return 0;
}