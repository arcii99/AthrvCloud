//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TEXT_SIZE 5000
#define MAX_SENTENCES 1000
#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 2000

// Function to calculate the length of a string
int string_length(char *text) {
    int count = 0;
    while (*text != '\0') {
        count++;
        text++;
    }
    return count;
}

// Function to convert all characters in a string to lowercase
void to_lowercase(char *text) {
   while(*text) {
      *text = tolower(*text);
      text++;
   }
}

// Function to split a string into individual words
int split_words(char words[MAX_SENTENCES][MAX_WORD_COUNT], char *text) {
    char *pch;
    int i = 0;
    pch = strtok(text," ,.-():;");
    while (pch != NULL) {
        strcpy(words[i], pch);
        i++;
        pch = strtok(NULL, " ,.-():;");
    }
    return i; 
}

// Function to remove non-alphabetic characters from a string
void remove_non_alphabetic(char *text) {
    while (*text != '\0') {
        if (!isalpha(*text)) {
            *text = ' ';
        }
        text++;
    }
}

// Function to remove duplicate words from an array of words
int remove_duplicates(char words[MAX_WORD_COUNT][MAX_WORD_LENGTH], int count) {
    int i, j;
    int n = count;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n;) {
            if (strcmp(words[j], words[i]) == 0) {
                int k;
                for (k = j; k < n; k++) {
                    strcpy(words[k], words[k + 1]); 
                }
                n--;
            }
            else {
                j++;
            }
        }
    }
    return n;
}

// Function to check if a word is a stop word
int is_stop_word(char *word) {
    char *stop_words[] = {"a", "an", "and", "are", "as", "at", "be", "by", "for", "from", "has", "he", "in", "is", "it", "its", "of", "on", "that", "the", "to", "was", "were", "will", "with"};
    int stop_word_count = sizeof(stop_words)/sizeof(stop_words[0]);
    int i;
    for (i = 0; i < stop_word_count; i++) {
        if (strcmp(word, stop_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to compute the frequency of words in an array of words
void compute_word_frequencies(char words[MAX_WORD_COUNT][MAX_WORD_LENGTH], int count, int frequency[MAX_WORD_COUNT], int *max_frequency) {
    int i, j;
    *max_frequency = 0;
    for (i = 0; i < count; i++) {
        frequency[i] = 0;
        for (j = 0; j < count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequency[i]++;
            }
        }
        if (frequency[i] > *max_frequency) {
            *max_frequency = frequency[i];
        }
    }
}

// Function to generate a summary of a text
void generate_summary(char *text) {
    int i;
    int word_count;
    char words[MAX_SENTENCES][MAX_WORD_COUNT][MAX_WORD_LENGTH];
    int frequency[MAX_WORD_COUNT];
    int max_frequency;
    char *sentences[MAX_SENTENCES];
    char *pch;
    int sentence_count = 0;
    pch = strtok(text, ".!?"); // split text into sentences
    while (pch != NULL) {
        sentences[sentence_count] = pch;
        sentence_count++;
        pch = strtok(NULL, ".!?");
    }
    for (i = 0; i < sentence_count; i++) {
        remove_non_alphabetic(sentences[i]); // remove non-alphabetic characters from each sentence
        to_lowercase(sentences[i]); // convert each sentence to lowercase
        word_count = split_words(words[i], sentences[i]); // split each sentence into words
        int j;
        for (j = 0; j < word_count; j++) {
            if (is_stop_word(words[i][j])) { // remove stop words from the array of words
                int k;
                for (k = j; k < word_count; k++) {
                    strcpy(words[i][k], words[i][k + 1]); // shift the words after the stop word left by 1
                }
                word_count--;
            }
        }
        word_count = remove_duplicates(words[i], word_count); // remove duplicate words from the array of words
        compute_word_frequencies(words[i], word_count, frequency, &max_frequency); // compute the frequency of words in the array of words
        printf("\nSummary of sentence %d: ", i+1); // generate summary for each sentence
        for (j = 0; j < word_count; j++) {
            if (frequency[j] == max_frequency) {
                printf("%s ", words[i][j]);
            }
        }
    }
}

int main() {
    char text[MAX_TEXT_SIZE] = "A chatbot is a computer program designed to simulate conversation with human users, especially over the Internet. Chatbots are artificial intelligence programs that are designed to mimic human conversation. They are programmed to understand natural language, which allows them to interact with users in an intuitive and human-like way. Chatbots are often used to answer simple questions or provide customer support, but they can also be programmed to perform more complex tasks. Some chatbots are designed to provide entertainment, while others are designed for practical purposes such as scheduling appointments or ordering products online. In recent years, chatbots have become increasingly popular as businesses and organizations look for ways to automate customer service and provide a more personalized experience for users. However, chatbots are not without their limitations, and there are still many challenges to be overcome in the development of truly intelligent conversational agents.";
    generate_summary(text);
    return 0;
}