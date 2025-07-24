//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char word[100];
    int i, j; 
    printf("Enter a word (or phrase): ");
    fgets(word, 100, stdin); // read input from user
    
    char word_copy[100]; // making a copy of the original word
    strcpy(word_copy, word);
    for (i = 0, j = strlen(word_copy) - 1; i < j; i++, j--) {
        char temp = word_copy[i];
        
        if (ispunct(temp) || isspace(temp)) {
            i--; // skip punctuation or spaces
            continue;
        }

        word_copy[i] = word_copy[j];
        word_copy[j] = temp;
    }

    // check if the word and the reversed word are the same
    if (strcmp(word, word_copy) == 0) {
        printf("%s is a palindrome!\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }
 
    return 0;
}