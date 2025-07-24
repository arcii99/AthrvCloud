//FormAI DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>

int main () {
   char text[1000], summary[1000];
   int i = 0, j = 0, count = 0, flag = 0;
   
   printf("Enter the text to summarize:\n");
   fgets(text, 1000, stdin); //user inputs text
   
   while (text[i] != '\0') { //loop through the text
      if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?')) {//if a sentence end is detected
         count++; //increment number of sentences
         if (flag == 1) { //if the flag is set, add the last word of the sentence to the summary
            summary[j] = text[i-1];
            j++;
            summary[j] = ' ';
            j++;
            flag = 0; //reset flag
         }
      }
      if (count == 3) { //if 3 sentences have been detected
         summary[j] = '\0'; //add null terminator to summary
         printf("\nSummary:\n%s\n", summary); //print summary
         break; //exit loop
      }
      if (flag == 1) { //if flag is set, add current character to summary
         summary[j] = text[i];
         j++;
      }
      if (text[i] == ' ') { //if a space is detected, set flag
         flag = 1;
      }
      i++; //increment loop variable
   }
   
   if (count < 3) { //if there are less than 3 sentences
      printf("\nError: Text must contain at least 3 sentences.\n"); //print error message
   }
   
   return 0;
}