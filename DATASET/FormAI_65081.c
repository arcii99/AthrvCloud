//FormAI DATASET v1.0 Category: Text Summarizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_TEXT_LENGTH 50000
#define MAX_SUMMARY_LENGTH 10000

// Function to check if a character is a punctuation mark
int is_punctuation(char c) {
    char punctuation_marks[] = {'.', ',', ';', ':', '?', '!', '-'};
    int num_punctuation_marks = (int)strlen(punctuation_marks);
    for (int i = 0; i < num_punctuation_marks; i++) {
        if (c == punctuation_marks[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to split text into separate sentences
int split_sentences(char *text, char sentences[MAX_SENTENCES][MAX_TEXT_LENGTH]) {
    int num_sentences = 0;
    char *token;
    char *prev_token;
    token = strtok(text, ".");
    prev_token = token;
    while (token != NULL) {
        if (num_sentences >= MAX_SENTENCES) {
            break;
        }
        // Check if the token is a valid sentence
        if (strlen(token) > 1 && (token[1] == ' ' || is_punctuation(token[1]))) {
            strcpy(sentences[num_sentences], prev_token);
            strcat(sentences[num_sentences], ".");
            num_sentences++;
            prev_token = token;
        }
        token = strtok(NULL, ".");
    }
    strcpy(sentences[num_sentences], prev_token);
    strcat(sentences[num_sentences], ".");
    num_sentences++;
    return num_sentences;
}

// Function to count the number of occurrences of a word in a sentence
int count_word_occurrences(char *word, char *sentence) {
    char *token;
    int num_occurrences = 0;
    char copy_sentence[MAX_TEXT_LENGTH];
    strcpy(copy_sentence, sentence);
    token = strtok(copy_sentence, " ");
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            num_occurrences++;
        }
        token = strtok(NULL, " ");
    }
    return num_occurrences;
}

// Function to summarize text
void summarize_text(char *text, char summary[MAX_SUMMARY_LENGTH], int summary_length) {
    char sentences[MAX_SENTENCES][MAX_TEXT_LENGTH];
    char words[MAX_TEXT_LENGTH][MAX_TEXT_LENGTH];
    int num_sentences = split_sentences(text, sentences);
    int num_words = 0;
    for (int i = 0; i < num_sentences; i++) {
        char *token;
        token = strtok(sentences[i], " ");
        while (token != NULL) {
            int is_duplicate = 0;
            for (int j = 0; j < num_words; j++) {
                if (strcmp(token, words[j]) == 0) {
                    is_duplicate = 1;
                    break;
                }
            }
            if (!is_duplicate) {
                strcpy(words[num_words], token);
                num_words++;
            }
            token = strtok(NULL, " ");
        }
    }
    char top_words[num_words][MAX_TEXT_LENGTH];
    int top_word_counts[num_words];
    for (int i = 0; i < num_words; i++) {
        strcpy(top_words[i], words[i]);
        top_word_counts[i] = 0;
    }
    for (int i = 0; i < num_sentences; i++) {
        for (int j = 0; j < num_words; j++) {
            int num_occurrences = count_word_occurrences(top_words[j], sentences[i]);
            top_word_counts[j] += num_occurrences;
        }
    }
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (top_word_counts[j] > top_word_counts[i]) {
                int temp_count = top_word_counts[i];
                top_word_counts[i] = top_word_counts[j];
                top_word_counts[j] = temp_count;
                char temp_word[MAX_TEXT_LENGTH];
                strcpy(temp_word, top_words[i]);
                strcpy(top_words[i], top_words[j]);
                strcpy(top_words[j], temp_word);
            }
        }
    }
    int num_summary_sentences = summary_length;
    if (num_summary_sentences > num_sentences) {
        num_summary_sentences = num_sentences;
    }
    for (int i = 0; i < num_summary_sentences; i++) {
        int has_top_word = 0;
        for (int j = 0; j < num_words; j++) {
            if (count_word_occurrences(top_words[j], sentences[i]) > 0) {
                has_top_word = 1;
                break;
            }
        }
        if (has_top_word) {
            strcat(summary, sentences[i]);
            strcat(summary, " ");
        }
    }
}

int main() {
    char text[MAX_TEXT_LENGTH] = "In computer science, artificial intelligence (AI), sometimes called machine intelligence, is intelligence demonstrated by machines, in contrast to the natural intelligence displayed by humans. Colloquially, the term artificial intelligence is used to describe machines and algorithms that are capable of performing tasks that typically require human-level intelligence, such as visual perception, speech recognition, decision-making, and language translation. AI has been an important field of research for more than half a century, with many practical applications. In recent years, AI has been applied to a variety of domains, including finance, healthcare, transportation, and entertainment.";
    char summary[MAX_SUMMARY_LENGTH] = "";
    summarize_text(text, summary, 3);
    printf("%s\n", summary);
    return 0;
}