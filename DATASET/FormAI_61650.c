//FormAI DATASET v1.0 Category: Text Summarizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in the given text string
int count_words(char* text) {
    int count = 1;
    for(int i=0; text[i]!='\0'; i++) {
        if(text[i] == ' ') {
            count++;
        }
    }
    return count;
}

// Function to summarize the given text using the specified number of sentences
void summarize_text(char* text, int num_sentences) {
    // Compute the total number of words in the text
    int num_words = count_words(text);
    // Calculate the average number of words per sentence
    int avg_words_per_sentence = num_words/num_sentences;
    // Split the text into individual words
    char** words = (char**)calloc(num_words, sizeof(char*));
    char* word = strtok(text, " ");
    int count = 0;
    while(word != NULL) {
        words[count++] = word;
        word = strtok(NULL, " ");
    }
    // Determine the significance score of each word by counting its occurrences
    int* scores = (int*)calloc(num_words, sizeof(int));
    for(int i=0; i<num_words; i++) {
        for(int j=i+1; j<num_words; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                scores[i]++;
            }
        }
    }
    // Retrieve the top-scoring sentences based on the accumulated significance scores
    int* sentence_scores = (int*)calloc(num_sentences, sizeof(int));
    int* sentence_lengths = (int*)calloc(num_sentences, sizeof(int));
    char** sentences = (char**)calloc(num_sentences, sizeof(char*));
    char* sentence = strtok(text, ".");
    count = 0;
    while(sentence != NULL) {
        sentences[count] = sentence;
        sentence_lengths[count] = count_words(sentence);
        for(int i=0; i<sentence_lengths[count]; i++) {
            for(int j=0; j<num_words; j++) {
                if(strcmp(words[j], sentences[count][i]) == 0) {
                    sentence_scores[count] += scores[j];
                }
            }
        }
        count++;
        sentence = strtok(NULL, ".");
    }
    // Sort the sentences in descending order by their significance scores
    for(int i=0; i<num_sentences-1; i++) {
        for(int j=i+1; j<num_sentences; j++) {
            if(sentence_scores[i] < sentence_scores[j]) {
                // Swap scores
                int temp_score = sentence_scores[i];
                sentence_scores[i] = sentence_scores[j];
                sentence_scores[j] = temp_score;
                // Swap lengths
                int temp_length = sentence_lengths[i];
                sentence_lengths[i] = sentence_lengths[j];
                sentence_lengths[j] = temp_length;
                // Swap pointers
                char* temp_sentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp_sentence;
            }
        }
    }
    // Print the top-scoring sentences to the console
    for(int i=0; i<num_sentences; i++) {
        printf("%s.", sentences[i]);
        if(i == num_sentences-1) {
            printf("..");
        } else {
            printf(" ");
        }
    }
    printf("\n");
    // Free allocated memory
    free(words);
    free(scores);
    free(sentence_scores);
    free(sentence_lengths);
    free(sentences);
}

int main() {
    char text[] = "This is a sample text string that we will use to test the text summarizer program. The program should be able to accurately identify the most important sentences from this text and summarize them into a shorter approximation of the original text. The number of sentences to be included in the summary can be customized by passing a parameter to the summarize_text function. We will start by testing the program with a small input text, but it should also be able to handle larger texts with thousands of words and multiple paragraphs. Let's see how well the program works!";
    int num_sentences = 3;
    summarize_text(text, num_sentences);
    return 0;
}