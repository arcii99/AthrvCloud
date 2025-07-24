//FormAI DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h>

const int SPAM_THRESHOLD = 10;

int count_occurrences(char* str, char* substr) {
    int count = 0;
    while ((str = strstr(str, substr))) {
        count++;
        str++;
    }
    return count;
}

int main()
{
    char input[1000];
    printf("Enter message: ");
    fgets(input, 1000, stdin);

    // Check for excessive uppercase letters
    int message_len = strlen(input);
    int uppercase_count = 0;
    for (int i = 0; i < message_len; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            uppercase_count++;
        }
    }

    if (uppercase_count > message_len / 4) {
        printf("This message contains too many uppercase letters. Possible spam detected.\n");
        return 1;
    }

    // Check for excessive punctuation marks
    int punctuation_count = 0;
    char* punctuation_list = "!@#$%^&*()_+-=[]\\{}|;':\",./<>?";
    for (int i = 0; i < message_len; i++) {
        if (strchr(punctuation_list, input[i])) {
            punctuation_count++;
        }
    }
    if (punctuation_count > message_len / 4) {
        printf("This message contains too many punctuation marks. Possible spam detected.\n");
        return 1;
    }

    // Check for repeated words
    char* words[1000];
    int words_count = 0;
    char* token = strtok(input, " \t\n");
    while (token != NULL) {
        words[words_count] = token;
        words_count++;
        token = strtok(NULL, " \t\n");
    }
    for (int i = 0; i < words_count; i++) {
        int count = 0;
        for (int j = i+1; j < words_count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count++;
            }
        }
        if (count > 2) {
            printf("This message contains too many repeated words. Possible spam detected.\n");
            return 1;
        }
    }

    // Check for specific spam keywords
    char* spam_keywords[] = {"money", "sale", "free", "deal", "click", "subscribe", "sex", "win", "prize", "cash", "urgent", "offer", "now", "limited"};
    for (int i = 0; i < sizeof(spam_keywords) / sizeof(char*); i++) {
        char* keyword = spam_keywords[i];
        int count = count_occurrences(input, keyword);
        if (count >= SPAM_THRESHOLD) {
            printf("This message contains spam keywords. Possible spam detected.\n");
            return 1;
        }
    }

    printf("This message appears to be legitimate.\n");
    return 0;
}