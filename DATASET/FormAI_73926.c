//FormAI DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define SPAM_THRESHOLD 5

int main() {
    char message[100];
    char spam_words[][20] = {"discount", "free", "win", "cash", "prize"};
    int spam_counter = 0;
    
    printf("Enter your message: ");
    fgets(message, 100, stdin);

    // check for spam words
    for(int i = 0; i < 5; i++) {
        if(strstr(message, spam_words[i])) {
            spam_counter++;
        }
    }

    // check if message is spam or not
    if(spam_counter >= SPAM_THRESHOLD) {
        printf("Your message contains spam words.\n");
    } else {
        printf("Your message is not spam.\n");
    }

    return 0;
}