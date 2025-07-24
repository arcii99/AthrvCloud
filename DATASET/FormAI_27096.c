//FormAI DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdio.h>
#include <string.h>

// Function prototype
int isSpam(char *message);

int main() {
    char message[100];
    printf("Enter a message: ");
    fgets(message, 100, stdin);
 
    if(isSpam(message)) {
        printf("This message contains spam.\n");
    } else {
        printf("This message is valid.\n");
    }
    return 0;
}

int isSpam(char *message) {
    // List of spam words to check against
    char *spamWords[] = {"buy", "money", "prize", "winner", "lottery"};
    int numWords = sizeof(spamWords)/sizeof(spamWords[0]);

    // Base case: message has no more words
    if(message[0] == '\0') {
        return 0;
    }

    // Recursive case: check current word against list of spam words
    char word[20];
    int i = 0;
    while(message[i] != ' ' && message[i] != '\n') {
        word[i] = message[i];
        i++;
    }
    word[i] = '\0';
    for(int j=0; j<numWords; j++) {
        if(strcmp(word, spamWords[j]) == 0) {
            return 1;
        }
    }
    return isSpam(message+i+1);  // Check next word recursively
}