//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: secure
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

int main() {
    char text[MAX_STRING_LENGTH];
    int pos = 0, neg = 0, neutral = 0, count = 0;

    printf("Enter your text: ");
    fgets(text, MAX_STRING_LENGTH, stdin);

    // Remove trailing newline
    if (text[strlen(text) - 1] == '\n')
        text[strlen(text) - 1] = '\0';

    // Loop through each character in the text
    for (int i = 0; i < strlen(text); i++) {
        // Ignore punctuation and spaces
        if (text[i] == ' ' || text[i] == '.' || text[i] == ',' || text[i] == ':' || text[i] == ';' || text[i] == '?' || text[i] == '!')
            continue;

        // Count the number of positive, negative, and neutral words
        count++;
        if (strstr(text + i, "good") == text + i)
            pos++;
        else if (strstr(text + i, "bad") == text + i)
            neg++;
        else
            neutral++;

        // Skip to the end of the word
        while (i < strlen(text) && text[i] != ' ' && text[i] != '.' && text[i] != ',' && text[i] != ':' && text[i] != ';' && text[i] != '?' && text[i] != '!')
            i++;
    }

    // Determine the sentiment
    if (count == 0)
        printf("No sentiment detected.\n");
    else if (pos > neg && pos > neutral)
        printf("Positive sentiment detected.\n");
    else if (neg > pos && neg > neutral)
        printf("Negative sentiment detected.\n");
    else
        printf("Neutral sentiment detected.\n");

    return 0;
}