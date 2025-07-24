//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <string.h>

int main() {
   char input[500]; //initialize input array
   int happy = 0, sad = 0, neutral = 0, sentimentScore = 0; //initialize variables
   
   printf("Enter text to analyze sentiment: "); //prompt user for input
   fgets(input, 500, stdin); //get input
   
   char *happyWords[] = {"happy", "joyful", "fantastic", "excited", "delighted"}; //initialize array of happy words
   char *sadWords[] = {"sad", "depressed", "unhappy", "miserable", "gloomy"}; //initialize array of sad words
   
   char *token = strtok(input, " "); //tokenize input by space delimiter
   
   while(token != NULL) {
      for(int i=0; i<5; i++) {
         if(strcmp(token, happyWords[i]) == 0) //if token matches happy word
            happy++;
         else if(strcmp(token, sadWords[i]) == 0) //if token matches sad word
            sad++;
      }
      token = strtok(NULL, " "); //move to next token
   }
   
   neutral = strlen(input) - happy - sad; //calculate number of neutral words
   
   sentimentScore = (happy - sad) * 10; //calculate sentiment score
   
   printf("\nSentiment Analysis Results:\n");
   printf("Positive Words: %d\n", happy); //print number of positive words
   printf("Negative Words: %d\n", sad); //print number of negative words
   printf("Neutral Words: %d\n", neutral); //print number of neutral words
   
   if(sentimentScore > 0)
      printf("Sentiment Score: +%d\n", sentimentScore); //if sentiment is positive
   else if(sentimentScore < 0)
      printf("Sentiment Score: %d\n", sentimentScore); //if sentiment is negative
   else
      printf("Sentiment Score: 0\n"); //if sentiment is neutral
   
   return 0;
}