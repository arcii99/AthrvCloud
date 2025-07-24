//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * Cryptic Text Summarizer (CTS) Program 
 */

#define MAX_LINE 1000   // Maximum length of a line
#define MAX_CHAR 5000   // Maximum length of a document
#define MAX_SENT 100    // Maximum number of sentences in a document
#define MAX_WORD 1000   // Maximum number of words in a sentence

// Function to tokenize a sentence into words
int tokenize(char *sentence, char words[][MAX_LINE]){
    int i=0, j=0, k=0;
    while(sentence[i] != '\0'){
        if(sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t'){
            words[j][k] = '\0';
            j++;
            k=0;
        }
        else{
            words[j][k] = sentence[i];
            k++;
        }
        i++;
    }
    words[j][k] = '\0';
    return j+1;
}

// Function to remove punctuations from a word
void removePunctuations(char *word){
    int i=0, j=0;
    while(word[i] != '\0'){
        if(word[i] >= 'a' && word[i] <= 'z'){
            word[j] = word[i];
            j++;
        }
        i++;
    }
    word[j] = '\0';
}

// Function to check if a word is a stopword
int isStopword(char *word){
    char *stopWords[] = {"the", "a", "an", "in", "on", "at", "to", "for", "from", "of"};
    int count = sizeof(stopWords)/sizeof(stopWords[0]);
    int i=0;
    for(i=0; i<count; i++){
        if(strcmp(word, stopWords[i]) == 0){
            return 1;
        }
    }
    return 0;
}

// Function to summarize a document
void summarize(char *document, int summarySize){
    char sentences[MAX_SENT][MAX_CHAR];        // Array to store sentences of the document
    char words[MAX_SENT][MAX_WORD][MAX_LINE];  // Array to store words of each sentence
    int sentenceCount = 0;                     // Count of total sentences in the document
    int wordCount[MAX_SENT];                   // Count of total words in each sentence
    char summary[MAX_CHAR] = "";               // Summary of the document

    // Tokenizing document into sentences
    int i=0, j=0, k=0;
    while(document[i] != '\0' && sentenceCount < MAX_SENT){
        if(document[i]=='.' || document[i]=='?' || document[i]=='!'){
            sentences[sentenceCount][k] = document[i];
            sentences[sentenceCount][k+1] = '\0';
            sentenceCount++;
            k=0;
        }
        else{
            sentences[sentenceCount][k] = document[i];
            k++;
        }
        i++;
    }

    // Tokenizing each sentence into words
    for(i=0; i<sentenceCount; i++){
        wordCount[i] = tokenize(sentences[i], words[i]);
    }

    // Removing stopwords and counting total unique words in each sentence
    int uniqueCount[MAX_SENT] = {0};
    for(i=0; i<sentenceCount; i++){
        for(j=0; j<wordCount[i]; j++){
            removePunctuations(words[i][j]);
            if(!isStopword(words[i][j])){
                uniqueCount[i]++;
            }
        }
    }

    // Selecting top sentences for summary
    int selectedCount = 0, currentCount = 0;
    int selectedSentences[MAX_SENT] = {0};
    while(selectedCount < summarySize){
        int maxCount = 0, maxIndex = -1;
        for(i=0; i<sentenceCount; i++){
            if(!selectedSentences[i]){
                if(uniqueCount[i] > maxCount){
                    maxCount = uniqueCount[i];
                    maxIndex = i;
                }
            }
        }
        if(maxIndex != -1){
            selectedSentences[maxIndex] = 1;
            selectedCount++;
            currentCount += uniqueCount[maxIndex];
            strcat(summary, sentences[maxIndex]);
        }
        else{
            break;
        }
    }

    // Printing the summary
    printf("%s", summary);
}


// Main function to execute the program
int main(){
    char document[MAX_CHAR] = "The quick brown fox jumps over the lazy dog. The quick brown fox is a very energetic animal. The lazy dog does not like to run or jump. The quick brown fox is always in a hurry. The lazy dog likes to sleep all day. ";
    int summarySize = 3;
    summarize(document, summarySize);
    return 0;
}