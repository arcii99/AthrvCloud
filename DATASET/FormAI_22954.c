//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int i, spam_count = 0;
    printf("Enter your message:\n");
    scanf("%[^\n]", message);
    char* words[100] = {"lottery", "free", "money", "cash", "bank account", "Nigerian prince", "rich", "riches", "earn", "investment", "secret", "won", "prize", "click", "offer", "insurance"};
    int len = sizeof(words)/sizeof(words[0]);
    char* temp_word;

    for (i = 0; i < len; i++) {
        temp_word = strtok(message, " ");
        while (temp_word != NULL) {
            if (strcmp(words[i], temp_word) == 0) {
                spam_count++;
                break;
            }
            temp_word = strtok(NULL, " ");
        }
    }

    if(spam_count > 0) {
        printf("Warning: This message may contain spam!\n");
    } else {
        printf("This message is safe to read and reply.\n");
    }

    return 0;
}