//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[1000], key[100];
    int len, key_len, i, j;

    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    len = strlen(message);

    printf("Enter the key for encryption: ");
    fgets(key, sizeof(key), stdin);
    key_len = strlen(key);

    for(i = 0, j = 0; i < len; ++i, ++j){
        if(j == key_len){
            j = 0;
        }

        message[i] = message[i] + key[j];

        if(message[i] > 'z'){
            message[i] = message[i] - 'z' + 'a' - 1;
        }
    }

    printf("The encrypted message is: %s", message);

    return 0;
}