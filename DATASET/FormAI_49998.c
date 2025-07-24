//FormAI DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#define KEY 3  // The encryption key

int main() {
    char message[100], ch;
    int i;
    
    printf("Enter the message you want to encrypt: ");
    fgets(message, sizeof(message), stdin); // Read message from user input
    
    for(i = 0; message[i] != '\0'; i++) {
        ch = message[i];
        
        if(ch >= 'a' && ch <= 'z') { // Encrypt lowercase letters
            ch = ch + KEY;
            
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') { // Encrypt uppercase letters
            ch = ch + KEY;
            
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            
            message[i] = ch;
        }
    }
    
    printf("The encrypted message is: %s", message); // Print encrypted message
    
    return 0;
}