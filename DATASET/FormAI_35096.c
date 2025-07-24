//FormAI DATASET v1.0 Category: Encryption ; Style: authentic
#include<stdio.h>
#include<string.h>

//Function to encrypt the plaintext
void encrypt(char plaintext[], int key){
    int i;
    for(i=0; i<strlen(plaintext); i++){
        if(plaintext[i]>='a' && plaintext[i]<='z'){
            plaintext[i] = (plaintext[i]+key-'a')%26 + 'a';
        }
        else if(plaintext[i]>='A' && plaintext[i]<='Z'){
            plaintext[i] = (plaintext[i]+key-'A')%26 + 'A';
        }
    }
}

//Function to decrypt the ciphertext
void decrypt(char ciphertext[], int key){
    int i;
    for(i=0; i<strlen(ciphertext); i++){
        if(ciphertext[i]>='a' && ciphertext[i]<='z'){
            ciphertext[i] = (ciphertext[i]-key-'a'+26)%26 + 'a';
        }
        else if(ciphertext[i]>='A' && ciphertext[i]<='Z'){
            ciphertext[i] = (ciphertext[i]-key-'A'+26)%26 + 'A';
        }
    }
}

int main(){
    char plaintext[100], ciphertext[100];
    int key;

    printf("Enter a plaintext to encrypt: ");
    scanf("%[^\n]s", plaintext); //Read plaintext from user

    printf("Enter a key (integer): ");
    scanf("%d", &key); //Read key from user

    //Encrypting the plaintext using the key
    encrypt(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);

    //Decrypting the ciphertext using the key
    decrypt(plaintext, key);
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}