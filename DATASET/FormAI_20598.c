//FormAI DATASET v1.0 Category: Text Summarizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 1000
#define MAX_SUMMARY_LEN 1000

void remove_punctuations(char* text);
int is_stopword(char* word);
int get_sentence_score(char* sentence, char* keywords[], int num_keywords);

int main() {
    char text[10000];
    char summary[MAX_SUMMARY_LEN];
    char* sentences[MAX_SENTENCES];
    char* keywords[MAX_SENTENCES]; 
    int num_sentences = 0;
    int num_keywords = 0;

    // Read the text to be summarized
    printf("Enter the text to be summarized:\n");
    fgets(text, sizeof(text), stdin);
    remove_punctuations(text);

    // Split the text into sentences
    sentences[num_sentences] = strtok(text, ".");
    while(sentences[num_sentences] != NULL) {
        num_sentences++;
        sentences[num_sentences] = strtok(NULL, ".");
    }

    // Read the keywords
    printf("Enter the keywords:\n");
    char keyword[100];
    while(fgets(keyword, sizeof(keyword), stdin) != NULL) {
        remove_punctuations(keyword);
        if(!is_stopword(keyword)) {
            keywords[num_keywords] = strdup(keyword);
            num_keywords++;
        }
    }

    // Compute the score of each sentence and store in an array
    int sentence_scores[num_sentences];
    for(int i = 0; i < num_sentences; i++) {
        sentence_scores[i] = get_sentence_score(sentences[i], keywords, num_keywords);
    }

    // Select the top 3 sentences based on score and concatenate to form the summary
    int indices[num_sentences];
    for(int i = 0; i < num_sentences; i++) {
        indices[i] = i;
    }
    for(int i = 0; i < num_sentences - 1; i++) {
        for(int j = i + 1; j < num_sentences; j++) {
            if(sentence_scores[indices[i]] < sentence_scores[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
    strncpy(summary, sentences[indices[0]], sizeof(summary));
    strncat(summary, " ", sizeof(summary));
    strncat(summary, sentences[indices[1]], sizeof(summary));
    strncat(summary, " ", sizeof(summary));
    strncat(summary, sentences[indices[2]], sizeof(summary));
    printf("Summary:\n%s\n", summary);

    return 0;
}

// Function to remove punctuations from a string
void remove_punctuations(char* text) {
    int j = 0;
    for(int i = 0; text[i] != '\0'; i++) {
        if(ispunct(text[i])) {
            continue;
        }
        text[j] = tolower(text[i]);
        j++;
    }
    text[j] = '\0';
}

// Function to check if a given word is a stopword
int is_stopword(char* word) {
    char* stopwords[] = {"the", "a", "an", "in", "of", "on", "at", "by", "to", "and", "but", "is", "are", "was", "were"};
    int num_stopwords = sizeof(stopwords) / sizeof(stopwords[0]);
    for(int i = 0; i < num_stopwords; i++) {
        if(strcmp(word, stopwords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to compute the score of a given sentence based on the presence of keywords
int get_sentence_score(char* sentence, char* keywords[], int num_keywords) {
    char* words[MAX_SENTENCES];
    int num_words = 0;
    words[num_words] = strtok(sentence, " ");
    while(words[num_words] != NULL) {
        num_words++;
        words[num_words] = strtok(NULL, " ");
    }
    int score = 0;
    for(int i = 0; i < num_words; i++) {
        for(int j = 0; j < num_keywords; j++) {
            if(strcmp(words[i], keywords[j]) == 0) {
                score++;
            }
        }
    }
    return score;
}