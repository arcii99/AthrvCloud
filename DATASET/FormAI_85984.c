//FormAI DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    
    int spam_count = 0;
    char* spam_words[] = {"free", "money-back guarantee", "lottery", "investment", "earn money fast", "limited time offer", "click here", "weight loss", "online pharmacy", "dating website"};
    
    // Check for spam words in the message
    for(int i=0; i<10; i++) {
        if(strstr(message, spam_words[i]) != NULL) {
            spam_count++;
        }
    }
    
    // Check for excessive use of capital letters
    int capital_count = 0;
    for(int i=0; i<strlen(message); i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            capital_count++;
        }
    }
    
    // Check if the message is all caps
    int all_caps = 1;
    for(int i=0; i<strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            all_caps = 0;
            break;
        }
    }
    
    // Determine if the message is spam or not
    if(spam_count >= 2 || capital_count > strlen(message)/4 || all_caps) {
        printf("This message is likely spam.\n");
    } else {
        printf("This message is not spam.\n");
    }
    
    return 0;
}