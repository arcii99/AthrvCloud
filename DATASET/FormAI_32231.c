//FormAI DATASET v1.0 Category: Text Summarizer ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000

struct sentence{
    char words[MAX_SIZE];
    int frequency;
};

int main(){

    char input_text[MAX_SIZE];
    printf("Input text:\n");
    fgets(input_text,MAX_SIZE,stdin);

    //Tokenize text into sentences
    char *token=strtok(input_text,".?!");

    //Initialize structure array
    struct sentence sentences[MAX_SIZE];
    int count=0;

    //Loop through tokenized sentences to store them in structure
    while(token!=NULL){

        strcpy(sentences[count].words,token);
        sentences[count].frequency=1;

        count++;

        token=strtok(NULL,".?!");

    }

    //Loop through sentences to find word frequency
    for(int i=0;i<count;i++){

        //Tokenize sentence into words
        char *word_token=strtok(sentences[i].words," ,;:");

        //Loop through words to find frequency
        while(word_token!=NULL){

            for(int j=0;j<count;j++){

                if(i==j){
                    continue;
                }

                char *word_query=strtok(sentences[j].words," ,;:");
                while(word_query!=NULL){

                    if(strcmp(word_token,word_query)==0){
                        sentences[i].frequency++;
                    }

                    word_query=strtok(NULL," ,;:");
                }

            }

            word_token=strtok(NULL," ,;:");
        }

    }

    //Sort sentences based on frequency
    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
            if(sentences[i].frequency<sentences[j].frequency){
                struct sentence temp;
                temp=sentences[i];
                sentences[i]=sentences[j];
                sentences[j]=temp;
            }
        }
    }

    //Print top 3 sentences
    printf("\nSummary:\n");
    for(int i=0;i<3;i++){
        printf("%s ",sentences[i].words);
    }

    return 0;
}