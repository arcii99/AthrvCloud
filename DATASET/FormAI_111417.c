//FormAI DATASET v1.0 Category: Word Count Tool ; Style: satisfied
#include <stdio.h>
#include <string.h>

void count_words(char sentence[]) {
    int word_count = 0;
    char delimiters[] = " ,.?!";
    char* token = strtok(sentence, delimiters);
    
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, delimiters);
    }
    
    printf("The sentence '%s' has %d words.\n", sentence, word_count);
}

int main() {
    printf("Welcome to the Word Count Tool!\n");
    printf("Please enter a sentence:\n");
    
    char sentence[100];
    fgets(sentence, 100, stdin);
    
    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }
    
    count_words(sentence);
    
    return 0;
}