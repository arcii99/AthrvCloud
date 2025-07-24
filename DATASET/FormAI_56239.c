//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include<stdio.h>

//function to calculate sentiment score of a sentence
int calculateScore(char * sentence){
    int score = 0, i = 0;
    while(sentence[i] != '\0'){
        if(sentence[i] == 'good' || sentence[i] == 'great' || sentence[i] == 'excellent' || sentence[i] == 'fantastic'){
            score += 2;
        }
        else if(sentence[i] == 'bad' || sentence[i] == 'poor' || sentence[i] == 'terrible' || sentence[i] == 'worst'){
            score -= 2;
        }
        else{
            score += 1;
        }
        i++;
    }
    return score;
}

int main(){
    //taking input from user
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    //calculating score of the sentence
    int score = calculateScore(sentence);

    //printing sentiment based on the score
    if(score > 0){
        printf("Positive Sentiment");
    }
    else if(score < 0){
        printf("Negative Sentiment");
    }
    else{
        printf("Neutral Sentiment");
    }

    return 0;
}