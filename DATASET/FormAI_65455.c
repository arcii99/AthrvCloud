//FormAI DATASET v1.0 Category: Spam Detection System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

void checkSpam(char*);

int main() {
    char message[1000];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // remove newline character

    checkSpam(message);
    
    return 0;
}

void checkSpam(char* message) {
    char* spamWords[] = {"buy", "discount", "free", "offer"};
    int spamCount = 0;

    char* word = strtok(message, " ");
    while (word != NULL) {
        for (int i = 0; i < sizeof(spamWords) / sizeof(spamWords[0]); i++) {
            if (strcmp(word, spamWords[i]) == 0) {
                spamCount++;
            }
        }
        word = strtok(NULL, " ");
    }

    if (spamCount == 0) {
        printf("This is not a spam message.\n");
    } else {
        printf("WARNING: This message contains %d spam words.\n", spamCount);
    }
}