//FormAI DATASET v1.0 Category: Spam Detection System ; Style: realistic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SPAM_WORDS 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char *word;
    int count;
} SpamWord;

int is_spam(char *message);

int main()
{
    char message[MAX_MESSAGE_LENGTH];
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    if (is_spam(message)) {
        printf("This message contains spam.\n");
    } else {
        printf("This message does not contain spam.\n");
    }

    return 0;
}

int is_spam(char *message)
{
    const char *spam_words[MAX_SPAM_WORDS] = {
        "free",
        "money",
        "click",
        "offer",
        "credit",
        "sex",
        "win",
        "cash",
        "online",
        "signup"
    };

    SpamWord spam_words_with_count[MAX_SPAM_WORDS];
    int num_spam_words = 0;

    // initialize the spam_words_with_count array
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        spam_words_with_count[i].word = NULL;
        spam_words_with_count[i].count = 0;
    }

    // count occurrences of each spam word in the message
    char *token = strtok(message, " ");
    while (token != NULL) {
        // convert token to lowercase
        char *lowercase = token;
        while (*lowercase) {
            *lowercase = tolower(*lowercase);
            lowercase++;
        }

        for (int i = 0; i < MAX_SPAM_WORDS; i++) {
            if (strcmp(token, spam_words[i]) == 0) {
                // increase count for this word
                int found = 0;
                for (int j = 0; j < num_spam_words; j++) {
                    if (strcmp(token, spam_words_with_count[j].word) == 0) {
                        spam_words_with_count[j].count++;
                        found = 1;
                        break;
                    }
                }

                // add to list if not already present
                if (!found) {
                    spam_words_with_count[num_spam_words].word = token;
                    spam_words_with_count[num_spam_words].count = 1;
                    num_spam_words++;
                }

                break;
            }
        }

        token = strtok(NULL, " ");
    }

    // determine if message is spam based on the number of occurrences of each spam word
    int total_spam_count = 0;
    for (int i = 0; i < num_spam_words; i++) {
        total_spam_count += spam_words_with_count[i].count;
    }

    return total_spam_count >= 3;
}