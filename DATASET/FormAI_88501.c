//FormAI DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000

int main(){

   char sentence[SIZE];
   int count=0, wordCount=1, charCount=0, i;

   printf("Enter a sentence: ");
   fgets(sentence,SIZE,stdin);
   sentence[strlen(sentence)-1] = '\0';

   for(i=0; sentence[i]!='\0'; i++){

      //Counts words
      if(sentence[i] == ' '){
         wordCount++;
      }

      //Counts characters
      if(sentence[i] != ' ' && sentence[i] != '\n'){
         count++;
         charCount++;
      }
      
      //Counts unique characters
      for(int j=i+1; sentence[j]!='\0'; j++){
         if(sentence[i] == sentence[j]){
            count--;
            break;
         }
      }
   }

   //Outputs the word count and character counts to the user
   printf("\nWord Count: %d", wordCount);
   printf("\nTotal Number of Unique Characters: %d", count);
   printf("\nTotal Number of Characters Excluding Spaces and Line Breaks: %d", charCount);

   return 0;
}