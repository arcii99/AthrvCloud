//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: unmistakable
#include<stdio.h>
#include<string.h>

//function to check if given word is present in sentence or not
int checkWord(char sentence[], char word[]){
    char *pos;
    int index, wordLen;
    int sentenceLen = strlen(sentence);

    pos = strstr(sentence, word);
    if(pos == NULL){
        return 0;
    }
    index = pos - sentence;
    wordLen = strlen(word);

    //check if the given word is present as a separate word or as a part of another word
    if((index == 0 || sentence[index-1] == ' ') && 
    (index + wordLen == sentenceLen || sentence[index+wordLen] == ' ')){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char sentence[200];
    char word[50];
    int positiveCount = 0, negativeCount = 0, neutralCount = 0;

    //define the list of positive words
    char positiveWords[10][20] = {"great", "good", "wonderful", "fantastic", "excellent", "amazing", "superb", "perfect", "happy", "love"};

    //define the list of negative words
    char negativeWords[10][20] = {"bad", "horrible", "terrible", "poor", "disappointing", "sad", "unhappy", "angry", "hate", "dislike"};

    printf("Enter the sentence: ");
    fgets(sentence, 200, stdin);

    //convert the sentence to lowercase
    int i;
    for(i=0; sentence[i]!='\0'; i++){
        sentence[i] = tolower(sentence[i]);
    }

    //split the sentence into words and check each word
    char *token;
    token = strtok(sentence, " .,?!");

    while(token != NULL){
        int j;
        for(j=0; j<10; j++){
            if(checkWord(token, positiveWords[j])){
                positiveCount++;
            }
            else if(checkWord(token, negativeWords[j])){
                negativeCount++;
            }
        }
        token = strtok(NULL, " .,?!");
    }

    //if count of positive words is more, sentence is positive
    if(positiveCount > negativeCount){
        printf("Positive sentence!\n");
    }
    //if count of negative words is more, sentence is negative
    else if(negativeCount > positiveCount){
        printf("Negative sentence!\n");
    }
    //if both are same, sentence is neutral
    else{
        printf("Neutral sentence!\n");
    }

    return 0;
}