//FormAI DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input_string, int shift);

int main()
{
    char buffer[100];
    int shift;

    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);

    printf("Enter a shift value: ");
    scanf("%d", &shift);

    encrypt(buffer, shift);

    printf("Encrypted string: %s", buffer);

    return 0;
}

void encrypt(char *input_string, int shift)
{
    int len = strlen(input_string);
    for(int i=0; i<len; i++)
    {
        if(input_string[i] >= 'a' && input_string[i] <= 'z')
        {
            input_string[i] = ((input_string[i] - 'a' + shift) % 26) + 'a';
        }
        else if(input_string[i] >= 'A' && input_string[i] <= 'Z')
        {
            input_string[i] = ((input_string[i] - 'A' + shift) % 26) + 'A';
        }
    }
}