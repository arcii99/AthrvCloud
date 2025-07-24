//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Linus Torvalds
#include<stdio.h>
#include<string.h>

int main(){
   char text[1000];
   int positive = 0, negative = 0, neutral = 0;
   printf("Enter your text for sentiment analysis: ");
   fgets(text, 1000, stdin);

   //Converting all letters to lowercase
   for(int i = 0; i < strlen(text); i++){
      text[i] = tolower(text[i]);
   }  
  
   //Checking each word for sentiment and recording sentiment count
   char *token = strtok(text, " ");
   while(token != NULL){
      if(strcmp(token, "good") == 0 || strcmp(token, "great") == 0 || strcmp(token, "excellent") == 0 || strcmp(token, "awesome") ==0){
         positive++;
      }
      else if(strcmp(token, "bad") == 0 || strcmp(token, "terrible") == 0 || strcmp(token, "awful") == 0 || strcmp(token, "poor") == 0){
         negative++;
      }
      else{
         neutral++;
      }
      token = strtok(NULL, " ");
   }
   
   //Displaying the sentiment analysis report
   printf("\nSentiment Analysis Report:\n");
   printf("Positive: %d\n", positive);
   printf("Negative: %d\n", negative);
   printf("Neutral: %d\n", neutral);

   return 0;
}