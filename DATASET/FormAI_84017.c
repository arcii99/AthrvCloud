//FormAI DATASET v1.0 Category: Spam Detection System ; Style: active
// SPAM DETECTION SYSTEM

#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000 // Maximum length of message
#define MIN_SPAM_WORDS 3 // Minimum number of spam words to trigger detection

char spam_words[10][15] = {"money", "inheritance", "lottery", "prize", "free", "won", "offer", "credit", "debt", "cash"};

int count_spam_words(char message[MAX_MSG_LENGTH]){
    /* This function takes a message and counts the number of
    spam words in it. It returns the count. */
    int count = 0;

    for (int i=0; i<10; i++) {
        char* word = spam_words[i];
        char* occurence = strstr(message, word);
        while (occurence != NULL) {
            count++;
            occurence = strstr(occurence+1, word);
        }
    }
    return count;
}

int main() {
    char message[MAX_MSG_LENGTH];
    printf("Enter the message:\n");
    fgets(message, MAX_MSG_LENGTH, stdin);

    int spam_count = count_spam_words(message);

    if (spam_count >= MIN_SPAM_WORDS) {
        printf("SPAM DETECTED! The message contains %d spam words.", spam_count);
    }
    else {
        printf("This message is not spam.");
    }
    return 0;
}