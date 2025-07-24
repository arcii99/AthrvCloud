//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: paranoid
#include<stdio.h>
#include<string.h>

int main(){
    char text[100];
    printf("Enter a sentence: ");
    fgets(text, 100, stdin);

    //extracting keywords
    char keywords[10][10] = {"hate", "kill", "dangerous", "liar", "steal", "cheat", "pain", "evil", "poison", "attack"};

    //counting the frequency of keywords in the sentence
    int freq[10] = {0};
    char* token = strtok(text, ".,!?");
    while(token!=NULL){
        for(int i=0; i<10; i++){
            if(strstr(token, keywords[i])!=NULL){
                freq[i]++;
            }
        }
        token = strtok(NULL, ".,!?");
    }

    //determining sentiment
    int count = 0;
    for(int i=0; i<10; i++){
        if(freq[i]>0){
            count++;
        }
    }

    if(count>5){
        printf("\nParanoid Sentiment Detected\n");
    }
    else{
        printf("\nNormal Sentiment Detected\n");
    }

    return 0;
}