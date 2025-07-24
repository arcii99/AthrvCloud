//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

//GLOBAL VARIABLES
#define MAX 5000 //maximum number of characters in input
#define MAXWORDS 1000 //maximum number of words in input
int Freq[MAXWORDS], order[MAXWORDS];
char Input[MAX], words[MAXWORDS][30], wordFreq[MAXWORDS][30];

/*FUNCTION DECLARATIONS*/

//to remove punctuation from the input
void RemovePunctuations(char str[]);

//converts all uppercase characters to lowercase
void ToLower(char str[]);

//tokenizes the input into individual words
int TokenizeInput(char Input[], char words[][30]);

//sorts words in descending order of frequency
void SortWords(int Freq[], int order[], int n);

//calculates frequency of each word in the input
void CalculateFrequency(char words[][30], int Freq[], int n);

//gives the final summary based on the top n most frequent words
void GenerateSummary(char words[][30], char wordFreq[][30], int order[], int n);

//MAIN FUNCTION
int main(){

    //input
    printf("Please enter the text you would like to summarize:\n");
    fgets(Input, MAX, stdin);

    //remove punctuations and convert to lowercase
    RemovePunctuations(Input);
    ToLower(Input);

    //tokenize the input into words and calculate frequency
    int n = TokenizeInput(Input, words);
    CalculateFrequency(words, Freq, n);

    //sort words in descending order of frequency and generate summary
    SortWords(Freq, order, n);
    GenerateSummary(words, wordFreq, order, 10);

    //exit
    return 0;
}

//FUNCTION DEFINITIONS

//to remove punctuation from the input
void RemovePunctuations(char str[]){
    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(ispunct(str[i])) str[i] = ' ';
    }
}

//converts all uppercase characters to lowercase
void ToLower(char str[]){
    int len = strlen(str);
    for(int i=0; i<len; i++){
        str[i] = tolower(str[i]);
    }
}

//tokenizes the input into individual words
int TokenizeInput(char Input[], char words[][30]){
    int i=0, j=0, k=0, n=0, len = strlen(Input);
    while(i<len){
        if(Input[i] == ' '){
            words[n][k] = '\0';
            n++;
            k=0;
        }
        else{
            words[n][k] = Input[i];
            k++;
        }
        i++;
    }
    words[n][k] = '\0';
    n++;
    return n;
}

//calculates frequency of each word in the input
void CalculateFrequency(char words[][30], int Freq[], int n){
    for(int i=0; i<n; i++) Freq[i] = 0;
    for(int i=0; i<n; i++){
        Freq[i]++;
        for(int j=i+1; j<n; j++){
            if(strcmp(words[i], words[j]) == 0){
                Freq[i]++;
                words[j][0] = '\0';
            }
        }
    }
}

//sorts words in descending order of frequency
void SortWords(int Freq[], int order[], int n){
    for(int i=0; i<n; i++) order[i] = i;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(Freq[order[i]] < Freq[order[j]]){
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }
}

//gives the final summary based on the top n most frequent words
void GenerateSummary(char words[][30], char wordFreq[][30], int order[], int n){
    printf("SUMMARY\n");
    for(int i=0; i<n; i++){
        strcpy(wordFreq[i], words[order[i]]);
        printf("%s ", wordFreq[i]);
    }
}