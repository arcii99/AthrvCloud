//FormAI DATASET v1.0 Category: String manipulation ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

// function prototype
void ShannonEncode(char str[]);
void ShannonDecode(char str[]);

// main function
int main()
{
    char str[100];

    // take user input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // encode string using Shannon's algorithm
    ShannonEncode(str);
    printf("Encoded string: %s\n", str);

    // decode string using Shannon's algorithm
    ShannonDecode(str);
    printf("Decoded string: %s\n", str);

    return 0;
}

// function definition for Shannon's encoding algorithm
void ShannonEncode(char str[])
{
    int len = strlen(str);
    int i, j;
    char temp;
    for(i = 0; i < len - 1; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            if(str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
        str[i] -= i;
    }
}

// function definition for Shannon's decoding algorithm
void ShannonDecode(char str[])
{
    int len = strlen(str);
    int i, j;
    char temp;
    for(i = len - 2; i >= 0; i--)
    {
        str[i] += i;
        for(j = i + 1; j < len - 1; j++)
        {
            if(str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}