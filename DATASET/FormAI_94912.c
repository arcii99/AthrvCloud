//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

char word[MAX_WORDS][MAX_WORD_LENGTH] = {'\0'};  // array to store words
int freq[MAX_WORDS] = {0};  // array to store frequency count of words
int num_words = 0;

int is_in_word_array(char *word, int n){
    // function to check whether the word is already in the word array
    for(int i=0;i<n;i++){
        if(strcmp(word, word[i]) == 0){
            return i; // returns index of existing word
        }
    }
    return -1; // returns -1 if word does not exist in array
}

void add_word(char *word){
    // function to add word to the word array and update frequency count
    int index = is_in_word_array(word, num_words);
    if(index != -1){ // if word already exists
        freq[index]++; // increment frequency count
    }
    else{ // add new word to array
        strcpy(word[num_words], word);
        freq[num_words] = 1; // set frequency count to 1
        num_words++; // increment number of words
    }
}

int main(void){
    char c, input[MAX_WORD_LENGTH];
    int index = 0;

    FILE* file = fopen("input.txt", "r"); // open input file
    if(file == NULL){ // check if file exists
        printf("Input file does not exist. Exiting program.");
        return 1;
    }

    while((c = fgetc(file)) != EOF){ // read characters from file
        if(isalpha(c)){ // check if character is a letter
            input[index++] = tolower(c); // convert to lowercase and add to input string
        }
        else if(index > 0){ // if a word has been formed
            input[index] = '\0'; // terminate the input string
            add_word(input); // add the word to the word array and update frequency count
            index = 0; // reset input string index for new word
        }
    }

    fclose(file); // close input file

    // print word frequency counts
    for(int i=0;i<num_words;i++){
        printf("%s: %d\n", word[i], freq[i]);
    }
    return 0;
}