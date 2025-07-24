//FormAI DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int i, j, count = 0;
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    message[strlen(message) - 1] = '\0';
  
    //check for excessive punctuation
    for(i = 0; i < strlen(message); i++) {
        if(message[i] == '!' || message[i] == '?' || message[i] == '.') {
            count++;
        }
    }
    if(count > 3) {
        printf("Your message contains excessive punctuation and may be spam.\n");
        return 0;
    }
    
    //check for all caps
    count = 0;
    for(i = 0; i < strlen(message); i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            count++;
        }
    }
    if(count > strlen(message)/2) {
        printf("Your message contains too many capital letters and may be spam.\n");
        return 0;
    }
  
    //check for repetitive characters
    count = 0;
    for(i = 0; i < strlen(message) - 1; i++) {
        if(message[i] == message[i+1]) {
            count++;
        }
    }
    if(count >= strlen(message)/4) {
        printf("Your message contains too many repetitive characters and may be spam.\n");
        return 0;
    }

    printf("Your message is not considered spam.\n");
    return 0;
}