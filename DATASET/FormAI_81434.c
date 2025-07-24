//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define positive 1
#define negative 0

int main(){

    char sentence[500];
    int positive_count=0,negative_count=0;
    char *positive_words[10]={"good","happy","awesome","like","love","excellent","fantastic","great","perfect","superb"};
    char *negative_words[10]={"bad","sad","terrible","hate","awful","poor","worst","disappointing","horrible","disgusting"};

    printf("Enter a sentence:\n");
    fgets(sentence,500,stdin);

    char *token=strtok(sentence," ");

    while(token != NULL){
        for(int i=0;i<10;i++){
            if(strcmp(token,positive_words[i])==0){
                positive_count++;
            }
            if(strcmp(token,negative_words[i])==0){
                negative_count++;
            }
        }
        token=strtok(NULL," ");  
    }

    if(positive_count>negative_count){
        printf("The sentence is positive\n");
    }else if(positive_count<negative_count){
        printf("The sentence is negative\n");
    }else{
        printf("The sentence is neutral\n");
    }
    
    return 0;
}