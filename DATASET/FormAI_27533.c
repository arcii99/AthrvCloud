//FormAI DATASET v1.0 Category: Text Summarizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUMMARY_LEN 200

char* summarize(char* text) {
    char* cleaned_text = strdup(text); // duplicate input string
    // remove extra white spaces, tabs, and new line characters
    char* ptr = cleaned_text;
    for (int i = 0; i < strlen(cleaned_text); i++) {
        if (isspace(cleaned_text[i])) {
            ptr++;
            if (ptr != cleaned_text && isspace(ptr[-2])) {
                ptr--;
            }
        } else {
            *(ptr++) = cleaned_text[i];
        }
    }
    *ptr = '\0';
    // tokenize string into words
    char* word;
    char* summary = calloc(MAX_SUMMARY_LEN, sizeof(char));
    ptr = cleaned_text;
    while ((word = strsep(&ptr, " ")) != NULL) {
        if (strlen(summary) + strlen(word) <= MAX_SUMMARY_LEN - 1) {
            strcat(summary, word);
            strcat(summary, " ");
        } else {
            break;
        }
    }
    // remove extra spaces and punctuation marks
    ptr = summary;
    char* ptr2 = summary;
    while (*ptr != '\0') {
        if (!ispunct(*ptr) && !isspace(*ptr)) {
            *(ptr2++) = tolower(*ptr);
        } else if (ptr == summary || *(ptr - 1) != ' ') {
            *(ptr2++) = ' ';
        }
        ptr++;
    }
    *ptr2 = '\0';
    free(cleaned_text);
    return summary;
}

int main() {
    char text[] = "Welcome to this C Text Summarizer example program. This program takes in a piece of text as input and returns a summary of the text. The summary contains the first 200 characters of the original text, without any extra white spaces, tabs, or new line characters. Punctuation marks are replaced with spaces and all characters are lowercased. Try it out!";
    char* summary = summarize(text);
    printf("%s\n", summary);
    free(summary);
    return 0;
}