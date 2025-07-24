//FormAI DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to implement run-length encoding algorithm
int runLengthEncode(char *inputString, char *outputString)
{
    int inputLength = strlen(inputString);
    int i, j, count;

    for (i = 0, j = 0; i < inputLength; i = i + count)
    {
        outputString[j] = inputString[i];
        count = 1;

        while (inputString[i] == inputString[i + count] && count < 255)
        {
            count++;
        }

        if (count > 1)
        {
            outputString[j + 1] = count;
            j = j + 2;
        }
        else
        {
            j++;
        }
    }

    outputString[j] = '\0'; // terminate the output string

    return strlen(outputString); // returns length of output string
}

// Function to implement modified Huffman encoding algorithm
int modifiedHuffmanEncode(char *inputString, char **huffmanTable, char *outputString)
{
    int inputLength = strlen(inputString);
    int i, j;

    for (i = 0, j = 0; i < inputLength; i++)
    {
        strcat(outputString, huffmanTable[inputString[i] - 'a']);
        j = j + strlen(huffmanTable[inputString[i] - 'a']);
    }

    outputString[j] = '\0'; // terminate the output string

    return strlen(outputString); // returns length of output string
}

int main()
{
    char inputString[100], outputString[100];
    char *huffmanTable[26] = {"1010", "100000", "00000", "10110", "010", "110011", "100010", "0001",
                                 "0110", "1100001011", "10111", "11000011", "0010", "1111", "1001",
                                 "100001", "1101", "0111", "0100", "0011", "00001", "1100010", "1100000",
                                 "1100011", "100011"};
    int outputLength1, outputLength2;

    printf("Enter the input string to encode:\n");
    fgets(inputString, 100, stdin);

    outputLength1 = runLengthEncode(inputString, outputString);

    outputLength2 = modifiedHuffmanEncode(outputString, huffmanTable, outputString);

    printf("Original string:\n%s", inputString);
    printf("Encoded string:\n%s", outputString);
    printf("Length of original string: %d\n", strlen(inputString));
    printf("Length of encoded string: %d\n", outputLength2);

    return 0;
}