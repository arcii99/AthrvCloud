//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

unsigned int calculateCheckSum(unsigned char *data, int length);

int main()
{
    unsigned char inputText[100];
    printf("Enter the text to calculate the checksum: ");
    scanf("%s", inputText);

    int length = strlen(inputText);

    unsigned int result = calculateCheckSum(inputText, length);

    printf("\nThe checksum result is: %u", result);

    return 0;
}

unsigned int calculateCheckSum(unsigned char *data, int length)
{
    unsigned int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += data[i];
    }

    return sum % 256;
}