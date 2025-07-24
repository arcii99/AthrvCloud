//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is a punctuation mark
int is_punctuation(char c) {
    return c == '.' || c == '!' || c == '?';
}

// Function that removes punctuation from a string
void remove_punctuation(char *str) {
    char *src = str, *dst = str;
    while (*src) {
        // Copy non-punctuation characters to destination string
        if (!is_punctuation(*src)) {
            *dst++ = *src;
        }
        src++;
    }
    // Terminate destination string with null character
    *dst = '\0';
}

// Function that returns the number of words in a string
int count_words(char *str) {
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function that returns the average word length in a string
double average_word_length(char *str) {
    int sum = 0, count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        sum += strlen(token);
        count++;
        token = strtok(NULL, " ");
    }
    return (double) sum / count;
}

// Shape-shifting function that summarizes text based on its characteristics
char *summarize(char *text) {
    remove_punctuation(text);
    int word_count = count_words(text);
    double avg_word_length = average_word_length(text);
    char *summary;
    if (word_count >= 50 && avg_word_length >= 6) {
        summary = "The text is long and contains many long words.";
    } else if (word_count >= 50 && avg_word_length < 6) {
        summary = "The text is long but contains mostly short words.";
    } else if (word_count < 50 && avg_word_length >= 6) {
        summary = "The text is short but contains many long words.";
    } else {
        summary = "The text is short and contains mostly short words.";
    }
    return summary;
}

int main() {
    char text[] = "This is an example of a piece of text that the summarizer program will analyze. The program will count the number of words in the text and calculate the average word length. Based on these characteristics, the program will shape-shift and provide a summary of the text.";
    char *summary = summarize(text);
    printf("%s", summary);
    return 0;
}