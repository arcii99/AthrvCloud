//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>

int main() {
    char *message = "Vi4nnaS8WckyVHJlZg=="; // Encrypted message
    int key = 5; // Decryption key
    
    // Decrypting the message
    for(int i = 0; message[i] != '\0'; ++i) {
        message[i] = message[i] - key;
    }
    
    // Checking for spam keywords
    char *keywords[] = {"money", "win", "free", "prize"};
    int matches = 0;
    
    for(int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i) {
        if(strstr(message, keywords[i]) != NULL) {
            ++matches;
        }
    }
    
    // Determining if message is spam or not
    if(matches > 0) {
        printf("SPAM DETECTED!!!\n");
    } else {
        printf("Message is not spam.\n");
    }
    
    return 0;
}