//FormAI DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    printf("Enter the message: ");
    fgets(message, 1000, stdin); 

    int count = 0;
    char *word = strtok(message, " ");
    while (word != NULL) {
        if (strcmp(word, "spam") == 0 || strcmp(word, "SPAM") == 0) {
            count++;
        }
        word = strtok(NULL, " ");
    }

    if (count >= 3) {
        printf("This message may be spam.\n");
    } else {
        printf("This message is not spam.\n");
    }
    return 0;
}