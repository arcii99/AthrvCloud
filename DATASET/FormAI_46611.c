//FormAI DATASET v1.0 Category: Text Summarizer ; Style: rigorous
#include<stdio.h>
#include<string.h>
#define MAX_SENTENCES 100 // Maximum number of sentences in the text
#define MAX_SENTENCE_LENGTH 1000 // Maximum length of a sentence

int main(){
    char text[MAX_SENTENCES][MAX_SENTENCE_LENGTH]; // 2D array to store the sentences
    char input[1000]; // to store the input text
    int sentenceCount=0, i, j, k;
    float score[MAX_SENTENCES]={0}; // array to store the score of each sentence
    printf("Enter the text:\n");
    fgets(input, 1000, stdin); // take input from the user
    for(i=0; i<strlen(input); i++){ // loop to extract the sentences from the input text
        if(input[i]=='.' || input[i]=='?' || input[i]=='!'){
            sentenceCount++;
            j=0;
            continue;
        }
        text[sentenceCount][j++]=input[i];
    }

    float maxScore;
    int maxIndex;
    int summaryIndex=0;
    while(summaryIndex<5){ // generate a summary of 5 sentences
        maxScore=0;
        for(i=0 ;i<sentenceCount; i++){ // loop through all the sentences to find the sentence with the highest score
            score[i]=0;
            for(j=0; j<sentenceCount; j++){ // calculate the score of each sentence
                if(i==j) continue;
                for(k=0; k<strlen(text[j]); k++){ // loop through the words of each sentence
                    if(strstr(text[i], &text[j][k])){
                        score[i]++;
                        break;
                    }
                }
            }
            if(score[i]>maxScore){ // update the maximum score and index of the sentence with the highest score
                maxScore=score[i];
                maxIndex=i;
            }
        }
        printf("%s ", text[maxIndex]); // print the sentence with the highest score
        summaryIndex++;
        score[maxIndex]=-1; // set the score of this sentence to -1 so that it is not considered again
    }
    return 0; // end the program
}