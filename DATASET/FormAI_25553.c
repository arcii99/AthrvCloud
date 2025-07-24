//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include<stdio.h>
#include<string.h>

void getSentiment(char str[200]);

int main(){
    char str[200];

    printf("Enter a sentence to analyze sentiment:\n");
    fgets(str, 200, stdin); // getting sentence from user

    getSentiment(str); // calling function to analyze sentiment

    return 0; 
}

void getSentiment(char str[200]){
    int i, score = 0; 

    char *positiveWords[] = {"good", "great", "amazing", "excellent", "fantastic", "superb", "awesome", "perfect", "wonderful", "happy", "joyful", "lovely", "nice", "pleased", "splendid", "delightful", "satisfied", "glad"};
    char *negativeWords[] = {"bad", "terrible", "horrible", "awful", "poor", "disappointing", "frustrating", "unfortunate", "displeasing", "miserable", "upset", "angry", "sad", "unhappy", "depressed", "regretful", "distressing"};

    // splitting sentence into words
    char *token = strtok(str, " ");

    while (token != NULL){
        for (i=0; i<18; i++){ // checking if word is in positiveWords[] array
            if (strcmp(token, positiveWords[i]) == 0){
                score++; 
            }
        }

        for (i=0; i<17; i++){ // checking if word is in negativeWords[] array
            if (strcmp(token, negativeWords[i]) == 0){
                score--; 
            }
        }

        token = strtok(NULL, " ");
    }

    printf("Sentiment score is %d.\n", score);
    if (score > 0){
        printf("The sentence is positive.\n");
    }
    else if (score < 0){
        printf("The sentence is negative.\n");
    }
    else{
        printf("The sentence is neutral.\n");
    }
}