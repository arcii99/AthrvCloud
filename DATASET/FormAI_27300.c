//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000          // Maximum length of input string
#define MAX_SENTENCES 100        // Maximum number of sentences
#define MAX_SUMMARY_LENGTH 500   // Maximum length of summary string
#define MAX_WORD_LENGTH 50       // Maximum length of a word

// Function to split input text into sentences
int sentence_splitter(char input_text[], char sentences[][MAX_LENGTH]) {
    int num_sentences = 0;
    char *sentence = strtok(input_text, ".?!");

    while (sentence != NULL) {
        strcpy(sentences[num_sentences], sentence);    // Copy sentence to sentences array
        num_sentences++;                               // Increment number of sentences
        sentence = strtok(NULL, ".?!");                 // Go to next sentence
    }

    return num_sentences;
}

// Function to split a sentence into words
int word_splitter(char sentence[], char words[][MAX_WORD_LENGTH]) {
    int num_words = 0;
    char *word = strtok(sentence, " \t\n");

    while (word != NULL) {
        strcpy(words[num_words], word);     // Copy word to words array
        num_words++;                        // Increment number of words
        word = strtok(NULL, " \t\n");       // Go to next word
    }

    return num_words;
}

// Function to calculate the importance score of a sentence
int calculate_score(char sentence[], char keywords[][MAX_WORD_LENGTH], int num_keywords) {
    int score = 0;
    char lower_sentence[MAX_LENGTH];
    char lower_keyword[MAX_WORD_LENGTH];
    int i, j;

    // Convert sentence and keywords to lowercase
    for (i = 0; i < strlen(sentence); i++) {
        lower_sentence[i] = tolower(sentence[i]);
    }
    lower_sentence[i] = '\0';
    for (i = 0; i < num_keywords; i++) {
        for (j = 0; j < strlen(keywords[i]); j++) {
            lower_keyword[j] = tolower(keywords[i][j]);
        }
        lower_keyword[j] = '\0';

        // If keyword is present in sentence, increment score
        if (strstr(lower_sentence, lower_keyword) != NULL) {
            score++;
        }
    }

    return score;
}

// Function to generate summary using input text and keywords
void generate_summary(char input_text[], char keywords[][MAX_WORD_LENGTH], int num_keywords, char summary[]) {
    char sentences[MAX_SENTENCES][MAX_LENGTH];    // Array to store sentences
    char words[MAX_LENGTH][MAX_WORD_LENGTH];      // Array to store words in a sentence
    int sentence_scores[MAX_SENTENCES];           // Array to store importance scores of sentences
    int num_sentences, num_words, i, j, k, max_score, max_index;
    int summary_length = 0;

    num_sentences = sentence_splitter(input_text, sentences);   // Split input text into sentences

    // Calculate importance score for each sentence
    for (i = 0; i < num_sentences; i++) {
        sentence_scores[i] = calculate_score(sentences[i], keywords, num_keywords);
    }

    // Generate summary by selecting most important sentences
    while (summary_length <= MAX_SUMMARY_LENGTH && num_sentences > 0) {
        max_score = -1;
        max_index = -1;

        // Find sentence with maximum score
        for (i = 0; i < num_sentences; i++) {
            if (sentence_scores[i] > max_score) {
                max_score = sentence_scores[i];
                max_index = i;
            }
        }

        // Add sentence to summary
        num_words = word_splitter(sentences[max_index], words);
        for (j = 0; j < num_words; j++) {
            strcat(summary, words[j]);
            strcat(summary, " ");
            summary_length += strlen(words[j]) + 1;
        }
        strcat(summary, "\n");
        summary_length++;

        // Remove selected sentence from sentences and scores array
        for (k = max_index; k < num_sentences-1; k++) {
            strcpy(sentences[k], sentences[k+1]);
            sentence_scores[k] = sentence_scores[k+1];
        }
        num_sentences--;
    }
}

int main() {
    char input_text[MAX_LENGTH] = "In C programming, functions are the building blocks of any application. They are used to group related statements together to perform a specific task. The syntax for defining a function in C is as follows: return_type function_name(type1 arg1, type2 arg2, ...) { statement(s); } To call a function, you simply pass the required parameters along with the function name. In this way, you can modularize your application and make it easier to maintain and debug.";
    char keywords[][MAX_WORD_LENGTH] = {"function", "C programming", "syntax"};
    int num_keywords = 3;
    char summary[MAX_SUMMARY_LENGTH] = "";

    generate_summary(input_text, keywords, num_keywords, summary);

    printf("Input Text:\n%s\n\n", input_text);
    printf("Keywords:\n");
    for (int i = 0; i < num_keywords; i++) {
        printf("%s ", keywords[i]);
    }
    printf("\n\n");
    printf("Summary:\n%s", summary);

    return 0;
}