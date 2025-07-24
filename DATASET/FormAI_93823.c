//FormAI DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <string.h>

void cipher(char *input, int key);

int main()
{
    char message[100];
    int key;

    printf("Enter the message to encrypt: ");
    scanf("%[^\n]%*c", message);

    printf("Enter the key: ");
    scanf("%d", &key);

    cipher(message, key);
    printf("The encrypted message is: %s\n", message);
}

void cipher(char *input, int key)
{
    int i;
    int len = strlen(input);

    for (i = 0; i < len; i++){
        if (input[i] >= 'a' && input[i] <= 'z'){
            input[i] = 'a' + (input[i] - 'a' + key) % 26;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z'){
            input[i] = 'A' + (input[i] - 'A' + key) % 26;
        }
    }
}