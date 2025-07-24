//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include<stdio.h>
#include<string.h>

int main(){
    char input[200]; //initialize a character array to store user input
    int happyCount=0, sadCount=0, neutralCount=0; //initialize counters for happy, sad, and neutral words
    char happyWords[][20]={"happy", "joyful", "excited", "pleased", "delighted", "elated"};
    char sadWords[][20]={"sad", "depressed", "miserable", "downcast", "gloomy", "disheartened"};
    
    printf("Enter a statement to be analyzed: ");
    fgets(input, sizeof(input), stdin); //get user input from the console
    
    char *token=strtok(input, " "); //parse the input into tokens
    
    while(token!=NULL){
        //iterate through each token and check if it matches any happy or sad words
        for(int i=0; i<6; i++){
            if(strcmp(token, happyWords[i])==0){
                happyCount++;
                break;
            }
            else if(strcmp(token, sadWords[i])==0){
                sadCount++;
                break;
            }
            else{
                neutralCount++;
                break;
            }
        }
        token=strtok(NULL, " "); //move to the next token
    }
    
    if(happyCount>sadCount){ //if there are more happy words than sad words
        printf("The statement is positive.\n");
    }
    else if(sadCount>happyCount){ //if there are more sad words than happy words
        printf("The statement is negative.\n");
    }
    else{ //if there are an equal number of happy and sad words
        printf("The statement is neutral.\n");
    }
    
    return 0;
}