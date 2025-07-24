//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {

    char input[300];
    
    printf("Enter a sentence to analyze: ");
    fgets(input, 300, stdin);
    
    int length = strlen(input);
    int positiveScore = 0;
    int negativeScore = 0;
    int neutralScore = 0;
    
    for(int i = 0; i < length; i++){
        
        if((input[i] == 'g' || input[i] == 'G') && (input[i+1] == 'o' || input[i+1] == 'O') && (input[i+2] == 'o' || input[i+2] == 'O') && (input[i+3] == 'd' || input[i+3] == 'D')){
            positiveScore++;
        }
        else if((input[i] == 'b' || input[i] == 'B') && (input[i+1] == 'a' || input[i+1] == 'A') && (input[i+2] == 'd' || input[i+2] == 'D')){
            negativeScore++;
        }
        else if((input[i] == 'o' || input[i] == 'O') && (input[i+1] == 'k' || input[i+1] == 'K')){
            neutralScore++;
        }
    }
    
    printf("\nPositive score: %d", positiveScore);
    printf("\nNegative score: %d", negativeScore);
    printf("\nNeutral score: %d", neutralScore);
    
    if(positiveScore > negativeScore && positiveScore > neutralScore){
        printf("\nThe sentiment of the sentence is positive");
    }
    else if(negativeScore > positiveScore && negativeScore > neutralScore){
        printf("\nThe sentiment of the sentence is negative");
    }
    else{
        printf("\nThe sentiment of the sentence is neutral");
    }
    
    return 0;
}