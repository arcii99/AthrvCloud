//FormAI DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 10000
#define MAX_OUTPUT_SIZE 1000

// Function to remove punctuations from the input text
void remove_punctuations(char *text) {
    for(int i = 0; text[i] != '\0'; i++) {
        if (ispunct(text[i])) {
            for (int j = i; text[j] != '\0'; j++) {
                text[j] = text[j + 1];
            }
            i--;
        }
    }
}

// Function to tokenize the input text into sentences
int split_into_sentences(char *text, char sentences[][MAX_INPUT_SIZE]) {
    int count = 0;

    // Tokenize the text using the period as the separator
    char *token = strtok(text, ".");
    while(token != NULL) {
        // Trim the whitespace from the beginning of the sentence
        while(*token == ' ' || *token == '\t' || *token == '\n') {
            token++;
        }
        if (strlen(token) > 1) {
            // Copy the sentence into the sentences array
            strcpy(sentences[count], token);
            count++;
        }
        token = strtok(NULL, ".");
    }

    return count;
}

// Function to calculate the score of a sentence
double sentence_score(char *sentence, int word_count, char keywords[][50], int keyword_count) {
    double score = 0.0;

    // Tokenize the sentence into words
    char *token = strtok(sentence, " ");
    while(token != NULL) {
        // Check if the word is a keyword
        for(int i = 0; i < keyword_count; i++) {
            if(strcmp(token, keywords[i]) == 0) {
                score += 1.0;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    // Normalize the score by dividing it by the number of words in the sentence
    score = score / (double)word_count;

    return score;
}

// Function to generate the summary
void generate_summary(char *input_text, char *output_text, int num_sentences) {
    char sentences[num_sentences][MAX_INPUT_SIZE];
    char keywords[][50] = {"computer", "programming", "language", "algorithm", "data", "structure"};
    int keyword_count = 6;
    int sentence_count = split_into_sentences(input_text, sentences);

    // Remove punctuations from the input text
    remove_punctuations(input_text);

    // Calculate the total number of words in the input text
    int word_count = 0;
    char *token = strtok(input_text, " ");
    while(token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }

    // Calculate the score of each sentence and store it in an array
    double sentence_scores[sentence_count];
    for(int i = 0; i < sentence_count; i++) {
        sentence_scores[i] = sentence_score(sentences[i], word_count, keywords, keyword_count);
    }

    // Select the top num_sentences sentences based on score
    int selected_sentences[num_sentences];
    for(int i = 0; i < num_sentences; i++) {
        selected_sentences[i] = -1;
    }
    for(int i = 0; i < num_sentences; i++) {
        double max_score = -1.0;
        int max_index = -1;
        for(int j = 0; j < sentence_count; j++) {
            // Check if the sentence has already been selected
            int already_selected = 0;
            for(int k = 0; k < i; k++) {
                if(j == selected_sentences[k]) {
                    already_selected = 1;
                    break;
                }
            }
            if(!already_selected && sentence_scores[j] > max_score) {
                max_score = sentence_scores[j];
                max_index = j;
            }
        }
        selected_sentences[i] = max_index;
    }

    // Copy the selected sentences into the output text
    int output_index = 0;
    for(int i = 0; i < num_sentences; i++) {
        if(selected_sentences[i] != -1) {
            strcpy(&output_text[output_index], sentences[selected_sentences[i]]);
            output_index += strlen(sentences[selected_sentences[i]]);
            output_text[output_index] = '.';
            output_index++;
        }
    }
    output_text[output_index] = '\0';
}

int main() {
    // Initialize the input and output text buffers
    char input_text[MAX_INPUT_SIZE];
    char output_text[MAX_OUTPUT_SIZE];

    // Read the input text from stdin
    fgets(input_text, MAX_INPUT_SIZE, stdin);

    // Generate the summary and output it to stdout
    generate_summary(input_text, output_text, 3);
    printf("%s", output_text);

    return 0;
}