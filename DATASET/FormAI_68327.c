//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

void detect_spam(char* message) {
    int i, j, spam_words = 0;
    char spam_list[5][10] = {"viagra", "lottery", "inheritance", "nigeria", "online"};
    char* token = strtok(message, " ");
    
    while (token != NULL) {
        for (i = 0; i < 5; i++) {
            if (strcmp(token, spam_list[i]) == 0) {
                spam_words++;
            }
        }
        token = strtok(NULL, " ");
    }

    if (spam_words > 0) {
        printf("Possible spam detected: %s\n", message);
    }
    else {
        printf("Message is not spam: %s\n", message);
    }
}

int main() {
    char message[100];

    printf("Enter a message to check for spam: ");
    fgets(message, 100, stdin);
    detect_spam(message);

    return 0;
}