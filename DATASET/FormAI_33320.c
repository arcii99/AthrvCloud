//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_WORD_LENGTH 50 //Maximum length of a word
#define MAX_NUMBER_OF_WORDS 1000 //Maximum number of words to be counted

int getCWordFrequency(char text[], char words[][MAX_WORD_LENGTH], int frequency[]){
    int word_count = 0;
    char delimiters[] = " ,.-\n"; //define the boundaries of a word
    char *word;
  
    //Tokenize each word in the text and count their frequency
    word = strtok(text, delimiters); //get the first word in the text
    while (word != NULL) { //while there are still words in the text
        int i, match_found = 0;
        for (i = 0; i < word_count; ++i) { //search for a match in previous words
            if (strcmp(word, words[i]) == 0) {
                //match found, increment frequency counter for that word
                ++frequency[i];
                match_found = 1;
                break;
            }
        }
        if (!match_found) { //if no match found, add it as a new word
            strcpy(words[word_count], word);
            frequency[word_count] = 1;
            ++word_count;
            if (word_count == MAX_NUMBER_OF_WORDS) {
                break; //Maximum number of words reached
            }
        }
        word = strtok(NULL, delimiters); //get the next word in the text
    }
  
    return word_count;
}

int main(){
    char text[1000];
    char words[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int frequency[MAX_NUMBER_OF_WORDS];
    int i, j, word_count;
    printf("Enter some text (max length 1000 characters):\n");
    fgets(text, 1000, stdin);
  
    word_count = getCWordFrequency(text, words, frequency);
  
    //Display the frequency of each word
    printf("Word Frequency:\n");
    for (i = 0; i < word_count; ++i) { 
        printf("%s - %d\n", words[i], frequency[i]);
    }
  
    return 0;
}