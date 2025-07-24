//FormAI DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //Define the arrays for the text processing
    char sentence[1000];
    char word[100];
    char new_word[100];
    
    //Take input from the user
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    printf("Enter a word to replace: ");
    fgets(word, sizeof(word), stdin);
    printf("Enter new word: ");
    fgets(new_word, sizeof(new_word), stdin);
    
    //Remove any trailing newline characters from the inputs
    sentence[strcspn(sentence, "\n")] = 0;
    word[strcspn(word, "\n")] = 0;
    new_word[strcspn(new_word, "\n")] = 0;

    //Get the length of the word to replace
    int word_length = strlen(word);

    //Loop through the sentence to find the word to replace
    int i;
    int found = 0;
    for (i = 0; i < strlen(sentence); i++) {
        //Check if the word to replace is at this position
        if (strncmp(&sentence[i], word, word_length) == 0) {
            //Replace the word with the new word
            strncpy(&sentence[i], new_word, strlen(new_word));
            found = 1;
        }
    }
    
    //Check if the word was found and replaced
    if (found) {
        printf("Replaced '%s' with '%s':\n", word, new_word);
        printf("%s\n", sentence);
    } else {
        printf("Did not find '%s' in the sentence.\n", word);
    }

    return 0;
}