//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>

int main() {
   char input_str[100];
   int happy_count = 0, sad_count = 0;
   printf("Welcome to my Happy Sentiment Analysis Tool!\n");
   printf("Enter a sentence and let's see if it contains happy or sad words:\n");

   fgets(input_str, 100, stdin);

   char* happy_words[] = {"happy", "joy", "excited", "great", "fantastic", "awesome", "amazing",
                          "wonderful", "delightful", "thrilled", "ecstatic", "blissful", "content",
                          "pleased", "overjoyed", "elated", "enthusiastic"};

   char* sad_words[] = {"sad", "depressed", "unhappy", "miserable", "heartbroken", "sorrowful",
                        "gloomy", "down", "disappointed", "lonely", "bad", "sorry", "painful",
                        "devastated", "shattered", "troubled"};

   for(int i=0;i<strlen(input_str);i++){
       if(input_str[i] >= 'A' && input_str[i] <= 'Z'){ // Coverting the input string to lower case for better matching
           input_str[i] += 'a' - 'A';
       }
   }

   char* word = strtok(input_str, " ,.-"); // Breaking the input string into words

   while(word != NULL){
       for(int i=0;i<sizeof(happy_words)/sizeof(char*);i++){ // Checking if any happy words are present
           if(strcmp(word, happy_words[i]) == 0){
               happy_count++;
           }
       }
       for(int i=0;i<sizeof(sad_words)/sizeof(char*);i++){ // Checking if any sad words are present
           if(strcmp(word, sad_words[i]) == 0){
               sad_count++;
           }
       }
       word = strtok(NULL, " ,.-"); // Moving to the next word
   }

   if(happy_count > sad_count){
       printf("\nAfter analyzing your input, I can say with confidence that it is a happy sentence!\n");
   }else if(sad_count > happy_count){
       printf("\nAfter analyzing your input, I can say with confidence that it is a sad sentence :(\n");
   }else{
       printf("\nAfter analyzing your input, I found an equal number of happy and sad words. So, it's a neutral sentence\n");
   }

   return 0;
}