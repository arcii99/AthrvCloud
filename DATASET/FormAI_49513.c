//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: automated
#include <stdio.h>
#include <string.h>

// function for sentiment analysis
void sentiment_analysis(char str[]){

    // calculating the length of the input string
    int len = strlen(str);

    // initializing variables for sentiment tracking
    int pos_count = 0, neg_count = 0, neu_count = 0;

    // analyzing the input string character by character
    for(int i=0; i<len; i++){

        // check for positive words
        if( (str[i]=='g' && str[i+1]=='o' && str[i+2]=='o' && str[i+3]=='d') || 
            (str[i]=='n' && str[i+1]=='i' && str[i+2]=='c' && str[i+3]=='e') || 
            (str[i]=='h' && str[i+1]=='a' && str[i+2]=='p' && str[i+3]=='p' && str[i+4]=='y') ){
                pos_count++; // incrementing positive count
        }

        // check for negative words
        else if( (str[i]=='b' && str[i+1]=='a' && str[i+2]=='d') || 
                 (str[i]=='s' && str[i+1]=='a' && str[i+2]=='d') || 
                 (str[i]=='h' && str[i+1]=='u' && str[i+2]=='r' && str[i+3]=='t') ){
            neg_count++; // incrementing negative count
        }

        // check for neutral words
        else if( (str[i]=='i' && str[i+1]=='s' && str[i+2]==' ' && str[i+3]=='a' && str[i+4]==' ') || 
                 (str[i]=='w' && str[i+1]=='a' && str[i+2]=='s' && str[i+3]==' ' && str[i+4]=='a' && str[i+5]=='n' && str[i+6]=='d' && str[i+7]==' ' && str[i+8]=='i' && str[i+9]=='s') ){
            neu_count++; // incrementing neutral count
        }

    }

    // printing the sentiment analysis report
    printf("\nSentiment Analysis Report:\n");
    printf("==========================\n");
    printf("Positive Count: %d\n", pos_count);
    printf("Negative Count: %d\n", neg_count);
    printf("Neutral Count: %d\n", neu_count);

    // finding the overall sentiment
    if(pos_count > neg_count && pos_count > neu_count){
        printf("\nThe input has Positive Sentiment");
    }
    else if(neg_count > pos_count && neg_count > neu_count){
        printf("\nThe input has Negative Sentiment");
    }
    else{
        printf("\nThe input has Neutral Sentiment");
    }
}

int main(){

    // initializing the input string
    char str[100];

    // getting the input from the user
    printf("Enter the string that needs to be analyzed: ");
    fgets(str, sizeof(str), stdin);

    // performing sentiment analysis
    sentiment_analysis(str);

    return 0;
}