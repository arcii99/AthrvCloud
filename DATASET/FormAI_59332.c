//FormAI DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int is_spam(char *msg) {
    const char *spam[] = {"buy", "cheap", "viagra", "click here"};
    const int size = sizeof(spam)/sizeof(spam[0]);
    for (int i = 0; i < size; i++) {
        if (strstr(msg, spam[i])) {
            printf("SPAM ALERT: %s\n", spam[i]);
            return 1;
        }
    }
    return 0;
}

int main() {
    char msg[100];
    printf("Enter your message: ");
    fgets(msg, sizeof(msg), stdin);
    if (!is_spam(msg)) {
        printf("No spam detected.\n");
    }
    return 0;
}