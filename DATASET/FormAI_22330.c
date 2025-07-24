//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
   char sentence[1000], word[100], ch;
   int positive=0, negative=0;

   printf("Enter a sentence: ");
   fgets(sentence, sizeof(sentence), stdin);
   printf("Enter the word to analyse: ");
   fgets(word, sizeof(word), stdin);
   
   int len = strlen(sentence);
   int wordLen = strlen(word)-1; //excluding newline character from word
   int j=0; //counter for the word

   for(int i=0; i<len; i++) {
      if(sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\0'){
         if(j==wordLen && strncmp(sentence+i-j, word, j)==0){  //if word matches
               char temp = sentence[i];
               sentence[i] = '\0'; //temporarily nullify the end of the word for printf function
               printf("%s : ", word);
               sentence[i] = temp; //reassigning the original end of the word
               
               //code to check and add sentiment
               for(int k=i-j-1; k>=0; k--){
                  ch = sentence[k];
                  if(ch == '.' || ch == '?' || ch == '!') break;
                  else if(ch == 'g') positive++;
                  else if(ch == 'b') negative++;
               }
         }
         j=0; //resetting the word counter
      }
      else{
         j++;
      }
   }

   //output based on sentiment count
   if(positive > negative){
      printf("\nSentiment: Positive");
   }
   else if(negative > positive){
      printf("\nSentiment: Negative");
   }
   else{
      printf("\nSentiment: Neutral");
   }
   return 0;
}