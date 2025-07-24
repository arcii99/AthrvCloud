//FormAI DATASET v1.0 Category: Text Summarizer ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function to remove provided characters from string
void removeChar(char *str, char *charsToRemove) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (strchr(charsToRemove, *dst) == NULL) {
            dst++;
        }
    }
    *dst = '\0';
}

// Function to convert text to lowercase
void toLowercase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int main() {
    char input[1000]; // Store user input text
    char temp[1000]; // Store temporary string
    char summary[1000] = ""; // Store final text summary
    int i, j, wordCount = 0; // Counters

    printf("Enter the text you want to summarize:\n");
    fgets(input, sizeof(input), stdin); // Get user input text

    char *charsToRemove = "(){}[]<>/';,."; // Characters to be removed
    removeChar(input, charsToRemove); // Remove unwanted characters
    toLowercase(input); // Convert to lowercase

    // Loop through each word in the text
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') { // Check for whitespace
            wordCount++; // Increment word count
            if (wordCount <= 10) { // Only keep the first 10 words
                strncat(summary, temp, sizeof(temp)); // Append word to summary
                strcat(summary, " "); // Add whitespace after word
            } else {
                strcat(summary, "..."); // Add ellipses to indicate summary
                break; // Exit loop after first 10 words are added
            }
            memset(temp, 0, sizeof(temp)); // Clear temporary string
            j = 0; // Reset temporary string counter
        } else {
            temp[j] = input[i]; // Add character to temporary string
            j++; // Increment temporary string counter
        }
    }

    printf("Summary:\n%s", summary); // Print text summary

    return 0;
}