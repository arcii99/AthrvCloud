//FormAI DATASET v1.0 Category: Compression algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

/* C compression algorithm implementation */

int charCount(const char *phrase);
void compress(const char *phrase, char *compressed);
void decompress(const char *compressed, char *decompressed);

int main() {
    char phrase[] = "Hello World! This is an example for a unique compression algorithm.";
    int phraseLen = charCount(phrase);
    printf("Original Phrase: %s\n", phrase);

    // Create compressed array with excess allocated memory
    char *compressed = (char*) calloc(phraseLen * 2, sizeof(char));
    compress(phrase, compressed);
    printf("Compressed Phrase: %s\n", compressed);

    // Create decompressed array with excess allocated memory
    char *decompressed = (char*) calloc(phraseLen, sizeof(char));
    decompress(compressed, decompressed);
    printf("Decompressed Phrase: %s\n", decompressed);

    // Free memory
    free(compressed);
    free(decompressed);

    return 0;
}

/* Returns the number of characters in a string */
int charCount(const char *phrase) {
    int count = 0;
    while (*phrase) {
        count++;
        phrase++;
    }
    return count;
}

/* Compresses string by converting all consecutive repeating
   characters to the character followed by its count */
void compress(const char *phrase, char *compressed) {
    int i, count, compressedIndex = 0, phraseLen = charCount(phrase);
    for (i = 0; i < phraseLen; i++) {
        count = 1;
        // Check for consecutive repeating characters
        while (i < phraseLen - 1 && phrase[i] == phrase[i+1]) {
            count++;
            i++;
        }
        // Write compressed character and its count to compressed array
        compressed[compressedIndex++] = phrase[i];
        compressed[compressedIndex++] = (char) (count + '0');
    }
    // Null-terminate compressed array
    compressed[compressedIndex] = '\0';
}

/* Decompresses string by converting all count-represented
   characters back to the character repeated count times */
void decompress(const char *compressed, char *decompressed) {
    int i, count, decompressedIndex = 0, compressedLen = charCount(compressed);
    for (i = 0; i < compressedLen; i += 2) {
        count = compressed[i+1] - '0';
        while (count--) {
            decompressed[decompressedIndex++] = compressed[i];
        }
    }
    // Null-terminate decompressed array
    decompressed[decompressedIndex] = '\0';
}