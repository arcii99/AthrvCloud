//FormAI DATASET v1.0 Category: Text Summarizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 150

// function to check if a character is punctuation or not
int is_punctuation(char c) {
   return (c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?');
}

// function to summarize text
char* summarize_text(char* text) {
   char* summary = malloc(MAX_SUMMARY_LENGTH + 1);
   int summary_length = 0;
   int i, j;
   
   // loop through each word in the text
   for (i = 0; i < strlen(text); i++) {
      if (!is_punctuation(text[i])) {
         // add the character to the summary
         summary[summary_length++] = text[i];
      }
      
      if (summary_length >= MAX_SUMMARY_LENGTH) {
         // summary is too long, break the loop
         break;
      }
      
      if (is_punctuation(text[i]) && summary_length > 0) {
         // add a space after the punctuation, and then check if the summary is long enough
         summary[summary_length++] = ' ';
         summary[summary_length] = '\0';
         if (summary_length >= MAX_SUMMARY_LENGTH) {
            break;
         }
         
         // remove any leading or trailing whitespace from the summary
         while (isspace(summary[0])) {
            memmove(summary, summary + 1, strlen(summary));
         }
         while (isspace(summary[strlen(summary)-1])) {
            summary[strlen(summary)-1] = '\0';
         }
         
         // add the ellipsis to the end of the summary
         if (i < strlen(text)-1 && !is_punctuation(text[i+1])) {
            strcat(summary, "...");
         }
         
         // return the summary
         return summary;
      }
   }
   
   // the text is too short to summarize, return the full text
   strcpy(summary, text);
   return summary;
}

// main function
int main() {
   char text[] = "This is a long piece of text that needs to be summarized. It contains many words and a few pieces of punctuation, which we will use to break up the summary. We will try to summarize the text in a way that captures its essence, without being too long or too short. Let us begin...";
   char* summary = summarize_text(text);
   
   printf("Full text: %s\n", text);
   printf("Summary: %s\n", summary);
   
   free(summary);
   
   return 0;
}