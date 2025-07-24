//FormAI DATASET v1.0 Category: Encryption ; Style: happy
#include<stdio.h>
#include<string.h>

void happyEncryption(char message[], int key);

int main(){
    char message[100];
    int key;
    printf("Welcome to Happy Encryption!\n");
    printf("Enter a message you'd like to encrypt: ");
    gets(message);
    printf("Enter a key value for encryption: ");
    scanf("%d", &key);
    happyEncryption(message, key);
    return 0;
}

void happyEncryption(char message[], int key){
    int length = strlen(message);
    int i, letter;

    printf("\nOriginal Message: %s", message);
    printf("\nKey Value: %d", key);
    printf("\nEncrypted Message: ");
    for(i = 0; i < length; i++){
        letter = message[i];
        if(letter >= 97 && letter <= 122){ // lowercase letters
            letter = letter + key;
            if(letter > 122){
                letter = letter - 26;
            }
        } else if(letter >= 65 && letter <= 90){ // uppercase letters
            letter = letter + key;
            if(letter > 90){
                letter = letter - 26;
            }
        }

        printf("%c", letter);
    }
    printf("\nThank you for using Happy Encryption!");
}