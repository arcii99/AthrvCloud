//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
    int i, j, k;
    char str[1000], encrypted[1000], decrypted[1000], key[50];
    
    // initialize key
    strcpy(key, "QWERTYUIOPASDFGHJKLZXCVBNMqazxswedcvfrtgbnhyujmkiolp1234567890!@#$%^&*()");
    
    printf("Enter the message to encrypt: ");
    gets(str);
    
    // encryption process
    for(i = 0; i < strlen(str); i++) {
        for(j = 0; j < strlen(str); j++) {
            if(str[i] == key[j]) {
                encrypted[i] = key[(j+10)%strlen(key)];
                break;
            }
            if(str[i] == ' ') {
                encrypted[i] = ' ';
                break;
            }
        }
    }
    encrypted[strlen(str)] = '\0';
    
    printf("Encrypted Message: %s\n", encrypted);
    
    // decryption process
    for(i = 0; i < strlen(encrypted); i++) {
        for(j = 0; j < strlen(key); j++) {
            if(encrypted[i] == key[j]) {
                decrypted[i] = key[(j+strlen(key)-10)%strlen(key)];
                break;
            }
            if(encrypted[i] == ' ') {
                decrypted[i] = ' ';
                break;
            }
        }
    }
    decrypted[strlen(encrypted)] = '\0';
    
    printf("Decrypted Message: %s\n", decrypted);
    
    return 0;
}