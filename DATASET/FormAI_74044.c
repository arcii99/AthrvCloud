//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include<stdio.h>
#include<ctype.h>
#include<string.h>

//Function to calculate the sentiment score for a word
int getWordScore(char* word){
    int score = 0;
    //List of positive words with their scores
    char* positiveWords[] = {"good", "great", "excellent", "happy", "love"};
    int positiveScores[] = {1, 2, 3, 1, 3};
    //List of negative words with their scores
    char* negativeWords[] = {"bad", "terrible", "awful", "sad", "hate"};
    int negativeScores[] = {-1, -2, -3, -1, -3};
    //If word is positive, add its score to the overall sentiment score
    for(int i=0;i<5;i++){
        if(strcmp(word, positiveWords[i]) == 0){
            score += positiveScores[i];
            return score;
        }
    }
    //If word is negative, subtract its score from the overall sentiment score
    for(int i=0;i<5;i++){
        if(strcmp(word, negativeWords[i]) == 0){
            score += negativeScores[i];
            return score;
        }
    }
    return score;
}

int main(){
    char inputText[1000];
    printf("Enter the text to analyze: ");
    fgets(inputText, 1000, stdin);
    int score = 0;
    char* word = strtok(inputText, " ,.-");
    while(word != NULL){
        //Convert the word to lowercase to match positive and negative lists
        for(int i=0;i<strlen(word);i++){
            word[i] = tolower(word[i]);
        }
        int wordScore = getWordScore(word);
        score += wordScore;
        word = strtok(NULL, " ,.-");
    }
    printf("The sentiment score for the text is: %d\n", score);
    if(score > 0){
        printf("The sentiment of the text is positive\n");
    }
    else if(score < 0){
        printf("The sentiment of the text is negative\n");
    }
    else{
        printf("The sentiment of the text is neutral\n");
    }
    return 0;
}