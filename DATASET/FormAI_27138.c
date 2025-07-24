//FormAI DATASET v1.0 Category: Spam Detection System ; Style: realistic
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int i, spam = 0;

    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    char *words[] = {"viagra", "lottery", "inheritance", "prince", "million", "dollars"};
    int num_words = sizeof(words) / sizeof(words[0]);

    for (i = 0; i < num_words; i++) {
        if (strstr(message, words[i])) {
            spam++;
        }
    }

    if (spam > 0) {
        printf("\nWarning: Your message contains %d spam words. It may be marked as spam.\n", spam);
    } else {
        printf("\nNo spam detected. Your message is safe to send.\n");
    }

    return 0;
}