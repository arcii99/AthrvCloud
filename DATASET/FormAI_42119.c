//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include<stdio.h>
#include<string.h>

// Sentiment Analysis function
int sentimentAnalysis(char *sentence){
    int positive_words = 0, negative_words = 0;
    char positive_dict[10][20] = {"happy", "great", "love", "awesome", "excellent", "amazing", "fantastic", "beautiful", "nice", "joy"};
    char negative_dict[10][20] = {"sad", "bad", "hate", "terrible", "awful", "disgusting", "worst", "horrible", "angry", "miserable"};
    
    // Tokenizing the senetence
    char *token = strtok(sentence, " ");
    while(token != NULL){
        // Searching for positive words
        for(int i=0; i<10; i++){
            if(strcmp(token, positive_dict[i]) == 0){
                positive_words++;
                break;
            }
        }
        // Searching for negative words
        for(int i=0; i<10; i++){
            if(strcmp(token, negative_dict[i]) == 0){
                negative_words++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    
    // Calculating the sentiment score and returning
    int score = positive_words - negative_words;
    if(score > 0){
        return 1;
    }
    else if(score < 0){
        return -1;
    }
    else{
        return 0;
    }
}

// Main function to test the sentiment analysis tool
int main(){
    // Some examples of sentences to analyze
    char sentence1[100] = "I love the sunny weather in California and the beaches are amazing.";
    char sentence2[100] = "The food at this restaurant was terrible and the service was equally bad.";
    char sentence3[100] = "I am feeling so happy today, everything seems perfect.";
    char sentence4[100] = "This book is one of the worst I have ever read, it's a complete waste of time.";
    char sentence5[100] = "I'm so angry with my boss right now, he is always unfair to me.";
    
    // Analyzing the sentiment of the sentences
    int result1 = sentimentAnalysis(sentence1);
    int result2 = sentimentAnalysis(sentence2);
    int result3 = sentimentAnalysis(sentence3);
    int result4 = sentimentAnalysis(sentence4);
    int result5 = sentimentAnalysis(sentence5);
    
    // Printing the results
    printf("SENTENCE 1 = %s\nSENTIMENT SCORE = %d\n\n", sentence1, result1);
    printf("SENTENCE 2 = %s\nSENTIMENT SCORE = %d\n\n", sentence2, result2);
    printf("SENTENCE 3 = %s\nSENTIMENT SCORE = %d\n\n", sentence3, result3);
    printf("SENTENCE 4 = %s\nSENTIMENT SCORE = %d\n\n", sentence4, result4);
    printf("SENTENCE 5 = %s\nSENTIMENT SCORE = %d\n\n", sentence5, result5);
    
    return 0;
}