//FormAI DATASET v1.0 Category: Text Summarizer ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1000
#define MAX_SUMMARY_SIZE 100

// function to remove special characters from the text
void remove_special_chars(char *text) {
    int i, j;
    for (i = 0; text[i] != '\0'; ++i) {
        while (!((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') || text[i] == '\0')) {
            for (j = i; text[j] != '\0'; ++j) {
                text[j] = text[j + 1];
            }
            text[j] = '\0';
        }
    }
}

// function to convert text to lowercase
void convert_to_lowercase(char *text) {
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
        text[i] = tolower(text[i]);
    }
}

// function to find the most frequent word in the text
void find_most_frequent_word(char *text, char *summary) {
    char delim[] = " ";
    char *token;
    int count[MAX_TEXT_SIZE], i, j, words;

    // initialize count array to 0
    for (i = 0; i < MAX_TEXT_SIZE; ++i) {
        count[i] = 0;
    }

    // tokenize the text and count the number of occurrences of each word
    words = 0;
    token = strtok(text, delim);
    while (token != NULL) {
        ++words;
        for (i = 0; token[i] != '\0'; ++i) {
            token[i] = tolower(token[i]);
        }
        for (i = 0; i < words; ++i) {
            if (strcmp(token, summary[i]) == 0) {
                ++count[i];
                break;
            }
        }
        if (i == words) {
            strcpy(summary[i], token);
            ++count[i];
        }
        token = strtok(NULL, delim);
    }

    // find the word with the highest frequency count
    int max_count = -1, max_index = -1;
    for (i = 0; i < words; ++i) {
        if (count[i] > max_count) {
            max_count = count[i];
            max_index = i;
        }
    }

    // set summary to the most frequent word
    strcpy(summary[0], summary[max_index]);
}

int main() {
    char text[MAX_TEXT_SIZE], summary[MAX_SUMMARY_SIZE][MAX_TEXT_SIZE] = {0};

    // get user input for text
    printf("Enter text you want to summarize:\n");
    fgets(text, MAX_TEXT_SIZE, stdin);

    // remove special characters and convert text to lowercase
    remove_special_chars(text);
    convert_to_lowercase(text);

    // find the most frequent word in the text and set it as the summary
    find_most_frequent_word(text, summary);

    // print the summary
    printf("\nSummary:\n%s", summary[0]);

    return 0;
}