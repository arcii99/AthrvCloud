//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compression(char *str);

int main()
{
    char string[100];
    printf("Enter a string to compress: ");
    fgets(string, sizeof(string), stdin);

    compression(string);

    return 0;
}

void compression(char *str)
{
    int count = 1;
    char compressed_string[100];
    char current_char;

    strcpy(compressed_string, "");
    current_char = str[0];

    for (int i = 1; i < strlen(str); i++)
    {
        if (current_char != str[i])
        {
            char num = count + '0';
            strncat(compressed_string, &num, 1);
            strncat(compressed_string, &current_char, 1);
          
            current_char = str[i];
            count = 1;
        }
        else
        {
            ++count;
        }
    }

    char num = count + '0';
    strncat(compressed_string, &num, 1);
    strncat(compressed_string, &current_char, 1);

    printf("Original String: %s\n", str);
    printf("Compressed String: %s\n", compressed_string);
}