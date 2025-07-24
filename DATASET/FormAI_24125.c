//FormAI DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold sentence information
typedef struct sentence {
    int index;
    char *text;
    int score;
} Sentence;

// function to count number of sentences in a text
int count_sentences(char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
    }
    return count;
}

// function to split text into an array of sentences
void split_sentences(char *text, Sentence *sentences, int num_sentences) {
    char *token = strtok(text, ".!?"); // tokenize text based on punctuation
    int i = 0;
    while (token != NULL) { // iterate through tokens and add them to sentence struct
        sentences[i].index = i;
        sentences[i].text = malloc(strlen(token) + 1);
        strcpy(sentences[i].text, token);
        i++;
        token = strtok(NULL, ".!?");
    }
}

// function to calculate score of each sentence based on keyword matches
void calculate_scores(Sentence *sentences, int num_sentences, char *keywords[], int num_keywords) {
    for (int i = 0; i < num_sentences; i++) {
        for (int j = 0; j < num_keywords; j++) {
            char *match = strstr(sentences[i].text, keywords[j]);
            if (match != NULL) {
                sentences[i].score++;
            }
        }
    }
}

// function to sort sentences by score in descending order
void sort_sentences(Sentence *sentences, int num_sentences) {
    for (int i = 0; i < num_sentences - 1; i++) {
        for (int j = i + 1; j < num_sentences; j++) {
            if (sentences[i].score < sentences[j].score) {
                // swap sentences if ith sentence score is less than jth sentence score
                Sentence tmp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = tmp;
            }
        }
    }
}

// function to print summary
void print_summary(Sentence *sentences, int num_summary_sentences) {
    for (int i = 0; i < num_summary_sentences; i++) {
        printf("%d. %s\n", sentences[i].index, sentences[i].text);
    }
}

int main(void) {
    char text[] = "The quick brown fox jumped over the lazy dog. "
                  "The lazy dog slept all day. "
                  "The quick brown fox hunted for food. "
                  "The quick brown fox found food and ate it.";
    char *keywords[] = {"fox", "food"}; // list of keywords to match
    int num_keywords = sizeof(keywords)/sizeof(keywords[0]); // calculate number of keywords

    int num_sentences = count_sentences(text); // count number of sentences in text
    Sentence sentences[num_sentences]; // create array of Sentence struct
    split_sentences(text, sentences, num_sentences); // split text into sentences and store in struct
    calculate_scores(sentences, num_sentences, keywords, num_keywords); // calculate score of each sentence based on keyword matches
    sort_sentences(sentences, num_sentences); // sort sentences by score in descending order
    int num_summary_sentences = 2; // choose number of sentences to include in summary
    print_summary(sentences, num_summary_sentences); // print summary

    return 0;
}