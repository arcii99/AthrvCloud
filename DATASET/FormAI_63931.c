//FormAI DATASET v1.0 Category: Text Summarizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

// Struct to store each sentence along with its score
struct sentence {
    char text[MAX_LEN];
    int score;
};

// Function to calculate the score of each sentence
void calculateScore(char* input, char* keywords[], int num_keywords, struct sentence** sentences, int* num_sentences) {
    *num_sentences = 0; // Initialize the number of sentences to 0
    char* token;
    char* sentence_ptr;
    char* delimiter = ".\n"; // Define the delimiter as period or newline
    char lower_case_input[MAX_LEN];
    strcpy(lower_case_input, input);
    lower_case_input[strcspn(lower_case_input, "\n")] = '\0'; // Remove the newline character at the end

    // Convert the input to lower case
    for (int i = 0; lower_case_input[i]; i++) {
        lower_case_input[i] = tolower(lower_case_input[i]);
    }

    // Tokenize the input into individual sentences
    sentence_ptr = strtok(lower_case_input, delimiter);

    while (sentence_ptr != NULL) {
        // Initialize the score of the sentence to 0
        int score = 0;

        // Tokenize the sentence into individual words
        token = strtok(sentence_ptr, " ");

        while (token != NULL) {
            // Check if the current word is a keyword
            for (int i = 0; i < num_keywords; i++) {
                if (strcmp(token, keywords[i]) == 0) {
                    score++;
                }
            }
            token = strtok(NULL, " ");
        }

        // If the sentence contains at least one keyword, add it to the array of sentences
        if (score > 0) {
            strncpy((*sentences)[*num_sentences].text, sentence_ptr, MAX_LEN);
            (*sentences)[*num_sentences].score = score;
            (*num_sentences)++;
        }

        sentence_ptr = strtok(NULL, delimiter);
    }
}

// Comparison function to sort the array of sentences in descending order of score
int compareScores(const void* a, const void* b) {
    const struct sentence* sentenceA = (struct sentence*)a;
    const struct sentence* sentenceB = (struct sentence*)b;

    if (sentenceA->score < sentenceB->score)
        return 1;
    else if (sentenceA->score > sentenceB->score)
        return -1;
    else
        return 0;
}

int main() {
    char input[MAX_LEN];
    char* keywords[] = {"programming", "language", "code", "computer", "algorithm"}; // Change the keywords as desired
    int num_keywords = sizeof(keywords) / sizeof(char*);
    struct sentence* sentences = malloc(MAX_LEN * sizeof(struct sentence));
    int num_sentences = 0;

    // Read the input from the user
    printf("Enter the text to be summarized:\n");
    fgets(input, MAX_LEN, stdin);

    // Calculate the score of each sentence and store it in an array
    calculateScore(input, keywords, num_keywords, &sentences, &num_sentences);

    // Sort the array of sentences in descending order of score
    qsort(sentences, num_sentences, sizeof(struct sentence), compareScores);

    // Print the top 3 sentences with the highest score
    printf("Summary:\n");
    for (int i = 0; i < 3 && i < num_sentences; i++) {
        printf("%s\n", sentences[i].text);
    }

    free(sentences);
    return 0;
}