//FormAI DATASET v1.0 Category: Text Summarizer ; Style: creative
#include <stdio.h>
#include <string.h>

// function to check if a character is a punctuation mark
int is_punctuation_mark(char c) {
    return (c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?');
}

// function to check if a character is whitespace
int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

// function to remove trailing punctuation marks
void remove_trailing_punctuation_marks(char *str) {
    int len = strlen(str);
    while (len > 0 && is_punctuation_mark(str[len - 1])) {
        str[len - 1] = '\0';
        len--;
    }
}

// function to calculate the number of words in a string
int word_count(char *str) {
    int count = 0;
    int in_word = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (is_whitespace(str[i])) {
            if (in_word) {
                count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    if (in_word) {
        count++;
    }
    return count;
}

// function to calculate the number of sentences in a string
int sentence_count(char *str) {
    int count = 0;
    int in_sentence = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (is_punctuation_mark(str[i])) {
            if (in_sentence) {
                count++;
                in_sentence = 0;
            }
        } else {
            in_sentence = 1;
        }
    }
    if (in_sentence) {
        count++;
    }
    return count;
}

// function to remove extra whitespace from a string
void remove_extra_whitespace(char *str) {
    int len = strlen(str);
    int i;
    int j = 0;
    for (i = 0; i < len; i++) {
        if (is_whitespace(str[i])) {
            if (i > 0 && !is_punctuation_mark(str[i - 1]) && !is_punctuation_mark(str[i + 1])) {
                str[j++] = ' ';
            }
        } else {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// function to calculate the average length of a word in a string
float average_word_length(char *str) {
    int word_count = 0;
    int word_length_sum = 0;
    int in_word = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (is_whitespace(str[i])) {
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
            word_length_sum++;
        }
    }
    if (in_word) {
        word_count++;
    }
    return (float) word_length_sum / word_count;
}

// function to summarize a text
// returns a dynamically allocated string containing the summary
char* summarize(char *text, int max_sentences) {
    char *summary = (char*) malloc(strlen(text) * sizeof(char));
    int sentence_count = 0;
    int char_count = 0;
    int i;
    for (i = 0; i < strlen(text); i++) {
        summary[char_count++] = text[i];
        if (is_punctuation_mark(text[i])) {
            sentence_count++;
        }
        if (sentence_count >= max_sentences) {
            break;
        }
    }
    summary[char_count] = '\0';
    remove_trailing_punctuation_marks(summary);
    remove_extra_whitespace(summary);
    return summary;
}

// example usage of the text summarizer
int main() {
    char text[] = "The quick brown fox jumps over the lazy dog. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non odio in nisl venenatis dictum. Mauris accumsan hendrerit neque in malesuada. Fusce vulputate, lectus nec interdum vestibulum, lacus tellus efficitur enim, eget tristique lectus nisi eu nisi. Duis pulvinar venenatis erat et semper. Suspendisse sagittis, odio a sagittis auctor, ex massa viverra diam, ut sagittis quam massa luctus turpis. Ut placerat lectus a erat gravida, sed rhoncus lacus fringilla. Sed at diam sit amet erat luctus bibendum ut id odio.";
    int max_sentences = 3;
    char *summary = summarize(text, max_sentences);
    printf("Original text:\n%s\n", text);
    printf("Summary:\n%s\n", summary);
    printf("Word count: %d\n", word_count(text));
    printf("Sentence count: %d\n", sentence_count(text));
    printf("Average word length: %.2f\n", average_word_length(text));
    free(summary);
    return 0;
}