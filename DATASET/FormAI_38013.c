//FormAI DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SUMMARY 100

int main() {
    char article[] = "This is an example article to demonstrate the functionality of the text summarizer program. The program reads in a given article and outputs a summary containing only the most important information. The program is highly configurable and can be adjusted to generate summaries of varying lengths and levels of detail. With this program, users can quickly generate summaries of long articles, allowing them to save time and focus on only the most important content.";

    char* words[MAX_WORDS]; // array containing words in article
    int frequencies[MAX_WORDS]; // array containing frequency of each word
    int num_words = 0; // number of words in array

    // tokenize article into array of words
    char* token = strtok(article, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // calculate frequency of each word
    for (int i = 0; i < num_words; i++) {
        frequencies[i] = 1;
        for (int j = i+1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequencies[i]++;
                words[j] = "";
            }
        }
    }

    // generate summary
    int summary_size = 0; // number of words in summary
    char summary[MAX_SUMMARY] = ""; // string containing summary
    int num_sentences = 0; // number of sentences in article

    // loop through each word in article
    for (int i = 0; i < num_words; i++) {
        if (strlen(words[i]) > 0) { // ignore empty strings

            if (strchr(".?!", words[i][strlen(words[i])-1])) { // found end of sentence
                num_sentences++;

                if (summary_size < MAX_SUMMARY-15) { // add sentence to summary if length permits
                    strcat(summary, words[i]);
                    strcat(summary, " ");
                    summary_size += strlen(words[i])+1;
                }
            }
            else { // not end of sentence
                if (frequencies[i] > 1) { // add word to summary if it appears multiple times in the article
                    strcat(summary, words[i]);
                    strcat(summary, " ");
                    summary_size += strlen(words[i])+1;
                }
            }

            if (summary_size > MAX_SUMMARY-15) { // reached maximum summary length
                break;
            }
        }
    }

    // print summary and statistics
    printf("Summary: %s\n\n", summary);
    printf("Number of sentences in article: %d\n", num_sentences);

    return 0;
}