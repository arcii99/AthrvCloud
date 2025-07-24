//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    int spam_count = 0;

    while(1) {
        printf("Enter a message: ");
        fgets(message, sizeof(message), stdin);

        if(strstr(message, "BUY NOW") != NULL || strstr(message, "DEAL ALERT") != NULL) {
            printf("SPAM DETECTED!!\n");
            spam_count++;
        }

        if(spam_count >= 3) {
            printf("WARNING: You have received multiple spam messages. Please take caution.\n");
        }
    }

    return 0;
}