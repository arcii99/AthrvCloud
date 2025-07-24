//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ada Lovelace
/**
* This groundbreaking Sentiment Analysis program will revolutionize the way we perceive and analyze language 
* Written in honor of Ada Lovelace
**/

#include <stdio.h>
#include <string.h>

/* Define function to calculate positive score */

float positive_score(char *string) {

   /* Define list of positive words */
   char *positive_words[5] = {"happy", "laugh", "love", "excite", "success"};

   int count = 0;
   char *word = strtok(string, " ");

   /* Loop through each word in the input string */
   while(word != NULL) {
       /* Compare each word to our list of positive words */
       for(int i=0; i<5; i++) {
           if(strcmp(word, positive_words[i]) == 0) {
               count++;
           }
       }
       word = strtok(NULL, " ");
   }

   /* Calculate and return positive score */
   float positive_score = (float)count / (float)strlen(string);
   return positive_score;
}

/* Define function to calculate negative score */

float negative_score(char *string) {

   /* Define list of negative words */
   char *negative_words[5] = {"hate", "sad", "fail", "angry", "disappoint"};

   int count = 0;
   char *word = strtok(string, " ");

   /* Loop through each word in the input string */
   while(word != NULL) {
       /* Compare each word to our list of negative words */
       for(int i=0; i<5; i++) {
           if(strcmp(word, negative_words[i]) == 0) {
               count++;
           }
       }
       word = strtok(NULL, " ");
   }

   /* Calculate and return negative score */
   float negative_score = (float)count / (float)strlen(string);
   return negative_score;
}

/* Define main function */

int main() {

   /* Prompt user for input */
   printf("Please enter a sentence to analyze:\n");

   /* Read input from user */
   char input[100];
   fgets(input, 100, stdin);

   /* Calculate positive and negative scores */
   float positive = positive_score(input);
   float negative = negative_score(input);

   /* Print results */
   printf("Positive score: %.2f\n", positive);
   printf("Negative score: %.2f\n", negative);

   /* Determine overall sentiment based on scores */
   if(positive > negative) {
       printf("This sentence has a positive sentiment!\n");
   }
   else if(negative > positive) {
       printf("This sentence has a negative sentiment.\n");
   }
   else {
       printf("This sentence has a neutral sentiment.\n");
   }

   return 0;
}