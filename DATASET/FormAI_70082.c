//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {

   char feedback[100];
   int positive_counter = 0;
   int negative_counter = 0;

   printf("Please provide your feedback: ");
   fgets(feedback, 100, stdin);

   for(int i=0; feedback[i]!='\0'; i++){

       if(feedback[i]=='g' && feedback[i+1]=='o' && feedback[i+2]=='o' && feedback[i+3]=='d'){
           positive_counter += 1;
       }
       else if(feedback[i]=='b' && feedback[i+1]=='a' && feedback[i+2]=='d'){
           negative_counter += 1;
       }

   }

   if(positive_counter > negative_counter){
       printf("Your feedback is positive\n");
   }
   else if(positive_counter < negative_counter){
       printf("Your feedback is negative\n");
   }
   else {
       printf("Your feedback is neutral\n");
   }

   return 0;
}