//FormAI DATASET v1.0 Category: Text Summarizer ; Style: rigorous
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000
#define MAX_SENTENCES 50
#define MAX_WORD_LENGTH 20

int main() {
    // Initialize variables and arrays
    char text[MAX_LENGTH];
    char sentences[MAX_SENTENCES][MAX_LENGTH];
    char words[MAX_SENTENCES][MAX_WORD_LENGTH];
    int num_sentences = 0;

    // Read in text from user input
    printf("Enter text to summarize: ");
    fgets(text, MAX_LENGTH, stdin);
    
    // Parse text into sentences
    char *pch = strtok(text, ".?!");
    while (pch != NULL && num_sentences < MAX_SENTENCES) {
        strcpy(sentences[num_sentences], pch);
        num_sentences++;
        pch = strtok(NULL, ".?!");
    }
    
    // Parse sentences into words and calculate frequency of each word
    int num_words = 0;
    char *word;
    int word_freq[MAX_SENTENCES][MAX_WORD_LENGTH];
    for (int i = 0; i < num_sentences; i++) {
        num_words = 0; // Reset number of words for each sentence
        word = strtok(sentences[i], " ,.-\n"); // Parse sentence into words
        
        // Loop through each word in sentence and add to array while checking for duplicates
        while (word != NULL && num_words < MAX_WORD_LENGTH) {
            int duplicate = 0;
            
            // Check for duplicate words
            for (int j = 0; j < num_words; j++) {
                if (strcmp(words[i][j], word) == 0) {
                    // Increment frequency of existing word
                    word_freq[i][j]++;
                    duplicate = 1;
                    break;
                }
            }
            
            // Add word to array if not a duplicate
            if (!duplicate) {
                strcpy(words[i][num_words], word);
                word_freq[i][num_words] = 1;
                num_words++;
            }
            
            // Parse next word in sentence
            word = strtok(NULL, " ,.-\n");
        }
    }

    // Calculate total frequency of all words and determine which sentence has the highest frequency
    int total_freq[MAX_WORD_LENGTH];
    int highest_freq = 0;
    int highest_freq_sentence = 0;
    for (int i = 0; i < num_words; i++) {
        total_freq[i] = 0; // Reset frequency count for each word
        for (int j = 0; j < num_sentences; j++) {
            total_freq[i] += word_freq[j][i]; // Add frequency of word in each sentence
        }
        // Check if this word has the highest frequency so far
        if (total_freq[i] > highest_freq) {
            highest_freq = total_freq[i];
            highest_freq_sentence = i;
        }
    }

    // Print out summary of most frequent words and sentence
    printf("\nSummary:\n\n");
    printf("Most frequent word(s): ");
    for (int i = 0; i < num_words; i++) {
        if (total_freq[i] == highest_freq) {
            printf("%s ", words[highest_freq_sentence][i]);
        }
    }
    printf("\n\nMost frequent sentence: %s", sentences[highest_freq_sentence]);
    
    return 0;
}