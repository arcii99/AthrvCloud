//FormAI DATASET v1.0 Category: Compression algorithms ; Style: curious
// Welcome to my curious compression algorithm program!
// This algorithm is designed to compress text by replacing certain words with emojis.
// Let's dive right in and see how it works!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to replace words with emojis
void replaceWordsWithEmojis(char *text, int num_words) {

    char words[num_words][10]; // Array to hold each word to be replaced
    char emojis[num_words][10]; // Array to hold the emojis to replace the words

    // Let's fill up our words and emojis array
    strcpy(words[0], "hello");
    strcpy(emojis[0], "😊");

    strcpy(words[1], "goodbye");
    strcpy(emojis[1], "👋");

    strcpy(words[2], "love");
    strcpy(emojis[2], "❤️");

    // Loop through the text and look for the words to replace
    for(int i=0; i<num_words; i++) {
        char *pos = strstr(text, words[i]);

        // If we find the word, replace it with the emoji
        if(pos != NULL) {
            strcpy(pos, emojis[i]);
        }
    }
}

int main() {
    char text[1000];

    printf("Enter some text: ");
    fgets(text, 1000, stdin);

    // Call replaceWordsWithEmojis to compress the text
    replaceWordsWithEmojis(text, 3);

    // Print out the compressed text
    printf("Compressed text: %s\n", text);

    return 0;
}