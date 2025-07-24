//FormAI DATASET v1.0 Category: Text Summarizer ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 1000
#define MAX_LENGTH 200

void to_lower(char *);
int count_words(char *);
int count_sentences(char *);
int get_index(int, int, const int []);
void print_summary(char [][MAX_LENGTH], const int [], int);

int main() {
    char input[MAX_WORDS], sentences[MAX_SENTENCES][MAX_LENGTH];
    int index[MAX_SENTENCES], freq[MAX_WORDS], i, j, count, sentences_count, words_count;

    // Take input from user
    printf("Enter text to summarize:\n");
    fgets(input, MAX_WORDS, stdin);

    // Convert input to lowercase
    to_lower(input);

    // Split input into sentences
    sentences_count = count_sentences(input);
    j = 0;
    for (i = 0; i < sentences_count; i++) {
        count = 0;
        while (input[j] != '.' && input[j] != '\n') {
            sentences[i][count++] = input[j++];
        }
        sentences[i][count++] = input[j++];
        sentences[i][count] = '\0';
    }

    // Check frequency of each word
    words_count = count_words(input);
    j = 0;
    for (i = 0; i < words_count; i++) {
        count = 0;
        while (input[j] != ' ' && input[j] != '\n') {
            input[j++];
            count++;
        }

        // Ignore very short words
        if (count >= 3) {
            freq[i] = 1;
            for (j = i + 1; j < words_count; j++) {
                if (strcmp(input+i, input+j) == 0) {
                    freq[i]++;
                }
            }
        } else {
            freq[i] = 0;
        }
    }

    // Find index of most significant word in each sentence
    for (i = 0; i < sentences_count; i++) {
        index[i] = -1;
        count = 0;
        for (j = 0; sentences[i][j] != '\0'; j++) {
            if (isalpha(sentences[i][j]) || isdigit(sentences[i][j])) {
                count++;
            } else {
                if (count >= 3) {
                    int temp = get_index(j-count, count, freq);
                    if (temp > index[i]) {
                        index[i] = temp;
                    }
                }
                count = 0;
            }
        }
    }

    // Print summary
    printf("\nSummary:\n--------\n");
    print_summary(sentences, index, sentences_count);

    return 0;
}

// Convert a string to lowercase
void to_lower(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

// Count number of words in a string
int count_words(char *str) {
    int count = 0, i = 0;
    while (*str != '\0') {
        if (*str == ' ' || *str == '\n') {
            i = 0;
        } else if (i == 0) {
            i = 1;
            count++;
        }
        str++;
    }
    return count;
}

// Count number of sentences in a string
int count_sentences(char *str) {
    int count = 0, i = 0;
    while (*str != '\0') {
        if (*str == '.' || *str == '\n') {
            count++;
            i = 0;
        } else {
            i = 1;
        }
        str++;
    }
    return count;
}

// Get the index of the most significant word within a given range
int get_index(int start, int len, const int freq []) {
    int index = -1, count = 0, i;
    for (i = start; i < start + len; i++) {
        if (isalpha(freq[i]) && freq[i] > count) {
            index = i;
            count = freq[i];
        }
    }
    return index;
}

// Print out the summary based on the most significant word in each sentence
void print_summary(char sentences[MAX_SENTENCES][MAX_LENGTH], const int index [], int count) {
    int i;
    for (i = 0; i < count; i++) {
        if (index[i] >= 0) {
            printf("%s", sentences[i]);
        }
    }
}