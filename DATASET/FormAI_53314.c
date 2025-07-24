//FormAI DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100];
    printf("Enter some text for spell checking:\n");
    fgets(text, 100, stdin);
    
    char dictionary[10][20] = {"apple", "banana", "cherry", "orange", "grape", "strawberry", "kiwi", "plum", "lemon", "peach"};
    int num_words = 10;
    
    char word[20];
    int text_len = strlen(text);
    int word_len, i, j, found;
    int misspelled = 0;
    
    for (i = 0; i < text_len; i++) { //iterate through text
        if (isalnum(text[i])) { //if character is alphanumeric
            word_len = 0;
            while (isalnum(text[i])) { //read word into buffer
                word[word_len++] = tolower(text[i++]);
            }
            word[word_len] = '\0'; //terminate word string
            
            found = 0; //reset found flag
            for (j = 0; j < num_words && !found; j++) { //iterate through dictionary
                if (strcmp(word, dictionary[j]) == 0) { //compare word to dictionary entry
                    found = 1; //set found flag
                }
            }
            if (!found) { //if word not found in dictionary
                printf("Misspelled word: %s\n", word);
                misspelled++;
            }
        }
    }
    
    if (misspelled == 0) { //if no misspelled words
        printf("No misspelled words found.\n");
    }
    
    return 0;
}