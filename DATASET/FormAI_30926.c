//FormAI DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check for spam keywords
int is_spam(char *message) {
    int i, n = strlen(message);
    char spam_keywords[][10] = {"buy", "viagra", "discount", "lottery", "cash"};
    for (i = 0; i < 5; i++) {
        if (strstr(message, spam_keywords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    char message[100];
    int spam_count = 0, i = 0;
    while (i++ < 5) {
        printf("Enter message #%d: ", i);
        fgets(message, 100, stdin);
        if (is_spam(message)) {
            printf("This message is spam!\n");
            spam_count++;
        } else {
            printf("This message is not spam.\n");
        }
    }
    printf("%d of the %d messages entered were detected as spam.\n", spam_count, i-1);
    return 0;
}