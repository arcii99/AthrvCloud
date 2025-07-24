//FormAI DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input_text[1000];  //initialize an input_text array
    int word_count = 0, sentence_count = 0, i;  //initialize word_count and sentence_count variables to 0

    printf("Enter a paragraph of text:\n");  //request user to enter a paragraph of text
    fgets(input_text, 1000, stdin);  //store user input in input_text array

    //count number of words in paragraph
    for (i = 0; input_text[i] != '\n'; i++) {
        if (input_text[i] == ' ') {
            word_count++;
        }
    }
    word_count++;

    //count number of sentences in paragraph
    for (i = 0; input_text[i] != '\n'; i++) {
        if (input_text[i] == '.' || input_text[i] == '?' || input_text[i] == '!') {
            sentence_count++;
        }
    }

    printf("\nWord count: %d\n", word_count);  //display word count
    printf("Sentence count: %d\n", sentence_count);  //display sentence count

    //display longest word in paragraph
    char *token = strtok(input_text, " ");
    char longest_word[100];
    while (token != NULL) {
        if (strlen(token) > strlen(longest_word)) {
            strcpy(longest_word, token);
        }
        token = strtok(NULL, " ");
    }
    printf("Longest word: %s\n", longest_word);

    return 0;
}