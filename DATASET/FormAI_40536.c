//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert all characters in a string to lowercase
void toLower(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char *argv[]) {
    // Check if filename was provided as command-line argument
    if (argc < 2) {
        printf("Usage: wordfreq filename.txt\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    // Check if file exists and can be opened
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return 1;
    }

    char buffer[1024];
    char *word;
    int frequency[1024] = {0};
    int count = 0;

    // Read file line by line
    while (fgets(buffer, 1024, file)) {
        // Tokenize each line into words
        word = strtok(buffer, " .,\n");

        // Count frequency of each word
        while (word != NULL) {
            toLower(word);  // Convert word to lowercase
            frequency[count]++;

            // Check if word already exists in the array
            for (int i = 0; i < count; i++) {
                if (strcmp(word, strtok(NULL, " .,\n")) == 0) {
                    frequency[i]++;
                    frequency[count]--;
                    break;
                }
            }

            // Go to next word
            word = strtok(NULL, " .,\n");
            count++;
        }
    }

    // Print word frequency table
    printf("Word Frequency Table:\n");
    for (int i = 0; i < count; i++) {
        if (frequency[i] > 0) {
            printf("%s: %d\n", strtok(buffer, " .,\n"), frequency[i]);
        }
    }

    // Close file and exit program
    fclose(file);
    return 0;
}