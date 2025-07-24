//FormAI DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {

    char spamWords[8][20] = {"buy now", "limited time", "act fast", "cash prize", "discount", "one time offer", "click here", "outstanding deal"};

    char message[1000];
    printf("Enter message: ");
    scanf("%[^\n]s", message);

    int count = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == ' ') {
            count++;
        }
    }
    count++;

    char words[30][20];
    int index = 0;
    char* word = strtok(message, " ");
    while (word != NULL) {
        strcpy(words[index], word);
        index++;
        word = strtok(NULL, " ");
    }

    int spamCount = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 8; j++) {
            if (strcmp(words[i], spamWords[j]) == 0) {
                spamCount++;
            }
        }
    }

    if (((float)spamCount/count)*100 >= 20.0) {
        printf("\nMessage is spam!");
    } else {
        printf("\nMessage is not spam.");
    }

    return 0;
}