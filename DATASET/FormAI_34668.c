//FormAI DATASET v1.0 Category: Text processing ; Style: Alan Touring
// Alan Touring Style program for text processing in C

#include <stdio.h>
#include <string.h>

int main() {

    char text[100];
    printf("Enter a sentence: ");
    fgets(text, sizeof(text), stdin); // get input from user
    
    // count number of words in the sentence
    int word_count = 1;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ' && text[i+1] != ' ') {
            word_count++;
        }
    }
    printf("Number of words in the sentence: %d\n", word_count);
    
    // find the longest word in the sentence
    char longest_word[20];
    char current_word[20];
    int longest_word_length = 0;
    int current_word_length = 0;
    int word_start_index = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            current_word_length = i - word_start_index;
            strncpy(current_word, text + word_start_index, current_word_length);
            current_word[current_word_length] = '\0';
            if (current_word_length > longest_word_length) {
                strncpy(longest_word, current_word, current_word_length);
                longest_word[current_word_length] = '\0';
                longest_word_length = current_word_length;
            }
            word_start_index = i + 1;
        }
    }
    printf("The longest word in the sentence is: %s\n", longest_word);
    
    // replace all vowels in sentence with 'X'
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' ||
            text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
            text[i] = 'X';
        }
    }
    printf("The sentence with vowels replaced with 'X': %s", text);

    return 0;
}