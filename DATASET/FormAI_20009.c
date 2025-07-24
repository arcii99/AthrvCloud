//FormAI DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 128

char* encrypt(char* string, int key);

int main(){
    char message[MAX_WORD_LENGTH];
    int key;
    char choice = 'y';

    while(choice == 'y'){
        printf("Please enter a message to encrypt: ");
        fgets(message, MAX_WORD_LENGTH, stdin);
        printf("Please enter a key to encrypt with: ");
        scanf("%d", &key);

        char* encrypted_message = encrypt(message, key);
        printf("Your encrypted message is: %s\n", encrypted_message);

        printf("Do you want to encrypt another message? (y/n): ");
        getchar();
        scanf("%c", &choice);
    }

    return 0;
}

char* encrypt(char* string, int key){
    int length = strlen(string);
    char* encrypted_string = malloc(sizeof(char) * length);

    for(int i = 0; i < length; ++i){
        if(string[i] == '\n'){
            encrypted_string[i] = '\0';
            break;
        }
        else{
            encrypted_string[i] = string[i] + key;
        }
    }

    return encrypted_string;
}