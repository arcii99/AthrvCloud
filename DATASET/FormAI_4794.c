//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: ephemeral
#include<stdio.h>
#include<string.h>

//function to calculate sentiment score
int sentimentScore(char sentence[]) {
    int score = 0;
    int len = strlen(sentence);
    
    //positive words
    char *posWords[] = {"good", "happy", "love", "excellent", "awesome", "great", "best", "fantastic"};
    int numPosWords = 8;
    
    //negative words
    char *negWords[] = {"bad", "sad", "hate", "terrible", "awful", "horrible", "worst", "disgusting"};
    int numNegWords = 8;
    
    //checking for positive words
    for(int i=0; i<len; i++) {
        if(sentence[i] >= 'A' && sentence[i] <= 'Z') {
            sentence[i] += 32;
        }
        
        if(sentence[i] == ' ') {
            for(int j=0; j<numPosWords; j++) {
                if(strncmp(sentence+i+1, posWords[j], strlen(posWords[j])) == 0) {
                    score++;
                    break;
                }
            }
            for(int j=0; j<numNegWords; j++) {
                if(strncmp(sentence+i+1, negWords[j], strlen(negWords[j])) == 0) {
                    score--;
                    break;
                }
            }
        }
    }
    
    return score;
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    
    int score = sentimentScore(sentence);
    
    printf("Sentiment score: %d\n", score);
    
    if(score > 0) {
        printf("Positive sentiment!\n");
    } else if(score < 0) {
        printf("Negative sentiment!\n");
    } else {
        printf("Neutral sentiment!\n");
    }
    
    return 0;
}