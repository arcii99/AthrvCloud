//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include<stdio.h>
#include<string.h>

// Function to calculate sentiment score of a sentence
int sentiment_score_calculator(char sentence[]){
    char positive_words[10][15]={"happy", "good", "great", "awesome", "excellent", "fantastic", "love", "like", "amazing", "fun"};
    char negative_words[10][15]={"sad", "bad", "terrible", "horrible", "awful", "dislike", "hate", "angry", "bored", "annoyed"};
    int positive_count=0, negative_count=0, score;

    // Checking for the presence of positive and negative words in the sentence
    for(int i=0;i<strlen(sentence);i++){
        if(sentence[i]==' ' || sentence[i]=='.' || sentence[i]==',' || sentence[i]=='\n'){
            for(int j=0;j<10;j++){
                if(strncmp(sentence+i+1, positive_words[j], strlen(positive_words[j]))==0){
                    positive_count++;
                }
                if(strncmp(sentence+i+1, negative_words[j], strlen(negative_words[j]))==0){
                    negative_count++;
                }
            }
        }
    }

    score = positive_count - negative_count; // Calculating sentiment score
    return score;
}

// Main function
int main(){
    char sentence[100];

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    int sentiment_score = sentiment_score_calculator(sentence);

    // Assigning sentiments based on the score
    if(sentiment_score>0){
        printf("The given sentence has a positive sentiment with score %d", sentiment_score);
    }
    else if(sentiment_score<0){
        printf("The given sentence has a negative sentiment with score %d", sentiment_score);
    }
    else{
        printf("The given sentence is neutral with score %d", sentiment_score);
    }

    return 0;
}