//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main(){
    char sentence[1000];
    int positive_count = 0, negative_count = 0;
    float positivity_percentage, negativity_percentage;

    printf("Enter a sentence: ");
    fgets(sentence,sizeof(sentence),stdin); // get input from user

    int length = strlen(sentence);
    sentence[length-1] = '\0'; // removing the new line character from string

    char* token = strtok(sentence," "); // tokenizing the sentence by space

    while(token != NULL){
        if(strcmp(token,"good")==0 || strcmp(token,"great")==0 || strcmp(token,"happy")==0 || strcmp(token,"love")==0 || strcmp(token,"excellent")==0){
            positive_count++;
        }
        else if(strcmp(token,"bad")==0 || strcmp(token,"worst")==0 || strcmp(token,"sad")==0 || strcmp(token,"hate")==0 || strcmp(token,"terrible")==0){
            negative_count++;
        }
        token = strtok(NULL," ");
    }
    positivity_percentage = (float)positive_count*100/(positive_count+negative_count); // calculating percentage of positivity
    negativity_percentage = (float)negative_count*100/(positive_count+negative_count); // calculating percentage of negativity

    if(positivity_percentage > negativity_percentage){
        printf("This sentence has %f%% positivity. It is a positive sentence.\n", positivity_percentage);
    }
    else{
        printf("This sentence has %f%% negativity. It is a negative sentence.\n", negativity_percentage);
    }

    return 0; // exit
}