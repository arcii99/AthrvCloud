//FormAI DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of occurrences of a word in a text
int count_occurrences(char *word, char *text) {
    int count = 0;
    char *pos = strstr(text, word); // Find first occurrence of word in text

    while (pos != NULL) { // Keep counting occurrences until no more are found
        count++;
        pos = strstr(pos + strlen(word), word); // Move to next occurrence of word
    }

    return count;
}

int main() {
    char *text = "The quick brown fox jumps over the lazy dog. The lazy dog didn't care. The quick brown fox was surprised.";
    char *word = "the";

    printf("Text:\n%s\n\n", text);

    int count = count_occurrences(word, text);

    printf("Number of occurrences of '%s' in text: %d", word, count);

    return 0;
}