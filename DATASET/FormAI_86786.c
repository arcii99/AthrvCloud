//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: creative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char input[1000];
    printf("Enter a sentence: ");
    fgets(input,1000,stdin);

    int sentiment = 0; //initialize sentiment score to 0
    int words = 1;     //initialize word count to 1

    for(int i=0;i<strlen(input);i++){
        if(input[i]==' ' || input[i]=='\n' || input[i]=='\t'){ //check if a new word has started
            words++;                                           //if yes, increment the word count
        }
        if(input[i]=='!' || input[i]=='.' || input[i]=='?'){   //check if end of sentence has been reached
            if(sentiment > 2*words){                           //if positive sentiment is greater than twice the number of words, print 'very positive'
                printf("Sentiment: Very Positive");
            }
            else if(sentiment > words){                        //if positive sentiment is more than number of words, print 'positive'
                printf("Sentiment: Positive");
            }
            else if(sentiment == words){                       //if positive sentiment is same as number of words, print 'neutral'
                printf("Sentiment: Neutral");
            }
            else if(sentiment > -1*words){                      //if negative sentiment is more than negative of number of words, print 'negative'
                printf("Sentiment: Negative");
            }
            else if(sentiment > -2*words){                      //if negative sentiment is more than twice the negative of number of words, print 'very negative'
                printf("Sentiment: Very Negative");
            }
            else{                                               //if none of the above conditions are satisfied, print 'neutral'
                printf("Sentiment: Neutral");
            }
            break;                                              //exit the loop after reaching the end of sentence
        }
        if(input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u' || input[i]=='A' || 
           input[i]=='E' || input[i]=='I' || input[i]=='O' || input[i]=='U'){ //check if vowel is present in current character
            sentiment++;                                                        //if yes, increment sentiment score
        }
        else if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z')){ //check if current character is an alphabet
            sentiment--;                                                               //if yes, decrement sentiment score
        }
    }

    return 0;
}