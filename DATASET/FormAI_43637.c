//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Romeo and Juliet
/* Romeo and Juliet Encryption */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[100];
    char secret_message[100];
    int key = 5;

    printf("Juliet: 'Romeo, can you encrypt our secret message?'\n");
    printf("Romeo: 'Of course, my love. Give me the message.'\n");

    printf("Juliet: 'The message is: '");
    fgets(message, sizeof(message), stdin);

    // Encrypting the message
    for(int i=0; i<strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            secret_message[i] = (((message[i] - 'a') + key) % 26) + 'a'; // Shifts the character by key value
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            secret_message[i] = (((message[i] - 'A') + key) % 26) + 'A'; // Shifts the character by key value
        }
        else {
            secret_message[i] = message[i];
        }
    }

    printf("Romeo: 'Here's your encrypted message: %s'\n", secret_message);

    printf("Juliet: 'Thank you, my Romeo. How do we decrypt it?'\n");
    printf("Romeo: 'We can decrypt it by shifting the letters back by %d.'\n", key);

    // Decrypting the message
    for(int i=0; i<strlen(secret_message); i++) {
        if(secret_message[i] >= 'a' && secret_message[i] <= 'z') {
            message[i] = (((secret_message[i] - 'a') - key + 26) % 26) + 'a'; // Shifts the character back by key value
        }
        else if(secret_message[i] >= 'A' && secret_message[i] <= 'Z') {
            message[i] = (((secret_message[i] - 'A') - key + 26) % 26) + 'A'; // Shifts the character back by key value
        }
        else {
            message[i] = secret_message[i];
        }
    }

    printf("Juliet: 'Oh, I see. So, the decrypted message is: %s'\n", message);
    printf("Romeo: 'Yes, my love. Our secret message is safe and secure.'\n");

    return 0;
}