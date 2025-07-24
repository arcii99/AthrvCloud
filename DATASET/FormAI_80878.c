//FormAI DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include<stdio.h>
#include<string.h>

#define SPAM_LIMIT 5 // Maximum number of times a word can appear before it is treated as spam
#define MAX_WORDS 20 // Maximum number of unique words that can be stored

struct word_count {
    char word[20];
    int count;
};

int check_spam(char msg[], char spam_words[][20], int spam_limit) {
    int spam_count = 0;
    char *word = strtok(msg, " ");

    while(word != NULL) {
        for(int i=0; i<spam_limit; i++) {
            if(strcmp(word, spam_words[i]) == 0) {
                spam_count++;
            }
        }
        if(spam_count >= spam_limit) {
            return 1;
        }
        word = strtok(NULL, " ");
    }
    return 0;
}

void add_word(struct word_count words[], char new_word[]) {
    for(int i=0; i<MAX_WORDS; i++) {
        if(strcmp(words[i].word, "") == 0) {
            strcpy(words[i].word, new_word);
            words[i].count = 1;
            return;
        } else if(strcmp(words[i].word, new_word) == 0) {
            words[i].count++;
            return;
        }
    }
}

void print_results(struct word_count words[]) {
    printf("Unique words: \n");
    for(int i=0; i<MAX_WORDS; i++) {
        if(strcmp(words[i].word, "") != 0) {
            printf("%s - %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char spam_words[][20] = {"buy", "now", "free", "limited", "offer"};
    char msg[100];

    struct word_count words[MAX_WORDS];
    for(int i=0; i<MAX_WORDS; i++) {
        strcpy(words[i].word, "");
        words[i].count = 0;
    }

    printf("Enter a message: ");
    fgets(msg, 100, stdin);

    if(check_spam(msg, spam_words, SPAM_LIMIT)) {
        printf("This message appears to be spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    char *word = strtok(msg, " ");
    while(word != NULL) {
        add_word(words, word);
        word = strtok(NULL, " ");
    }

    print_results(words);

    return 0;
}