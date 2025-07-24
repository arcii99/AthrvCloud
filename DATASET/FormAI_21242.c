//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include<stdio.h>
#include<string.h>

void detect_spam(char message[]) {
    
    int spam_count = 0;
    int message_length = strlen(message);
    char* keywords[] = {"buy", "sale", "promotion", "offer", "discount"};
    
    for(int i = 0; i < message_length; i++) {
        
        if(message[i] == ' ') {
            
            for(int j = 0; j < sizeof(keywords)/sizeof(keywords[0]); j++) {
                
                if(strncmp(message+i+1, keywords[j], strlen(keywords[j])) == 0) {
                    spam_count++;
                    break;
                }
            }
        }
    }
    
    if(spam_count > 2) {
        printf("This message contains spam.\n");
    }
    else {
        printf("This message is safe.\n");
    }
}

int main() {
    
    char message1[] = "Buy our products and get a 50% discount!";
    char message2[] = "Hey, how's it going? Want to hang out later?";
    
    detect_spam(message1);
    detect_spam(message2);
    
    return 0;
}