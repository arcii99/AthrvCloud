//FormAI DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define SIZE 1000

typedef struct {
    char word[MAX];
    int freq;
    char sentence[MAX];
}Word;

Word wordList[SIZE];
int numOfWords = 0;

void lowerString(char *string){
    int i = 0;
    while(string[i] != '\0'){
        if(string[i] >= 'A' && string[i] <= 'Z'){
            string[i] = string[i] + 32;
        }
        i++;
    }
}

int isDelimiter(char ch){
    if(ch == ' ' || ch == ',' || ch == '.' || ch == '\n' || ch == '\t'){
        return 1;
    }
    return 0;
}

void addWord(char *string, char *sentence){
    lowerString(string);

    int i = 0;
    while(i < numOfWords){
        if(strcmp(wordList[i].word, string) == 0){
            wordList[i].freq++;
            return;
        }
        i++;
    }

    strcpy(wordList[numOfWords].word, string);
    wordList[numOfWords].freq = 1;
    strcpy(wordList[numOfWords].sentence, sentence);

    numOfWords++;
}

void parseSentences(char *string){
    char sentence[MAX];
    int pos = 0;
    int len;

    len = strlen(string);

    for(int i = 0; i < len; i++){
        if(string[i] != '\n'){
            sentence[pos++] = string[i];
        }
        else{
            sentence[pos] = '\0';

            for(int j = 0; j < strlen(sentence); j++){
                if(sentence[j] == '.'){
                    sentence[j] = '\0';
                }
            }

            char *word = strtok(sentence, " ");
            while(word != NULL){
                if(!isDelimiter(word[0])){
                    addWord(word, sentence);
                }
                word = strtok(NULL, " ");
            }

            pos = 0;
        }
    }
}

void printSummary(){
    printf("----- Text Summary -----\n");

    int totalWords = 0;
    for(int i = 0; i < numOfWords; i++){
        totalWords += wordList[i].freq;
    }

    for(int i = 0; i < numOfWords; i++){
        printf("%s (%d/%d), occuring in sentence: %s\n", wordList[i].word, wordList[i].freq, totalWords, wordList[i].sentence);
    }

    printf("----- End of Summary -----\n");
}

int main(){
    char input[SIZE];

    printf("Enter text to summarize:\n");
    fgets(input, SIZE, stdin);

    parseSentences(input);
    printSummary();

    return 0;
}