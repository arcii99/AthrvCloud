//FormAI DATASET v1.0 Category: modern Encryption ; Style: content
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1000   // maximum length of string that can be encrypted

char* encrypt(char* str, int key){
    char* encrypted_str = (char*)malloc(MAX_LEN*sizeof(char));   // to store encrypted string
    int str_len = strlen(str);   // length of string to be encrypted
    for(int i=0; i<str_len; i++){
        char ch = str[i];
        if(ch >= 'A' && ch <= 'Z'){   // if uppercase letter
            encrypted_str[i] = ((((ch-'A') + key) % 26) + 'A') ;  // encrypt using Caesar Cipher
        }
        else if(ch >= 'a' && ch <= 'z'){   // if lowercase letter
            encrypted_str[i] = ((((ch-'a') + key) % 26) + 'a') ;  // encrypt using Caesar Cipher
        }
        else{   // if non-alphabetic character
            encrypted_str[i] = ch;
        }
    }
    encrypted_str[str_len] = '\0';   // add null character at the end of string to mark end of string
    return encrypted_str;
}

int main(){
    char str[MAX_LEN];   // to store string to be encrypted
    int key;   // key used for encryption
    printf("Enter the string to be encrypted: ");
    scanf("%[^\n]s", str);   // read the input string
    printf("Enter the key for encryption: ");
    scanf("%d", &key);   // read the encryption key
    char* encrypted_str = encrypt(str, key);   // call the encrypt function
    printf("Encrypted string: %s\n", encrypted_str);
    free(encrypted_str);   // deallocate memory used for encrypted string
    return 0;
}