//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//function to remove punctuation from sentence
void removePunct(char *str) {
   int i = 0, j = 0;
   while (str[i]) {
      if (!ispunct((unsigned char)str[i]))
         str[j++] = str[i];
      i++;
   }
   str[j] = '\0';
}

//function to count words in sentence
int countWords(char *arr) {
   int count = 0;
   char *token = strtok(arr, " ");
   while (token != NULL) {
      count++;
      token = strtok(NULL, " ");
   }
   return count;
}

int main() {

   char sentence[500];
   printf("Enter a sentence:\n");
   fgets(sentence, 500, stdin);
   removePunct(sentence); //remove punctuation from the sentence

   int len = strlen(sentence);
   if (len > 0 && sentence[len-1] == '\n') //removing new line character from the end of the sentence
      sentence[len-1] = '\0';

   int n = countWords(sentence);
   if(n >= 5) {
      char *token = strtok(sentence, " ");
      int i = 0;
      char words[5][20]; //store first 5 words in a 2D array
      while (token != NULL && i < 5) {
         strcpy(words[i], token);
         token = strtok(NULL, " ");
         i++;
      }

      printf("Summary: ");
      for(int j=0; j<5; j++) { //print the first 5 words as summary
         printf("%s ", words[j]);
      }
   }
   else if(n>0 && n<5) { //if there are less than 5 words, print the sentence as it is
      printf("Summary: %s", sentence);
   }
   else { //if sentence is empty, print a random surreal sentence
      printf("Summary: The sky was made of jello and trees could talk with bicycles.\n");
   }

   return 0;
}