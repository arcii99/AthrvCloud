//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate frequency of words in the given text
void freq_calc(char *text, char **words, int *freq, int num_words) {
    // Loop through all the words and count the frequency
    for (int i = 0; i < num_words; i++) {
        char *word = words[i];
        int count = 0;
        char *pos = strstr(text, word);

        while (pos != NULL) {
            count++;
            pos = strstr(pos + 1, word);
        }

        freq[i] = count;
    }
}

// Function to find the index of the word with maximum frequency
int max_freq_index(int *freq, int num_words) {
    int max_index = 0;
    int max_freq = freq[0];

    for (int i = 1; i < num_words; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_index = i;
        }
    }

    return max_index;
}

// Function to summarize the given text using the most frequent words
char *text_summarize(char *text, int num_sentences) {
    // Define the list of most common English words
    char *common_words[] = {"the", "of", "and", "a", "to", "in", "that", "is", "was", "for", "as", "with", "at", "by", "on", "were", "be", "he", "this", "which", "will", "she", "or", "from", "had", "not", "but", "have", "an", "they", "which", "one", "you", "we", "all", "his", "there", "been", "their", "if", "would", "who", "so", "her", "up", "out", "about", "some", "into", "them", "no", "its", "only", "like", "most", "my", "when", "than", "been", "more", "said", "over", "such", "did", "can", "your"};

    // Count the number of words in the text
    int num_words = 0;
    char *word = strtok(text, " ,.?!");

    while (word != NULL) {
        num_words++;
        word = strtok(NULL, " ,.?!");
    }

    // Create an array of unique words
    char **unique_words = malloc(num_words * sizeof(char *));
    int *unique_freq = calloc(num_words, sizeof(int));
    int index = 0;

    // Tokenize the text and add unique words to the array
    word = strtok(text, " ,.?!");

    while (word != NULL) {
        int is_common = 0;

        // Check if the word is a common English word
        for (int i = 0; i < 75; i++) {
            if (strcmp(word, common_words[i]) == 0) {
                is_common = 1;
                break;
            }
        }

        if (!is_common) {
            int is_unique = 1;

            // Check if the word is already in the unique words array
            for (int i = 0; i < index; i++) {
                if (strcmp(word, unique_words[i]) == 0) {
                    unique_freq[i]++;
                    is_unique = 0;
                    break;
                }
            }

            if (is_unique) {
                unique_words[index] = word;
                unique_freq[index++] = 1;
            }
        }

        word = strtok(NULL, " ,.?!");
    }

    // Calculate the frequency of unique words in the text
    freq_calc(text, unique_words, unique_freq, index);

    // Create a new array of unique words with maximum frequency
    char **top_words = malloc(num_sentences * sizeof(char *));
    int *top_freq = calloc(num_sentences, sizeof(int));
    int num_top_words = 0;

    while (num_top_words < num_sentences) {
        int max_index = max_freq_index(unique_freq, index);

        if (unique_freq[max_index] == 0) {
            // There are no more unique words with non-zero frequency
            break;
        }

        top_words[num_top_words] = unique_words[max_index];
        top_freq[num_top_words] = unique_freq[max_index];
        num_top_words++;

        // Set the frequency to 0 so that it is not considered again
        unique_freq[max_index] = 0;
    }

    // Create the summary text by appending sentences containing the top words
    char *summary = malloc(num_sentences * 100 * sizeof(char));
    char *sentence = strtok(text, ".?!");

    while (sentence != NULL) {
        int has_top_word = 0;

        // Check if the sentence contains any of the top words
        for (int i = 0; i < num_top_words; i++) {
            if (strstr(sentence, top_words[i]) != NULL) {
                has_top_word = 1;
                break;
            }
        }

        if (has_top_word) {
            strcat(summary, sentence);
            strcat(summary, ". ");
        }

        sentence = strtok(NULL, ".?!");
    }

    // Free the memory allocated for arrays
    free(unique_words);
    free(unique_freq);
    free(top_words);
    free(top_freq);

    // Return the summarized text
    return summary;
}

// Main function to test the text summarizer
int main() {
    char text[] = "The quick brown fox jumps over the lazy dog. The dog barked at the fox. The fox ran away from the dog. The dog chased the fox through the woods. The fox escaped from the dog and hid in a bush.";

    char *summary = text_summarize(text, 2);
    printf("%s\n", summary);

    free(summary);

    return 0;
}