//FormAI DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <ctype.h>

int main() {
    char message[1000];
    int key;
    
    printf("Enter message: ");
    fgets(message, 1000, stdin);
    
    printf("Enter encryption key: ");
    scanf("%d", &key);
    
    // Apply encryption
    for(int i = 0; message[i] != '\0'; i++) {
        if(isalpha(message[i])) {
            int shift = key % 26;
            if(isupper(message[i])) {
                message[i] = ((message[i] - 'A' + shift) % 26) + 'A';
            } else {
                message[i] = ((message[i] - 'a' + shift) % 26) + 'a';
            }
        }
    }
    
    printf("Encrypted message: %s", message);
    
    return 0;
}