//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
   char text[1000];
   int happy = 0, sad = 0, angry = 0, neutral = 0;
   printf("Enter text to analyze:\n");
   fgets(text, 1000, stdin);
   char *word = strtok(text, " ,.!?");

   while (word != NULL) {
       if (strstr(word, "happy") != NULL || strstr(word, "joy") != NULL || strstr(word, "excited") != NULL) {
           happy++;
       } else if (strstr(word, "sad") != NULL || strstr(word, "unhappy") != NULL || strstr(word, "depressed") != NULL) {
           sad++;
       } else if (strstr(word, "angry") != NULL || strstr(word, "mad") != NULL || strstr(word, "outraged") != NULL) {
           angry++;
       } else {
           neutral++;
       }
       word = strtok(NULL, " ,.!?");   
   }
   printf("\nSentiment Analysis Results:\n");
   printf("Happy: %d\n", happy);
   printf("Sad: %d\n", sad);
   printf("Angry: %d\n", angry);
   printf("Neutral: %d\n", neutral);
   return 0;
}