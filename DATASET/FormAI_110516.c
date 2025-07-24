//FormAI DATASET v1.0 Category: Text Summarizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 1000

// Function to tokenize given string and count the number of sentences
int tokenize(char *text, char *sentences[], int *sentence_length) {
    int len = strlen(text);

    if (len == 0) // If input string is empty 
        return 0;

    int sentence_count = 0, word_count = 0;
    char *token = strtok(text, ".!?"); // Tokenize string using delimiters (sentences)

    while (token != NULL && sentence_count < MAX_SENTENCES) {
        // Add sentence to sentences array
        sentences[sentence_count] = token;
        sentence_count++;

        // Count number of words in sentence
        char *word = strtok(token, " ");
        while (word != NULL) {
            word_count++;
            word = strtok(NULL, " ");
        }

        // Store sentence length
        sentence_length[sentence_count-1] = word_count;
        word_count = 0;

        // Get next sentence
        token = strtok(NULL, ".!?");
    }

    return sentence_count;
}

// Function to remove non-alphanumeric characters from given string
void remove_special_chars(char *str) {
    int len = strlen(str);
    char temp[len];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
             temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

// Function to generate summary using TF-IDF algorithm
void generate_summary(char *text) {
    char *sentences[MAX_SENTENCES];
    int sentence_length[MAX_SENTENCES];

    // Tokenize input text
    int sentence_count = tokenize(text, sentences, sentence_length);

    // Calculate TF (term frequency) for each word in each sentence
    int tf[sentence_count][MAX_SENTENCE_LENGTH];
    for (int i = 0; i < sentence_count; i++) {
        for (int j = 0; j < sentence_length[i]; j++) {
            tf[i][j] = 0;
            char *word = strtok(sentences[i], " ");
            while (word != NULL) {
                remove_special_chars(word);
                if (strlen(word) > 0) {
                    if (strcmp(word, sentences[i] + j) == 0) {
                        tf[i][j]++;
                    }
                }
                word = strtok(NULL, " ");
            }
        }
    }

    // Calculate IDF (inverse document frequency) for each word in the entire text
    int df[MAX_SENTENCE_LENGTH];
    memset(df, 0, sizeof(df));
    char *words[MAX_SENTENCE_LENGTH];
    int word_count = 0;
    for (int i = 0; i < sentence_count; i++) {
        char *word = strtok(sentences[i], " ");
        while (word != NULL) {
            remove_special_chars(word);
            if (strlen(word) > 0) {
                int flag = 1;
                for (int j = 0; j < word_count; j++) {
                    if (strcmp(word, words[j]) == 0) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    words[word_count++] = word;
                }
                df[word_count-1]++;
            }
            word = strtok(NULL, " ");
        }
    }
    double idf[word_count];
    for (int i = 0; i < word_count; i++) {
        idf[i] = log((double)sentence_count / df[i]);
    }

    // Calculate TF-IDF score for each sentence
    double tfidf[sentence_count];
    memset(tfidf, 0, sizeof(tfidf));
    for (int i = 0; i < sentence_count; i++) {
        for (int j = 0; j < sentence_length[i]; j++) {
            tfidf[i] += (double)tf[i][j] * idf[j];
        }
    }

    // Get top N sentences based on TF-IDF score (N = 30% of sentence count)
    int summary_length = sentence_count * 0.3;
    for (int i = 0; i < summary_length; i++) {
        double max_score = 0;
        int max_index = 0;
        for (int j = 0; j < sentence_count; j++) {
            if (tfidf[j] > max_score) {
                max_score = tfidf[j];
                max_index = j;
            }
        }
        printf("%s\n", sentences[max_index]);
        tfidf[max_index] = 0; // Remove sentence from list of candidates for next iteration
    }
}

int main() {
    char text[] = "In computer programming, text summarization refers to the process of creating a short, coherent, and fluent summary of a larger text document. The goal of text summarization is to find the essence of a text document and to present it in a concise and informative manner. There are many different techniques and algorithms that can be used for text summarization, including statistical methods, rule-based methods, and machine learning methods. Some of the most commonly used techniques include TF-IDF, LSA, and LDA. TF-IDF stands for term frequency-inverse document frequency and is a statistical method that is based on the idea that important words in a text document will occur more frequently than less important words. LSA stands for latent semantic analysis and is a machine learning method that is based on the idea that words that are used in similar contexts are likely to have similar meanings. LDA stands for latent Dirichlet allocation and is a statistical method that is based on the idea that a text document is generated from a mixture of topics.";
    
    generate_summary(text); // Call summary generation function

    return 0;
}