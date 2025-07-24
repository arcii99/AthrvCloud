//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function to clean the input data */
char * preprocess(char *data) {
    int i;
    char *clean_text = malloc(strlen(data) + 1);
    if (clean_text == NULL) {
        printf("Memory Allocation Error!\n");
        exit(1);
    }
    strcpy(clean_text, data);
    /* Convert the text to lowercase */
    for (i = 0; i < strlen(clean_text); i++)
        clean_text[i] = tolower(clean_text[i]);
    /* Remove Punctuation */
    for (i = 0; i < strlen(clean_text); i++) {
        if (ispunct(clean_text[i])) {
            memmove(&clean_text[i], &clean_text[i + 1], strlen(clean_text) - i);
            i--;
        }
    }
    /* Remove whitespaces */
    for (i = 0; i < strlen(clean_text); i++) {
        if (isspace(clean_text[i])) {
            memmove(&clean_text[i], &clean_text[i + 1], strlen(clean_text) - i);
            i--;
        }
    }
    return clean_text;
}

/* Main function */
int main() {
    char data[500];
    printf("Enter the input data: ");
    fgets(data, sizeof(data), stdin);
    char *clean_data = preprocess(data);
    printf("Cleaned Data: %s\n", clean_data);
    free(clean_data);
    return 0;
}