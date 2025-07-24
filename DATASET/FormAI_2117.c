//FormAI DATASET v1.0 Category: Text Summarizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORDS 100000
#define MAX_LENGTH 200

//Structure for holding the unique word and its frequency
struct wordFrequency {
    char word[MAX_LENGTH];
    int frequency;
};

//Function to check if a given word is unique or not and update its frequency
int checkAndUpdate(char* word, struct wordFrequency* words, int index) {
    for(int i=0; i<index; i++) {
        if(strcmp(words[i].word, word) == 0) {
            words[i].frequency++;
            return 0;
        }
    }
    strcpy(words[index].word, word);
    words[index].frequency = 1;
    return 1;
}

//Function to sort the unique words based on frequency in descending order
void sortWords(struct wordFrequency* words, int size) {
    struct wordFrequency temp;
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(words[j].frequency < words[j+1].frequency) {
                temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }
}

int main() {
    char text[MAX_WORDS];
    printf("Enter the text to summarize: ");
    fgets(text, MAX_WORDS, stdin);

    //Splitting the text into words and checking if they are unique
    struct wordFrequency words[MAX_WORDS];
    int index = 0;
    char* word = strtok(text, " ,.;:\n");
    while(word != NULL) {
        checkAndUpdate(word, words, index);
        index++;
        word = strtok(NULL, " ,.;:\n");
    }

    //Sorting the unique words based on frequency
    sortWords(words, index);

    //Printing the top 10 most frequent words
    printf("\nTop 10 most frequent words:\n");
    for(int i=0; i<10 && i<index; i++) {
        printf("%d. %s (%d)\n", i+1, words[i].word, words[i].frequency);
    }

    return 0;
}