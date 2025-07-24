//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to tokenize the input text
char **tokenize(char *text, int *word_count) {
    char **words = NULL;
    char *token = strtok(text, " \t\n\r\f\v");
    *word_count = 0;

    while (token != NULL) {
        *word_count += 1;
        words = realloc(words, (*word_count) * sizeof(char *));
        words[*word_count - 1] = token;
        token = strtok(NULL, " \t\n\r\f\v");
    }

    return words;
}

// function to check if a character is a vowel
int is_vowel(char character) {
    char vowels[] = "aeiouAEIOU";
    int i;

    for (i = 0; i < strlen(vowels); i++) {
        if (vowels[i] == character) {
            return 1;
        }
    }

    return 0;
}

// function to calculate the Flesch-Kincaid readability score
float flesch_kincaid(char *text) {
    int syllable_count = 0, word_count = 0, sentence_count = 0, i, j;
    char **words;
    float grade_level;

    // split the text into words
    words = tokenize(text, &word_count);

    // loop through each word to count syllables
    for (i = 0; i < word_count; i++) {
        syllable_count = 0;

        for (j = 0; j < strlen(words[i]); j++) {
            if (is_vowel(words[i][j])) {
                if (j == 0) {
                    syllable_count += 1;
                } else if (!is_vowel(words[i][j - 1])) {
                    syllable_count += 1;
                }
            }
        }

        if (strlen(words[i]) > 2 && words[i][strlen(words[i]) - 2] == 'e' && !is_vowel(words[i][strlen(words[i]) - 1])) {
            syllable_count -= 1;
        }

        if (syllable_count == 0 && strlen(words[i]) > 0) {
            syllable_count = 1;
        }

        sentence_count = strlen(text) - strlen(strtok(text, ".!?")) + 1;
    }

    grade_level = 0.39 * (float)word_count / (float)sentence_count + 11.8 * (float)syllable_count / (float)word_count - 15.59;

    free(words);

    return grade_level;
}

int main() {
    char text[10000], summary[5000], *token;
    int i, j, k, word_count = 0, sentence_count = 0, summary_word_count = 0, summary_sentence_count = 0;
    float grade_level;
    char **sentences = NULL;

    // read the input text
    printf("Enter the text to be summarized:\n");
    fgets(text, sizeof(text), stdin);

    // split the text into sentences
    token = strtok(text, ".!?");

    while (token != NULL) {
        sentence_count += 1;
        sentences = realloc(sentences, sentence_count * sizeof(char *));
        sentences[sentence_count - 1] = token;
        token = strtok(NULL, ".!?");
    }

    // loop through each sentence and summarize it
    for (i = 0; i < sentence_count; i++) {
        char **words = tokenize(sentences[i], &word_count);
        int *syllable_counts = calloc(word_count, sizeof(int));
        int sentence_syllable_count = 0;

        // calculate the syllable count for each word
        for (j = 0; j < word_count; j++) {
            for (k = 0; k < strlen(words[j]); k++) {
                if (is_vowel(words[j][k])) {
                    if (k == 0) {
                        syllable_counts[j] += 1;
                    } else if (!is_vowel(words[j][k - 1])) {
                        syllable_counts[j] += 1;
                    }
                }
            }

            if (strlen(words[j]) > 2 && words[j][strlen(words[j]) - 2] == 'e' && !is_vowel(words[j][strlen(words[j]) - 1])) {
                syllable_counts[j] -= 1;
            }

            if (syllable_counts[j] == 0 && strlen(words[j]) > 0) {
                syllable_counts[j] = 1;
            }

            sentence_syllable_count += syllable_counts[j];
        }

        // calculate the Flesch-Kincaid grade level for the sentence
        grade_level = 0.39 * (float)word_count / (float)sentence_count + 11.8 * (float)sentence_syllable_count / (float)word_count - 15.59;

        // add the sentence to the summary if it meets the grade level threshold
        if (grade_level < 8.0 && summary_sentence_count < 5) {
            for (j = 0; j < word_count; j++) {
                if (strlen(words[j]) + summary_word_count < 80 && summary_sentence_count < 5) {
                    strcat(summary, words[j]);
                    strcat(summary, " ");
                    summary_word_count += strlen(words[j]) + 1;
                } else {
                    strcat(summary, " ");
                    summary_sentence_count += 1;
                    summary_word_count = 0;
                }
            }

            strcat(summary, ". ");
        }

        free(words);
        free(syllable_counts);
    }

    printf("\nSummary:\n%s\n", summary);

    free(sentences);

    return 0;
}