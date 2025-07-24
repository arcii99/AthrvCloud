//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <ctype.h>

int main()
{
    char message[100], ch;
    int key, i;

    printf("Enter a message to encrypt: ");
    gets(message);

    printf("Enter the key: ");
    scanf("%d", &key);

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        if(isalpha(ch)){
            ch = toupper(ch);
            ch = ch + key;

            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }

    printf("Encrypted message: %s", message);

    return 0;
}