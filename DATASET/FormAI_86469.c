//FormAI DATASET v1.0 Category: Text Summarizer ; Style: invasive
#include <stdio.h>
#include <string.h>

// Function to summarize a given text
char* summarize(char* text, int limit) {

    // Initialize summary string with an empty string
    char summary[1000] = "";
    
    // Split the text into sentences
    char* sentence = strtok(text, ".");
    while(sentence != NULL) {

        // Check if the length of summary sentence is within the limit
        if(strlen(summary) + strlen(sentence) <= limit) {

            // If yes, append the sentence to summary
            strcat(summary, sentence);
            strcat(summary, ".");

        } else {
            
            // If not, stop summarizing
            break;

        }

        // Move to the next sentence
        sentence = strtok(NULL, ".");

    }

    // Return the summary
    return summary;

}

int main() {

    // Input text to summarize
    char text[1000] = "This is an example program for text summarization. Text summarization is the process of creating a shorter version of a text, while preserving its main points. There are many techniques for text summarization, including extraction-based, abstraction-based, and hybrid approaches. The goal of text summarization is to make large bodies of text easier to understand and digest. Text summarization has many applications, including automatic news summarization, email summarization, and document summarization. In this program, we will use the extraction-based approach to summarize a given text.";

    // Input limit for summary length
    int limit = 100;

    // Call the summarize function
    char* summary = summarize(text, limit);

    // Output the summary
    printf("Summary: %s", summary);

    return 0;

}