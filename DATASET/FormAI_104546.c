//FormAI DATASET v1.0 Category: Text Summarizer ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

/* Function to remove non-alphanumeric characters from a string */
void removeNonAlphaNumeric(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

/* Function to count the number of occurrences of a word in a string */
int countOccurrences(char *str, char *word) {
    int count = 0;
    char *found = strstr(str, word);
    while (found) {
        ++count;
        found = strstr(found + 1, word);
    }
    return count;
}

int main() {

    char text[MAX_STRING_LENGTH];
    printf("Enter text to summarize (max %d chars):\n", MAX_STRING_LENGTH);
    fgets(text, sizeof(text), stdin);

    /* Remove non-alphanumeric characters and convert to lowercase */
    removeNonAlphaNumeric(text);

    /* Create an array of keywords to summarize the text */
    char *keywords[] = {"the", "a", "an", "in", "at", "to", "for", "by", "of", "on",
                        "and", "but", "with", "or", "as", "is", "was", "were",
                        "it", "that", "this", "these", "those", "which", "who", "whom"};

    int nKeywords = sizeof(keywords) / sizeof(keywords[0]);

    /* Count the number of occurrences of each keyword */
    int keywordCount[nKeywords];
    int i;
    for (i = 0; i < nKeywords; i++) {
        keywordCount[i] = countOccurrences(text, keywords[i]);
    }

    /* Determine the top 3 keywords */
    int maxCount, maxIndex;
    int topKeywords[3];
    for (i = 0; i < 3; i++) {
        maxCount = 0;
        maxIndex = -1;
        int j;
        for (j = 0; j < nKeywords; j++) {
            if (keywordCount[j] > maxCount) {
                maxCount = keywordCount[j];
                maxIndex = j;
            }
        }
        if (maxIndex != -1) {
            topKeywords[i] = maxIndex;
            keywordCount[maxIndex] = -1;
        } else {
            topKeywords[i] = -1;
        }
    }

    /* Print the top 3 keywords */
    printf("\nTop 3 Keywords: ");
    for (i = 0; i < 3; i++) {
        if (topKeywords[i] != -1) {
            printf("%s ", keywords[topKeywords[i]]);
        }
    }

    return 0;
}