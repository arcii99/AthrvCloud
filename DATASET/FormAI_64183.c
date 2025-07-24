//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to summarize text
void summarize(char* text, int length) {
    // Count number of sentences and words
    int sentences = 0, words = 0;
    for (int i = 0; i < length; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentences++;
        } else if (isspace(text[i])) {
            words++;
        }
    }

    // Calculate average sentence length and words per sentence
    float avg_sentence_length, words_per_sentence;
    if (sentences != 0) {
        avg_sentence_length = (float) length / sentences;
        words_per_sentence = (float) words / sentences;
    } else {
        avg_sentence_length = 0;
        words_per_sentence = 0;
    }

    // Print summary
    printf("Number of sentences: %d\n", sentences);
    printf("Number of words: %d\n", words);
    printf("Average sentence length: %.2f\n", avg_sentence_length);
    printf("Words per sentence: %.2f\n", words_per_sentence);
}

int main() {
    // Input text
    char text[] = "Ada Lovelace was an English mathematician and writer credited with being the first computer programmer. Lovelace was born in London on December 10, 1815, the daughter of the poet Lord Byron and his wife Annabella. She was trained in mathematics from a young age by her mother and by noted mathematicians such as Augustus De Morgan. In 1843, she translated an article on Babbage's analytical engine, adding her own notes, which contained what is now considered the first computer program. Lovelace was also a visionary, seeing the potential for computers to do more than just calculations and recognizing the importance of collaboration between man and machine.";

    int length = strlen(text);

    // Summarize text
    summarize(text, length);

    return 0;
}