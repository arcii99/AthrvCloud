//FormAI DATASET v1.0 Category: Modern Encryption ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

char* encrypt(char* str) {
    int len = strlen(str);
    char* encrypted_str = (char*)malloc((len+1)*sizeof(char));    // allocating memory for encrypted string
    
    for(int i=0; i<len; i++) {
        encrypted_str[i] = str[i] + 3;    // adding 3 to each character
    }
    
    encrypted_str[len] = '\0';    // setting null character
    
    return encrypted_str;    // returning encrypted string
}

char* decrypt(char* encrypted_str) {
    int len = strlen(encrypted_str);
    char* decrypted_str = (char*)malloc((len+1)*sizeof(char));    // allocating memory for decrypted string
    
    for(int i=0; i<len; i++) {
        decrypted_str[i] = encrypted_str[i] - 3;    // subtracting 3 from each character
    }
    
    decrypted_str[len] = '\0';    // setting null character
    
    return decrypted_str;    // returning decrypted string
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0';    // removing newline character
    
    char* encrypted_str = encrypt(str);
    printf("\nEncrypted string: %s", encrypted_str);
    
    char* decrypted_str = decrypt(encrypted_str);
    printf("\nDecrypted string: %s", decrypted_str);
    
    free(encrypted_str);    // freeing memory allocated to encrypted string
    free(decrypted_str);    // freeing memory allocated to decrypted string
    
    return 0;
}