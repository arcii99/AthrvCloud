//FormAI DATASET v1.0 Category: Text Summarizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 50 // Maximum length of summary

int main() {
    char article[] = "In recent years, there has been a rise in the number of people adopting plant-based diets.";
    // Sample article to be summarized

    char *words[MAX_SUMMARY_LENGTH]; // Pointer array of words in summary
    int word_count = 0; // Count of words in summary

    // Split article into words using strtok()
    char *token = strtok(article, " ");
    while (token != NULL) {
        words[word_count++] = token;
        token = strtok(NULL, " ");
    }

    // Build summary by selecting the first MAX_SUMMARY_LENGTH words
    char summary[MAX_SUMMARY_LENGTH];
    strcpy(summary, "");
    for (int i = 0; i < MAX_SUMMARY_LENGTH; i++) {
        strcat(summary, words[i]);
        strcat(summary, " ");
    }

    printf("Article: %s\n", article);
    printf("Summary: %s\n", summary);

    return 0;
}