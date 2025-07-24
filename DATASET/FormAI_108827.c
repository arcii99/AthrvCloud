//FormAI DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    int key, i;

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    for(i = 0; i < strlen(string); i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = (string[i] - 'a' + key) % 26 + 'a';
        }
        else if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = (string[i] - 'A' + key) % 26 + 'A';
        }
    }

    printf("Encrypted string: %s", string);

    return 0;
}