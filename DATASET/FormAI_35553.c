//FormAI DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

int main()
{
    char str[MAX_LEN], to_replace[MAX_LEN], replacement[MAX_LEN];

    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);

    printf("Enter the word you want to replace: ");
    fgets(to_replace, MAX_LEN, stdin);

    printf("Enter the word you want to replace with: ");
    fgets(replacement, MAX_LEN, stdin);

    to_replace[strcspn(to_replace, "\n")] = 0;
    replacement[strcspn(replacement, "\n")] = 0;

    int str_len = strlen(str);
    int to_replace_len = strlen(to_replace);
    int replacement_len = strlen(replacement);
    char modified_str[MAX_LEN * (str_len / to_replace_len) + 1];
    int modified_index = 0;

    for (int i = 0; i < str_len; i++)
    {
        if (strncmp(str + i, to_replace, to_replace_len) == 0)
        {
            strncpy(modified_str + modified_index, replacement, replacement_len);
            modified_index += replacement_len;
            i += to_replace_len - 1;
        }
        else
        {
            modified_str[modified_index] = str[i];
            modified_index++;
        }
    }

    modified_str[modified_index] = '\0';

    printf("Modified string: %s", modified_str);

    return 0;
}