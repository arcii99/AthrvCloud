//FormAI DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int spamCount = 0;

    printf("Enter your message: ");
    fgets(input, sizeof(input), stdin);

    char* words[] = {"offer", "limited time", "money back", "buy now"};
    int wordsCount = sizeof(words) / sizeof(words[0]);

    for(int i = 0; input[i] != '\0'; i++) {
        if(input[i] == ' ' || input[i] == '\n') {
            input[i] = '\0';

            for(int j = 0; j < wordsCount; j++) {
                if(strcmp(input, words[j]) == 0) {
                    spamCount++;
                    break;
                }
            }

            input[i] = ' ';
        }
    }

    printf("\nSpam count: %d\n", spamCount);

    if(spamCount == 0) {
        printf("This message is not spam.\n");
    } else {
        printf("This message is spam.\n");
    }

    return 0;
}