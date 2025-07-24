//FormAI DATASET v1.0 Category: Spam Detection System ; Style: complete
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int i, j, spam_count = 0;

    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    char spam_words[5][10] = {"buy", "win", "free", "click", "discount"};

    // Check if message contains any spam word
    for (i = 0; message[i] != '\0'; i++) {
        for (j = 0; j < 5; j++) {
            if (strstr(&message[i], spam_words[j]) == &message[i]) {
                spam_count++;
                break;
            }
        }
    }

    // Decide whether it's spam or not
    if (spam_count > 0) {
        printf("This message is spam.");
    } else {
        printf("This message is not spam.");
    }

    return 0;
}