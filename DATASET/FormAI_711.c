//FormAI DATASET v1.0 Category: Encryption ; Style: retro
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char message[100], key[100], encrypted[100], decrypted[100];
    int i, j;

    
    printf("Enter the message to be encrypted:\n");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key:\n");
    fgets(key, sizeof(key), stdin);

    for(i=0; i<strlen(message); i++){
        for(j=0; j<strlen(key); j++){
            encrypted[i] = message[i]^key[j];
        }
    }

    printf("\nEncrypted message: ");
    for(i=0; i<strlen(message); i++){
        printf("%2x", encrypted[i]);
    }

    for(i=0; i<strlen(message); i++){
        for(j=0; j<strlen(key); j++){
            decrypted[i] = encrypted[i]^key[j];
        }
    }

    printf("\nDecrypted message: ");
    for(i=0; i<strlen(message); i++){
        printf("%c", decrypted[i]);
    }

    return 0;

}