//FormAI DATASET v1.0 Category: Compression algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Exciting Compression Algorithm
int excitingCompression(char* input, char* output)
{
    int inputLen = strlen(input);
    int index = 0;
    int outIndex = 0;
    int count = 0;
    int skip = 0;

    while(index < inputLen)
    {
        if(skip > 0)
        {
            skip--;
            index++;
            continue;
        }

        char currentChar = input[index];
        count = 1;

        for(int i = index + 1; i < inputLen; ++i)
        {
            if(input[i] == currentChar)
            {
                count++;
            }
            else
            {
                break;
            }
        }

        if(count == 1)
        {
            output[outIndex++] = currentChar;
        }
        else if(count > 1 && count < 10)
        {
            output[outIndex++] = count + '0';
            output[outIndex++] = currentChar;
        }
        else if(count == 10)
        {
            output[outIndex++] = '9';
            output[outIndex++] = currentChar;
            skip = count - 2;
        }
        else
        {
            output[outIndex++] = '9';
            output[outIndex++] = currentChar;
            skip = count - 1;
        }

        index += count;
    }

    output[outIndex] = '\0';

    return outIndex;
}

// Test the Exciting Algorithm!
int main(void)
{
    char* input = "WOWWW this compression is so EXCITING!!!";
    char output[100];
    excitingCompression(input, output);

    printf("Input: %s\n", input);
    printf("Output: %s\n", output);

    return 0;
}