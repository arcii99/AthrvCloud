//FormAI DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_ENTRIES 10000

typedef struct{
    char word[MAX_WORD_LENGTH+1];
    int frequency;
} dictEntry;

dictEntry dictionary[MAX_DICT_ENTRIES];
int numEntries = 0;

void addToDictionary(char* word){
    int i;
    for(i=0; i<numEntries; i++){
        if(strcmp(dictionary[i].word, word) == 0){
            dictionary[i].frequency++;
            return;
        }
    }
    if(numEntries < MAX_DICT_ENTRIES){
        strcpy(dictionary[numEntries].word, word);
        dictionary[numEntries].frequency = 1;
        numEntries++;
    }
}

int isInDictionary(char* word){
    int i;
    for(i=0; i<numEntries; i++){
        if(strcmp(dictionary[i].word, word) == 0)
            return 1;
    }
    return 0;
}

int isLetter(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int isDigit(char c){
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

int isAlphaNumeric(char c){
    if(isLetter(c) || isDigit(c))
        return 1;
    return 0;
}

void toLowerCase(char* word){
    int i;
    for(i=0; word[i]!='\0'; i++){
        if(isLetter(word[i]))
            word[i] = tolower(word[i]);
    }
}

void checkSpelling(char* document){
    char word[MAX_WORD_LENGTH+1];
    int i, j, k;
    int inWord = 0;
    int documentLength = strlen(document);
    for(i=0, j=0; j<=documentLength; j++){
        if(isAlphaNumeric(document[j])){
            if(!inWord){
                inWord = 1;
                k = 0;
            }
            word[k] = document[j];
            k++;
        }
        else{
            if(inWord){
                inWord = 0;
                word[k] = '\0';
                toLowerCase(word);
                if(!isInDictionary(word))
                    printf("Misspelled word: %s\n", word);
                addToDictionary(word);
            }
        }
    }
}

int main(){
    char document[] = "This text conatains some speling errors. Can you find them?";
    checkSpelling(document);
    return 0;
}