//FormAI DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, int key){
    for(int i=0;i<strlen(input);i++){
        if((int)input[i] >= 65 && (int)input[i] <= 90){
            input[i] = (char)((((int)input[i] + key - 65) % 26) + 65);
        }
        else if((int)input[i] >= 97 && (int)input[i] <= 122){
            input[i] = (char)((((int)input[i] + key - 97) % 26 ) + 97);
        }
    }
}

void decrypt(char *input, int key){
    for(int i=0;i<strlen(input);i++){
        if((int)input[i] >= 65 && (int)input[i] <= 90){
            input[i] = (char)((((int)input[i] - key - 65 + 26) % 26) + 65);
        }
        else if((int)input[i] >= 97 && (int)input[i] <= 122){
            input[i] = (char)((((int)input[i] - key - 97 + 26) % 26 ) + 97);
        }
    }
}

int main(){
    int key;
    char input[100];

    printf("Enter the key to encrypt: ");
    scanf("%d", &key);
    getchar(); // To clear the '\n' character from previous input

    printf("Enter the text to encrypt: ");
    fgets(input, 100, stdin);

    encrypt(input, key);

    printf("\nThe encrypted text is: %s", input);

    decrypt(input, key);

    printf("\nThe decrypted text is: %s", input);

    return 0;
}