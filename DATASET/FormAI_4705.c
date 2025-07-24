//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of words in a sentence
#define MAX_WORDS 100

// Struct to hold sentence and its score
typedef struct {
    char sentence[200];
    int score;
} Sentence;

// Function declarations
int get_word_count(char *sentence);
int get_sentence_count(char *text);
void get_sentences(char text[][200], char *file_name);
void get_sentence_scores(Sentence *sentences, int num_sentences, char *keywords[], int num_keywords);
void sort_sentences(Sentence *sentences, int num_sentences);
void print_summary(Sentence *sentences, int num_sentences, int summary_size);

int main() {
    char text[1000]; // Input text from user
    char sentences[MAX_WORDS][200]; // Array to hold sentences
    Sentence sentence_scores[MAX_WORDS]; // Array to hold sentence scores
    char *keywords[] = {"science", "research", "study", "experiment"}; // Array of keywords to look for
    int num_sentences, i, j, summary_size;

    // Get input text from user
    printf("Enter scientific article:\n");
    fgets(text, 1000, stdin);

    // Get all the sentences from input text and store in array
    get_sentences(sentences, text);

    // Get number of sentences
    num_sentences = get_sentence_count(text);

    // Get score for each sentence based on occurrence of keywords
    get_sentence_scores(sentence_scores, num_sentences, keywords, 4);

    // Sort sentences in descending order based on score
    sort_sentences(sentence_scores, num_sentences);

    // Get number of sentences to include in summary (10% of total sentences)
    summary_size = num_sentences / 10;

    // Print summary
    print_summary(sentence_scores, num_sentences, summary_size);

    return 0;
}

// Function to get the number of words in a sentence
int get_word_count(char *sentence) {
    int i, count = 1;

    for (i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ') {
            count++;
        }
    }

    return count;
}

// Function to get the number of sentences in the input text
int get_sentence_count(char *text) {
    int i, count = 0;

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            count++;
        }
    }

    return count;
}

// Function to get all the sentences from input text and store in array
void get_sentences(char sentences[][200], char *text) {
    int i, j = 0, k = 0;

    for (i = 0; text[i] != '\0'; i++) {
        sentences[j][k] = text[i];
        k++;

        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentences[j][k] = '\0';
            j++;
            k = 0;
        }
    }

    sentences[j][k] = '\0';
}

// Function to get score for each sentence based on occurrence of keywords
void get_sentence_scores(Sentence *sentences, int num_sentences, char *keywords[], int num_keywords) {
    int i, j, k, count;

    for (i = 0; i < num_sentences; i++) {
        count = 0;

        // Count occurrence of each keyword in sentence
        for (j = 0; j < num_keywords; j++) {
            k = 0;

            while (strstr(sentences[i].sentence + k, keywords[j]) != NULL) {
                count++;
                k = (int)(strstr(sentences[i].sentence + k, keywords[j]) - sentences[i].sentence) + 1;
            }
        }

        sentences[i].score = count;
    }
}

// Function to sort sentences in descending order based on score
void sort_sentences(Sentence *sentences, int num_sentences) {
    int i, j;
    Sentence temp;

    for (i = 0; i < num_sentences; i++) {
        for (j = i + 1; j < num_sentences; j++) {
            if (sentences[j].score > sentences[i].score) {
                temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }
}

// Function to print article summary
void print_summary(Sentence *sentences, int num_sentences, int summary_size) {
    int i;

    printf("\nArticle Summary:\n");

    for (i = 0; i < summary_size; i++) {
        printf("%s", sentences[i].sentence);
    }
}