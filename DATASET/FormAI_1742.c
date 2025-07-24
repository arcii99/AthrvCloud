//FormAI DATASET v1.0 Category: Encryption ; Style: grateful
#include<stdio.h> 

char *CaesarCipher(char *message, int key){ 
    int i; 
    char letter; 
    for(i=0;message[i]!='\0';i++){
        letter = message[i];
        if(letter >= 'A' && letter <= 'Z'){
            letter = letter + key;
            if(letter > 'Z'){
                letter = letter - 'Z' + 'A' - 1;
            }
            message[i] = letter;
        }
        else if(letter >= 'a' && letter <= 'z'){
            letter = letter + key;
            if(letter > 'z'){
                letter = letter - 'z' + 'a' - 1;
            }
            message[i] = letter;
        }
    } 
    return message; 
} 

int main() {
    int key;
    char message[100];
    printf("Enter the message: ");
    gets(message);
    printf("Enter the key: ");
    scanf("%d", &key);
    printf("Original message: %s\n", message);
    char *encrypted_message = CaesarCipher(message, key);
    printf("Encrypted message: %s\n", encrypted_message);
    char *decrypted_message = CaesarCipher(encrypted_message, 26-key);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}