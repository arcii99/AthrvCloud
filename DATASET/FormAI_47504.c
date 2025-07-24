//FormAI DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_MESSAGE_LEN 100

char spam_words[MAX_SPAM_WORDS][20] = {"buy", "free", "prize", "limited", "offer", 
                                       "now", "cash", "click", "discount", "save"};

int check_spam_word(char* word) {
    for(int i = 0; i < MAX_SPAM_WORDS; i++) {
        if(strcmp(word, spam_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void lower_string(char *str) {
    for(int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char message[MAX_MESSAGE_LEN];
    char temp_word[20];
    int is_spam = 0, num_words = 0;
    
    printf("Enter the message: ");
    fgets(message, MAX_MESSAGE_LEN, stdin);
    lower_string(message);

    for(int i = 0; i < strlen(message); i++) {
        if(message[i] == ' ' || message[i] == '\n') {
            temp_word[num_words] = '\0';
            if(check_spam_word(temp_word)) {
                is_spam = 1;
                break;
            }
            num_words = 0;
        } else {
            temp_word[num_words++] = message[i];
        }
    }

    if(is_spam) {
        printf("The message contains spam words.");
    } else {
        printf("The message is not spam.");
    }

    return 0;
}