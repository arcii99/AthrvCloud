//FormAI DATASET v1.0 Category: Text processing ; Style: brave
#include<stdio.h>
#include<string.h>

// function to capitalize the first letter of each word in a sentence
char *brave_text_processing(char *sentence) {
    int i;
    int first_char_in_word = 1;
    for (i = 0; i < strlen(sentence); i++) {
        if (first_char_in_word) {
            sentence[i] = toupper(sentence[i]); // capitalizing the first letter
            first_char_in_word = 0; // setting the flag to false after capitalizing
        }
        if (sentence[i] == ' ') {
            first_char_in_word = 1; // setting the flag to true if there is a space (new word)
        }
    }
    return sentence;
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    printf("Your brave text is: %s", brave_text_processing(sentence)); // printing the modified sentence
    return 0;
}