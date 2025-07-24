//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *sentiment_analysis(void *arg);

int main() {
   pthread_t thread;
   char input[1000];
   
   printf("Enter your text: ");
   fgets(input, 1000, stdin);
   
   pthread_create(&thread, NULL, sentiment_analysis, input);
   pthread_join(thread, NULL);
   
   return 0;
}

void *sentiment_analysis(void *arg) {
   char *input = (char*) arg;
   int pos = 0, neg = 0, neu = 0;
   char positive[20][100] = {"good", "great", "awesome", "fantastic", "excellent", "amazing", "wonderful", "nice", "happy", "joyful", "delightful", "pleasing", "pleasant", "satisfying", "superb", "terrific", "glorious", "splendid", "beautiful", "lovely"};
   char negative[20][100] = {"bad", "awful", "terrible", "horrible", "poor", "unpleasant", "dreadful", "disappointing", "unsatisfactory", "disturbing", "upsetting", "displeasing", "gloomy", "grim", "miserable", "sad", "unhappy", "depressing", "painful", "sorrowful"};
   
   char *token = strtok(input, "., \n");
   
   while(token != NULL) {
      for(int i=0; i<20; i++) {
         if(strcmp(token, positive[i]) == 0) {
            pos++;
            break;
         } else if(strcmp(token, negative[i]) == 0) {
            neg++;
            break;
         } else {
            neu++;
            break;
         }
      }
      token = strtok(NULL, "., \n");
   }
   
   printf("Sentiment Analysis result:\n");
   printf("Positive: %d\n", pos);
   printf("Negative: %d\n", neg);
   printf("Neutral: %d\n", neu);
   
   pthread_exit(NULL);
}