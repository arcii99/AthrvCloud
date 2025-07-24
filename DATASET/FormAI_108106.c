//FormAI DATASET v1.0 Category: Text Summarizer ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 1000
#define MAX_LEN 1000

int main() {

    char text[MAX_SENTENCES][MAX_LEN];
    int freq[MAX_SENTENCES];
    int sentenceCount = 0;

    // Read from input file
    FILE *inputFile;
    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    while (fgets(text[sentenceCount], MAX_LEN, inputFile) != NULL) {
        sentenceCount++;
    }

    fclose(inputFile);

    // Calculate frequency of each sentence
    for (int i = 0; i < sentenceCount; i++) {
        freq[i] = 0;

        for (int j = 0; j < strlen(text[i]); j++) {
            if (text[i][j] == 'a' || text[i][j] == 'e' || text[i][j] == 'i' || text[i][j] == 'o' || text[i][j] == 'u'
            || text[i][j] == 'A' || text[i][j] == 'E' || text[i][j] == 'I' || text[i][j] == 'O' || text[i][j] == 'U') {
                freq[i]++;
            }
        }
    }

    // Sort by frequency in descending order
    for (int i = 0; i < sentenceCount-1; i++) {
        for (int j = i+1; j < sentenceCount; j++) {
            if (freq[i] < freq[j]) {    // Swap frequency values
                int temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;

                // Swap text values
                char tempStr[MAX_LEN];
                strcpy(tempStr, text[i]);
                strcpy(text[i], text[j]);
                strcpy(text[j], tempStr);
            }
        }
    }

    // Print top 10 sentences
    printf("\n--- Summary ---\n");
    for (int i = 0; i < 10; i++) {
        printf("%s", text[i]);
    }

    return 0;
}