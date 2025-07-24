//FormAI DATASET v1.0 Category: Spam Detection System ; Style: secure
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_LINE_LENGTH 1000

char *spam_words[MAX_SPAM_WORDS] = {"buy", "free", "discount", "money", "cash", "earn", "income", "win", "prize", "limited time offer"};

int is_spam(char *line) {
    char *token = strtok(line, " ");
    while (token != NULL) {
        for (int i = 0; i < MAX_SPAM_WORDS; i++) {
            if (strcmp(token, spam_words[i]) == 0) {
                return 1;
            }
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

int main() {
    char line[MAX_LINE_LENGTH];
    printf("Enter a line of text:\n");
    fgets(line, MAX_LINE_LENGTH, stdin);
    if (is_spam(line)) {
        printf("This line contains spam.\n");
    } else {
        printf("This line does not contain spam.\n");
    }
    return 0;
}