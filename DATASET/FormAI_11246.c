//FormAI DATASET v1.0 Category: Word Count Tool ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int wordcount = 0, charcount = 0, sentencecount = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    // loop through each character in the sentence
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isspace(sentence[i])) {  // check if character is whitespace
            if (charcount > 0) {  // if character count > 0, then increment wordcount
                wordcount++;
                charcount = 0;  // reset character count
            }
        }
        else {
            charcount++;  // increment character count
        }

        if (sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!') {  // check for sentence ending punctuation
            sentencecount++;
        }
    }

    // handle case where last character is not sentence ending punctuation but there is still a word to count
    if (charcount > 0) {
        wordcount++;
    }

    // print results
    printf("\nWord count: %d\n", wordcount);
    printf("Sentence count: %d\n", sentencecount);
    printf("Character count (excluding whitespace): %d\n", charcount);

    return 0;
}