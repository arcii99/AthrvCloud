//FormAI DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_SPAM_LENGTH 20

int main() {
    char spam_words[MAX_SPAM_WORDS][MAX_SPAM_LENGTH] = {"buy", "discount", "free", "money"};
    char input[100];
    int spam_count = 0;
    
    printf("*** SPAM DETECTION SYSTEM ***\n");
    printf("Enter your message:\n");
    fgets(input, 100, stdin);
    
    char *token = strtok(input, " .,\n");
    while (token != NULL) {
        for (int i = 0; i < MAX_SPAM_WORDS; i++) {
            if (strcmp(token, spam_words[i]) == 0) {
                spam_count++;
                break;
            }
        }
        token = strtok(NULL, " .,\n");
    }
    
    if (spam_count > 0) {
        printf("This message contains %d spam word(s).\n", spam_count);
        printf("Please refrain from using spam words.\n");
    } else {
        printf("This message is not spam.\n");
    }
    
    return 0;
}