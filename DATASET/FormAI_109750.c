//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char input[500]; // We will take input text of maximum 500 characters
   int happy_score = 0, angry_score = 0, sad_score = 0; // Initializing sentiment scores

   printf("My dear user, please enter your text:\n");
   fgets(input, 500, stdin); // Reading the input text from the user
  
   // String comparison for happy words
   if (strstr(input, "love") || strstr(input, "happy") || strstr(input, "joy")) {
       happy_score += 2;
   } 
   if (strstr(input, "laughter") || strstr(input, "smile") || strstr(input, "fun")) {
       happy_score += 1;
   }
  
   // String comparison for angry words
   if (strstr(input, "hate") || strstr(input, "disgust") || strstr(input, "angry")) {
       angry_score += 2;
   } 
   if (strstr(input, "frustration") || strstr(input, "irritation") || strstr(input, "annoy")) {
       angry_score += 1;
   }
  
   // String comparison for sad words
   if (strstr(input, "depressed") || strstr(input, "grief") || strstr(input, "loss")) {
       sad_score += 2;
   } 
   if (strstr(input, "lonely") || strstr(input, "solitude") || strstr(input, "isolated")) {
       sad_score += 1;
   }
  
   // Results based on sentiment scores
   printf("\nMy dear user, the results are in:\n");
   if (happy_score > angry_score && happy_score > sad_score) {
       printf("The sentiment of your text is very lovely,\nAs though you are carrying an enchanting melody.\n");
   } 
   else if (angry_score > happy_score && angry_score > sad_score) {
       printf("Oh! Your text is quite angry,\nAs though the world has left you feeling tangy.\n");
   } 
   else if (sad_score > happy_score && sad_score > angry_score) {
       printf("Alas, your text is sad and blue,\nAs though you are feeling rather rue.\n");
   } 
   else {
       printf("Your text is not leaning one way or the other,\nAs though your words have no bother.\n");
   }

   return 0;
}