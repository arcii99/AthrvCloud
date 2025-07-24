//FormAI DATASET v1.0 Category: Spam Detection System ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define SPAM_LIMIT 3

int main() {
    int count = 0;
    char last_msg[100] = "";
    while (1) {
        char msg[100];
        printf("Enter your message: ");
        fgets(msg, 100, stdin);
        if (strcmp(msg, last_msg) == 0) {
            count++;
        } else {
            count = 0;
        }
        if (count >= SPAM_LIMIT) {
            printf("SPAM DETECTED: %s triggered the spam filter\n", msg);
            break;
        }
        strcpy(last_msg, msg);
    }
    return 0;
}