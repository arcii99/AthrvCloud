//FormAI DATASET v1.0 Category: Encryption ; Style: imaginative
#include<stdio.h>
#include<string.h>

char key[50] = "EncryptionIsFun";

char* encrypt(char *original_message){
    int length_of_message = strlen(original_message);
    int length_of_key = strlen(key);
    
    for(int i=0; i<length_of_message; i++){
        original_message[i] = original_message[i] ^ key[i%length_of_key];   
    }
    
    return original_message;
}

int main(){
    char message[50];
    printf("Enter a string: ");
    scanf("%s", message);
    printf("Original message: %s\n", message);
    
    char *encrypted_message = encrypt(message);
    printf("Encrypted message: %s\n", encrypted_message);
    
    return 0;
}