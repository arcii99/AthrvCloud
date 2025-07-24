//FormAI DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main() {
    char word[100] = "Hello, world!";
    char new_word[100];
    int word_len = strlen(word);
    
    printf("Original Word: %s\n", word);
    
    // Reverse the word
    for(int i=0; i<word_len; i++) {
        new_word[i] = word[word_len - i - 1];
    }
    new_word[word_len] = '\0';
    
    printf("Reversed Word: %s\n", new_word);
    
    // Change all characters to uppercase
    for(int i=0; i<word_len; i++) {
        if(word[i] >= 'a' && word[i] <= 'z') {
            new_word[i] = word[i] - 'a' + 'A';
        }
        else {
            new_word[i] = word[i];
        }
    }
    new_word[word_len] = '\0';
    
    printf("Uppercase Word: %s\n", new_word);
    
    // Remove all vowels
    int j = 0;
    for(int i=0; i<word_len; i++) {
        if(word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u') {
            new_word[j] = word[i];
            j++;
        }
    }
    new_word[j] = '\0';
    
    printf("Word without Vowels: %s\n", new_word);
    
    // Replace all spaces with underscores
    for(int i=0; i<word_len; i++) {
        if(word[i] == ' ') {
            new_word[i] = '_';
        }
        else {
            new_word[i] = word[i];
        }
    }
    new_word[word_len] = '\0';
    
    printf("Word with Underscores: %s\n", new_word);
    
    return 0;
}