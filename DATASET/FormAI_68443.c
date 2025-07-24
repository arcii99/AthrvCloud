//FormAI DATASET v1.0 Category: Spam Detection System ; Style: protected
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUSPICIOUS 1
#define NOT_SUSPICIOUS 0
#define TRUE 1
#define FALSE 0

int is_spam(char *message) {
    int i, j, count = 0;
    char *keywords[] = {"win", "prize", "cash", "urgent", "limited time", "act now", "offer", "buy", "order", "enlargement", "viagra", "online pharmacy", "free trial", "refinance", "diet", "lose weight", "investment", "earn"};
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    int message_len = strlen(message);
    int max_word_len = 0, curr_word_len = 0;
  
    for(i = 0; i < message_len; i++) {
        if(message[i] == ' ') {
            if(curr_word_len > max_word_len) {
                max_word_len = curr_word_len;
            }
            curr_word_len = 0;
        } else {
            curr_word_len++;
        }
    }

    if(curr_word_len > max_word_len) {
        max_word_len = curr_word_len;
    }
  
    if(max_word_len > 20) {
        return SUSPICIOUS;
    }

    for(i = 0; i < num_keywords; i++) {
        count = 0;
        for(j = 0; j < message_len - strlen(keywords[i]); j++) {
            if(strncmp(message+j, keywords[i], strlen(keywords[i])) == 0) {
                count++;
            }
        }
        if(count >= 2) {
            return SUSPICIOUS;
        }
    }     

    return NOT_SUSPICIOUS;
}

int main() {
    char message[1000];

    printf("Enter the message: ");
    fgets(message, 1000, stdin);

    if(is_spam(message)) {
        printf("This message is likely spam\n");
    } else {
        printf("This message is not spam\n");
    }

    return 0;
}