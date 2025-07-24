//FormAI DATASET v1.0 Category: Spam Detection System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    int spam = 0;
    // Checking for known spam words
    char *spam_words[] = {"free", "cash", "get rich", "click now", "limited offer"};
    for (int i = 0; i < 5; i++) {
        if (strstr(message, spam_words[i])) {
            spam = 1;
            break;
        }
    }
    // If message is not spam, check for apocalyptic language
    if (!spam) {
        int apocalyptic = 0;
        char *apocalyptic_words[] = {"zombie", "apocalypse", "survive", "end of the world", "cannibal"};
        for (int i = 0; i < 5; i++) {
            if (strstr(message, apocalyptic_words[i])) {
                apocalyptic = 1;
                break;
            }
        }
        if (apocalyptic) {
            printf("This message contains apocalyptic language. Proceed with caution.\n");
        } else {
            printf("This message seems normal. Carry on.\n");
        }
    } else {
        printf("This message is spam. Ignore it.\n");
    }
    return 0;
}