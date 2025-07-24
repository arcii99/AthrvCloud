//FormAI DATASET v1.0 Category: Text processing ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {

    // initialize variables
    char sentence[1000];
    char word[50];
    int count = 0;
    
    // ask user to input sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // ask user for word to search for
    printf("Enter a word to search for: ");
    scanf("%s", word);

    // remove \n character from sentence input
    sentence[strcspn(sentence, "\n")] = 0;

    // count occurrences of word in sentence
    char *ptr = strstr(sentence, word);
    while (ptr != NULL) {
        count++;
        ptr = strstr(ptr + 1, word);
    }

    // display output
    printf("The word '%s' appears %d times in the sentence.\n", word, count);

    return 0;
}