//FormAI DATASET v1.0 Category: Modern Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
    char message[1000];
    int key, i;
    
    printf("Enter the message to be encoded: ");
    scanf("%s", message);
    printf("Enter the key: ");
    scanf("%d", &key);
    
    // encoding algorithm
    for (i = 0; i < strlen(message); i++) {
        message[i] = (message[i] + key) % 128;
    }
    
    printf("Encoded message: %s\n", message);
    printf("Key: %d\n", key);
    
    return 0;
}