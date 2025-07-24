//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <string.h>

void spamDetector(char *str) {
    char *spams[] = {"buy", "$$$", "limited time offer", "free"};
    int len = sizeof(spams)/sizeof(spams[0]);
    int count = 0;

    char *word = strtok(str, " ");
    while (word != NULL) {
        for (int i = 0; i < len; i++) {
            if (strcmp(word, spams[i]) == 0) {
                count++;
                printf("Warning: Spam Alert - word '%s' found!\n", word);
            }
        }
        word = strtok(NULL, " ");
    }
    if (count == 0) {
        printf(" Message is not spam.\n");
    }
    else {
        printf(" %d spam words detected!\n", count);
    }
}

int main() {
    char message[1000];
    printf("Enter message: ");
    fgets(message, 1000, stdin);
    spamDetector(message);
    return 0;
}