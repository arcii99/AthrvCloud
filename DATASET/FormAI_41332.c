//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processText(char *content) {
    char vowels[] = "aeiouAEIOU";
    char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    char words[1000][1000], temp[1000];
    int vowelCount = 0, consonantCount = 0, wordCount = 0;

    // Tokenize the text into individual words
    char *token = strtok(content, " ,.?!:");

    while (token != NULL) {
        strcpy(words[wordCount++], token);
        token = strtok(NULL, " ,.?!:");
    }

    // Sort the words in alphabetical order
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    // Print the sorted words
    printf("\nSorted words:\n");

    for (int i = 0; i < wordCount; i++) {
        printf("%s\n", words[i]);
    }

    // Calculate the number of vowels and consonants in the text
    for (int i = 0; i < strlen(content); i++) {
        if (strchr(vowels, content[i])) {
            vowelCount++;
        } else if (strchr(consonants, content[i])) {
            consonantCount++;
        }
    }

    // Print the number of vowels and consonants in the text
    printf("\nNumber of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);
}

int main() {
    char content[10000];

    // Get input text from user
    printf("Enter some text:\n");
    fgets(content, sizeof(content), stdin);
    content[strcspn(content, "\n")] = '\0'; // Remove newline character

    // Process the input text
    processText(content);

    return 0;
}