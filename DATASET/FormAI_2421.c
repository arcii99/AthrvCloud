//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: configurable
#include<stdio.h>
#include<string.h>

//Defining the maximum length of sentence that this program can handle
#define MAX_LEN 100

//Function to calculate sentiment score of the given sentence using configurable weights
int calculateSentimentScore(char sentence[MAX_LEN], float pos_weight, float neg_weight, float neutral_weight){
    int pos_score=0, neg_score=0;
    int total_score = 0;

    //Converting the sentence to all lower case characters
    for(int i=0; sentence[i]; i++){
        sentence[i] = tolower(sentence[i]);
    }

    //Tokenizing the sentence on the basis of spaces
    char *token = strtok(sentence, " ");

    while(token != NULL){

        //Checking if any of the positive keywords appear in the token
        if(strstr("good great nice excellent", token)!=NULL){
            pos_score++;
        }

        //Checking if any of the negative keywords appear in the token
        if(strstr("bad worst not good poor", token)!=NULL){
            neg_score++;
        }

        token = strtok(NULL, " ");
    }

    //Calculating the total sentiment score of the sentence
    total_score = (pos_weight * pos_score) - (neg_weight * neg_score) + (neutral_weight * (strlen(sentence) - pos_score - neg_score));

    return total_score;
}

//Main function
int main(){

    char sentence[MAX_LEN] = "";
    float pos_weight = 1.5, neg_weight = 1.0, neutral_weight = 0.5;
    int sentiment_score = 0;

    //Taking user input for the sentence that needs to be analyzed
    printf("Enter the sentence: ");
    fgets(sentence, MAX_LEN, stdin);

    //Calculating the sentiment score of the given sentence
    sentiment_score = calculateSentimentScore(sentence, pos_weight, neg_weight, neutral_weight);

    //Printing the sentiment score of the sentence
    printf("The sentiment score of the given sentence is: %d\n", sentiment_score);

    return 0;
}