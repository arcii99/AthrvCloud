//FormAI DATASET v1.0 Category: Text Summarizer ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_INPUT_SIZE 100000    // maximum length of input text
#define MAX_OUTPUT_SIZE 10000    // maximum length of summarized text

// function to remove punctuation from the input text
void removePunctuation(char* str){
    int len = strlen(str);
    for (int i = 0; i<len; i++){
        if (ispunct(str[i])){
            memmove(&str[i], &str[i + 1], len - i);
            len--;
            i--;
        }
    }
}

// function to count the occurence of each word in the input text
void countWords(char* str, int* freq){
    char* word = strtok(str, " ");
    while (word != NULL){
        freq[strlen(word)]++;
        word = strtok(NULL, " ");
    }
}

// main function
int main(){
    char input[MAX_INPUT_SIZE], output[MAX_OUTPUT_SIZE];    // strings to hold input and output text
    int wordFreq[1000] = {0}; // array to hold the frequency of each word

    // get the input text from the user
    printf("Please enter the text to be summarized:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;

    // remove punctuation from the input text
    removePunctuation(input);

    // count the occurrence of each word in the input text
    countWords(input, wordFreq);

    // summarize the text by selecting the most common words
    printf("The summarized text is:\n");
    char* word = strtok(input, " ");
    while (word != NULL && strlen(output)<MAX_OUTPUT_SIZE){
        if (wordFreq[strlen(word)] >= 2){
            strcat(output, word);
            strcat(output, " ");
            wordFreq[strlen(word)] = 0;
        }
        word = strtok(NULL, " ");
    }
    printf("%s\n", output);

    return 0;
}