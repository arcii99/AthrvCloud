//FormAI DATASET v1.0 Category: Spam Detection System ; Style: rigorous
#include <stdio.h>
#include <string.h>

#define SPAM_KEYWORDS_COUNT 4
#define SPAM_THRESHOLD 0.7

char *spam_keywords[SPAM_KEYWORDS_COUNT] = {"cash", "winner", "money", "lottery"};

int main() {
    char message[1000];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    
    int i, j, keywords_count = 0;
    double keyword_match_ratio = 0.0;
    
    for (i = 0; i < strlen(message); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + 32;
        }
    }
    
    for (i = 0; i < SPAM_KEYWORDS_COUNT; i++) {
        char *keyword = spam_keywords[i];
        int keyword_length = strlen(keyword);
        for (j = 0; j < strlen(message); j++) {
            if (message[j] == keyword[0]) {
                char substring[keyword_length+1];
                strncpy(substring, message+j, keyword_length);
                substring[keyword_length] = '\0';
                if (strcmp(substring, keyword) == 0) {
                    keywords_count++;
                }
            }
        }
    }
    
    keyword_match_ratio = (double)keywords_count / (double)strlen(message);
    
    if (keyword_match_ratio > SPAM_THRESHOLD) {
        printf("This message is likely a spam.\n");
    } else {
        printf("This message is not a spam.\n");
    }
    
    return 0;
}