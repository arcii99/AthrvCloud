//FormAI DATASET v1.0 Category: Text Summarizer ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SENTENCES 1000
#define MAX_LINE 200

struct Sentence{
    char line[MAX_LINE];
    float score;
};

int main(){
    char text[MAX_SENTENCES][MAX_LINE];
    struct Sentence sentenceArray[MAX_SENTENCES];
    int count = 0, sentenceCount = 0; 

    printf("Enter the text you want to summarize:\n");

    while(count < MAX_SENTENCES && fgets(text[count], MAX_LINE, stdin)){
        count++;
    }

    sentenceCount = count;

    // spliting the text by sentence and storing it in lower case
    for(int i = 0; i < count; i++){
        char *token = strtok(text[i], ".!?");
        while(token != NULL){
            int length = strlen(token);
            for(int j = 0; j < length; j++){
                token[j] = tolower(token[j]);
            }
            strcpy(sentenceArray[i].line, token);
            sentenceArray[i].score = 0;
            sentenceCount++;
            token = strtok(NULL, ".!?");
        }
    }

    //calculating the score of each sentence
    for(int i = 0; i < sentenceCount; i++){
        char *word = strtok(sentenceArray[i].line, " ");
        while(word != NULL){
            if(!strcmp(word, "amazing") || !strcmp(word, "fantastic") || !strcmp(word, "great") || !strcmp(word, "beautiful")){
                sentenceArray[i].score += 2;
            }
            else if(!strcmp(word, "good") || !strcmp(word, "nice") || !strcmp(word, "cool") || !strcmp(word, "excellent")){
                sentenceArray[i].score += 1;
            }
            word = strtok(NULL, " ");
        }
    }

    //sorting the sentences according to the score
    for(int i = 0; i < sentenceCount-1; i++){
        for(int j = 0; j < sentenceCount-i-1; j++){
            if(sentenceArray[j].score < sentenceArray[j+1].score){
                struct Sentence temp = sentenceArray[j];
                sentenceArray[j] = sentenceArray[j+1];
                sentenceArray[j+1] = temp;
            }
        }
    }

    printf("\nSummary of the Text:\n\n");

    //printing the top 5 sentences
    for(int i = 0; i < 5; i++){
        printf("%s.\n", sentenceArray[i].line);
    }

    return 0;
}