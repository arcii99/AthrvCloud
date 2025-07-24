//FormAI DATASET v1.0 Category: Compression algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE (MAX_INPUT_SIZE / 2)

void RunLengthEncoding(const char* input, char* output)
{
    int count = 1;
    char lastChar = input[0];
    char* pOutput = output;

    for (const char* pInput = input + 1; *pInput != '\0'; ++pInput)
    {
        if (lastChar == *pInput && count < 255)
        {
            ++count;
        }
        else
        {
            *pOutput++ = count;
            *pOutput++ = lastChar;
            lastChar = *pInput;
            count = 1;
        }
    }

    *pOutput++ = count;
    *pOutput++ = lastChar;
    *pOutput = '\0';
}

void RunLengthDecoding(const char* input, char* output)
{
    char* pOutput = output;

    for (const char* pInput = input; *pInput != '\0'; ++pInput)
    {
        int count = *pInput++;
        char ch = *pInput;

        for (int i = 0; i < count; ++i)
        {
            *pOutput++ = ch;
        }
    }

    *pOutput = '\0';
}

int main()
{
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];

    printf("Please enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Original string: %s\n", input);

    RunLengthEncoding(input, output);
    printf("Encoded string: ");
    for (int i = 0; output[i] != '\0'; ++i)
    {
        printf("%02x ", output[i]);
    }
    printf("\n");

    RunLengthDecoding(output, input);
    printf("Decoded string: %s\n", input);

    return 0;
}