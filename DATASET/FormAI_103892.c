//FormAI DATASET v1.0 Category: Compression algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 200

//This function is used to apply compression on input string
void compress(char *inputString, char *outputString)
{
    int count = 1;
    char currentChar = inputString[0];
    
    int inputStringIndex = 0;
    int outputStringIndex = 0;

    //Iterating through the input string
    while(inputString[inputStringIndex] != '\0')
    {
        inputStringIndex++;

        //If the character being read is same as the current character
        //then we increase the count of current character
        if(inputString[inputStringIndex] == currentChar)
        {
            count++;    
        }
        else
        {
            //Otherwise, we add the current character and its count to the 
            //output string and start counting another character
            outputString[outputStringIndex++] = currentChar;
            outputString[outputStringIndex++] = '0' + count;
            count = 1;
            currentChar = inputString[inputStringIndex];
        }
    }

    //Adding the last character and its count to the output string
    outputString[outputStringIndex++] = currentChar;
    outputString[outputStringIndex++] = '0' + count;

    //Adding NULL character to the end of output string
    outputString[outputStringIndex] = '\0';
}

//This function is used to decompress the input string
void decompress(char *inputString, char *outputString)
{
    int inputStringIndex = 0;
    int outputStringIndex = 0;

    //Iterating through the input string
    while(inputString[inputStringIndex] != '\0')
    {
        char currentChar = inputString[inputStringIndex++];
        int count = inputString[inputStringIndex++] - '0';

        //Adding the current character count number of times
        for(int i = 0; i < count; i++)
        {
            outputString[outputStringIndex++] = currentChar;
        }
    }

    //Adding NULL character to the end of output string
    outputString[outputStringIndex] = '\0';
}

int main()
{
    char inputString[MAX_STRING_SIZE];
    char compressedString[MAX_STRING_SIZE];
    char decompressedString[MAX_STRING_SIZE];

    //Taking the input string from the user
    printf("Enter a string to compress: ");
    scanf("%[^\n]%*c", inputString);

    //Applying compression on the input string
    compress(inputString, compressedString);
    printf("Compressed string: %s\n", compressedString);

    //Decompressing the compressed string
    decompress(compressedString, decompressedString);
    printf("Decompressed string: %s\n", decompressedString);

    return 0;
}