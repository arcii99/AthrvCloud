//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>

int main(){
    int key;
    char message[100];
    
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    
    printf("Enter a key: ");
    scanf("%d", &key);
    
    for(int i=0; message[i] != '\0'; i++){
        char ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ((ch - 'a') + key) % 26 + 'a';
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ((ch - 'A') + key) % 26 + 'A';
        }
        message[i] = ch;
    }
    
    printf("Encrypted Message: %s", message);
    
    return 0;
}