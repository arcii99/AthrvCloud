//FormAI DATASET v1.0 Category: Text Summarizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000 // Maximum string length for processing
#define MAX_SENTENCES 50 // Maximum number of sentences to include in summary
#define MAX_SUMMARY_LEN 500 // Maximum length of summary

// Structure to store sentences and their corresponding sentence scores
typedef struct sentence {
    char text[MAX_STR_LEN];
    int score;
} Sentence;

// Function prototypes
void parseInput(FILE *fp, Sentence *sentences, int *numSentences);
void scoreSentences(Sentence *sentences, int numSentences);
void sortByScore(Sentence *sentences, int numSentences);
void generateSummary(Sentence *sentences, int numSentences, char *summary);

int main() {

    FILE *fp;
    Sentence sentences[MAX_SENTENCES];
    int numSentences = 0;
    char summary[MAX_SUMMARY_LEN];

    // Open file containing input text
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    parseInput(fp, sentences, &numSentences); // Parse input file
    scoreSentences(sentences, numSentences); // Score each sentence based on its content
    sortByScore(sentences, numSentences); // Sort sentences in descending order of their scores
    generateSummary(sentences, numSentences, summary); // Generate summary

    printf("Summary:\n%s\n", summary);

    fclose(fp);

    return 0;
}

// Function to parse input file and store sentences in array of Sentence structures
void parseInput(FILE *fp, Sentence *sentences, int *numSentences) {

    char line[MAX_STR_LEN];
    char *token;

    while (fgets(line, MAX_STR_LEN, fp) != NULL) {

        // Split line into individual sentences
        token = strtok(line, ".?!");

        while (token != NULL) {

            // Copy sentence into Sentence structure array
            strcpy(sentences[*numSentences].text, token);
            sentences[*numSentences].score = 0;

            (*numSentences)++; // Increment counter for number of sentences

            token = strtok(NULL, ".?!");
        }
    }
}

// Function to score sentences based on their content
void scoreSentences(Sentence *sentences, int numSentences) {

    int i, j;

    for (i = 0; i < numSentences; i++) {

        // Score sentence based on the number of occurrences of certain keywords
        if (strstr(sentences[i].text, "important")) {
            sentences[i].score += 5;
        }

        if (strstr(sentences[i].text, "need")) {
            sentences[i].score += 3;
        }

        if (strstr(sentences[i].text, "urgent")) {
            sentences[i].score += 4;
        }

        // Score sentence based on its length
        if (strlen(sentences[i].text) > 50) {
            sentences[i].score += 2;
        }

        // Score sentence based on the presence of certain parts of speech
        char *pos[] = {"VB", "VBD", "VBG", "VBN", "VBP", "VBZ", "JJ", "JJR", "JJS", "NN", "NNS", "NNP", "NNPS", NULL};
        char cmd[MAX_STR_LEN];
        sprintf(cmd, "echo '%s' | perl -ne 'foreach $w (split) {($word,$tag)=split(/_/, $w); print \"$tag \" if $_;}'", sentences[i].text);
        FILE *fp = popen(cmd, "r");
        char buff[MAX_STR_LEN];
        char *tag;

        while (fgets(buff, sizeof(buff), fp) != NULL) {
            // Remove newline character from tag
            tag = strtok(buff, "\n");

            // If tag is in list of parts of speech, add to sentence score
            for (j = 0; pos[j] != NULL; j++) {
                if (strstr(tag, pos[j]) != NULL) {
                    sentences[i].score++;
                    break;
                }
            }
        }

        pclose(fp);
    }
}

// Function to sort sentences in descending order of their scores
void sortByScore(Sentence *sentences, int numSentences) {

    int i, j;
    Sentence temp;

    for (i = 0; i < numSentences - 1; i++) {
        for (j = i + 1; j < numSentences; j++) {
            if (sentences[i].score < sentences[j].score) {
                temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }
}

// Function to generate summary based on top-scoring sentences
void generateSummary(Sentence *sentences, int numSentences, char *summary) {

    int i;
    int summaryLength = 0;

    // Copy top-scoring sentences to summary until its length exceeds the max summary length or the number of sentences has been exhausted
    for (i = 0; i < numSentences && summaryLength < MAX_SUMMARY_LEN; i++) {
        if (sentences[i].score > 0) {
            strcat(summary, sentences[i].text);
            strcat(summary, ". ");
            summaryLength += strlen(sentences[i].text);
        }
    }
}