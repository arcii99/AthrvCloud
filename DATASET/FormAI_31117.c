//FormAI DATASET v1.0 Category: Spam Detection System ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10
#define MAX_STR_LEN 200

char spam_words[MAX_SPAM_WORDS][MAX_STR_LEN] = {"viagra", "lottery", "free money", "cheap price"};
int spam_counter[MAX_SPAM_WORDS] = {0};

int is_spam(char *message) {
    int i, j;
    char temp[MAX_STR_LEN];

    // Convert message to lowercase
    strcpy(temp, message);
    for (i = 0; temp[i]; i++) {
        temp[i] = tolower(temp[i]);
    }

    // Check for spam words
    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        for (j = 0; spam_words[i][j]; j++) {
            if (temp[j] != spam_words[i][j]) {
                break;
            }
        }
        if (!spam_words[i][j] && (temp[j] == ' ' || temp[j] == '\n' || temp[j] == '\0')) {
            spam_counter[i]++;
            return 1;
        }
    }

    return 0;
}

int main() {
    char message[MAX_STR_LEN];
    int count = 0;

    while (1) {
        printf("Enter message: ");
        fgets(message, MAX_STR_LEN, stdin);

        if (is_spam(message)) {
            printf("SPAM detected!\n");
            count++;
        } else {
            printf("Not spam.\n");
        }

        if (count >= 3) {
            printf("Too many spam messages detected. Terminating program.\n");
            break;
        }
    }

    printf("Number of times spam words were detected:\n");
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        printf("%s: %d\n", spam_words[i], spam_counter[i]);
    }

    return 0;
}