//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include<stdio.h>
#include<string.h>

int main() {
    char sentence[100];
    int positive=0,negative=0,neutral=0,i;
    printf("Enter your sentence: ");
    fgets(sentence,100,stdin);
    strtok(sentence,"\n");
    char *word=strtok(sentence," ");
    while(word!=NULL){
        i=0;
        while(word[i]){
            word[i]=tolower(word[i]);
            i++;
        }
        if(strcmp(word,"great")==0 || strcmp(word,"good")==0 || strcmp(word,"excellent")==0 || strcmp(word,"awesome")==0){
            positive++;
        }
        else if(strcmp(word,"bad")==0 || strcmp(word,"terrible")==0 || strcmp(word,"awful")==0 || strcmp(word,"poor")==0){
            negative++;
        }
        else{
            neutral++;
        }
        word=strtok(NULL," ");
    }
    if(positive>negative){
        printf("Positive sentiment.\n");
    }
    else if(negative>positive){
        printf("Negative sentiment.\n");
    }
    else{
        printf("Neutral sentiment.\n");
    }
    printf("Positive count: %d\nNegative count: %d\nNeutral count: %d",positive,negative,neutral);
    return 0;
}