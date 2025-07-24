//FormAI DATASET v1.0 Category: Text Summarizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This function returns true if 'c' is a punctuation mark.
int isPunct(char c) {
    const char punct[] = {'.', ',', ';', ':', '!', '?', '-', '(', ')', '[', ']', '{', '}'};
    int i;
    for (i = 0; i < strlen(punct); i++) {
        if (c == punct[i]) {
            return 1;
        }
    }
    return 0;
}

// This function removes punctuation marks from the end of each word.
void removePunct(char* s) {
    size_t len = strlen(s);
    while (len > 0 && isPunct(s[len-1])) {
        s[--len] = '\0';
    }
}

// This function converts a string to lowercase.
void toLower(char* s) {
    int i;
    for (i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
}

// This function returns the length of the longest word in a string.
int maxWordLen(char* s) {
    int maxLen = 0, len = 0, i;
    char* ptr = s;

    while (*ptr) {
        if (!isspace(*ptr)) {
            len++;
        } else {
            if (len > maxLen) {
                maxLen = len;
            }
            len = 0;
        }
        ptr++;
    }

    if (len > maxLen) {
        maxLen = len;
    }

    return maxLen;
}

// This function tokenizes a string into an array of words.
char** tokenize(char* s, int* n) {
    int maxLen = maxWordLen(s);
    char* token;
    char** tokens = malloc(sizeof(char*) * 1000);
    int i = 0;

    token = strtok(s, " ");
    while (token != NULL) {
        removePunct(token);
        toLower(token);
        if (strlen(token) > maxLen) {
            token[maxLen] = '\0';
        }
        tokens[i++] = strdup(token);
        token = strtok(NULL, " ");
    }

    *n = i;
    return tokens;
}

// This function counts the occurrence of each word in an array of tokens.
void countWords(char** tokens, int n, int** count, char*** unique, int* uniqueCount) {
    int i, j;
    char** u = malloc(sizeof(char*) * n);
    int* c = malloc(sizeof(int) * n);
    int countIndex = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < countIndex; j++) {
            if (strcmp(tokens[i], u[j]) == 0) {
                c[j]++;
                break;
            }
        }
        if (j == countIndex) {
            u[countIndex] = tokens[i];
            c[countIndex++] = 1;
        }
    }

    *count = c;
    *unique = u;
    *uniqueCount = countIndex;
}

// This function sorts an array of words by their count in descending order.
void sortWords(char*** unique, int* count, int n) {
    int i, j, maxIndex;
    char* temp;

    for (i = 0; i < n; i++) {
        maxIndex = i;
        for (j = i+1; j < n; j++) {
            if (count[j] > count[maxIndex]) {
                maxIndex = j;
            }
        }
        temp = (*unique)[i];
        (*unique)[i] = (*unique)[maxIndex];
        (*unique)[maxIndex] = temp;
        temp = count[i];
        count[i] = count[maxIndex];
        count[maxIndex] = temp;
    }
}

// This function generates a summary of a text.
char* summarize(char* text) {
    char* summary = malloc(sizeof(char) * 1000);
    int i, j;
    int n, uniqueCount, sentenceCount = 0;
    char** tokens;
    char** unique;
    int* count;
    int totalWords = 0;

    // Count the number of sentences in the text.
    for (i = 0; text[i]; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentenceCount++;
        }
    }

    // Tokenize the text and count the occurrence of each word.
    tokens = tokenize(text, &n);
    countWords(tokens, n, &count, &unique, &uniqueCount);

    // Sort the words by their count in descending order.
    sortWords(&unique, count, uniqueCount);

    // Generate the summary by picking the most frequent words until the summary reaches the maximum number of sentences.
    for (i = 0; i < uniqueCount && sentenceCount > 0; i++) {
        for (j = 0; j < count[i] && sentenceCount > 0; j++) {
            strcat(summary, unique[i]);
            strcat(summary, " ");
            totalWords++;
            if (isPunct(summary[strlen(summary)-1])) {
                sentenceCount--;
            }
        }
    }

    // Add ellipses if there are more words than can fit in the summary.
    if (totalWords < n) {
        strcat(summary, "...");
    }

    // Free memory allocated for tokens and unique words.
    for (i = 0; i < n; i++) {
        free(tokens[i]);
    }
    free(tokens);
    for (i = 0; i < uniqueCount; i++) {
        free(unique[i]);
    }
    free(unique);
    free(count);

    return summary;
}

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog. Now is the time for all good men to come to the aid of their country. It was the best of times, it was the worst of times. In the beginning God created the heavens and the earth.";
    char* summary = summarize(text);
    printf("%s\n", summary);
    free(summary);
    return 0;
}