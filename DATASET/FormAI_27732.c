//FormAI DATASET v1.0 Category: Text processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// function to reverse a string
void reverse(char *str) {
   int i = 0, j = strlen(str) - 1;
   while (i < j) {
      char temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++; j--;
   }
}

// function to count the number of words in a string
int count_words(char *str) {
   int count = 0;
   char *split = strtok(str, " ");
   while (split != NULL) {
      count++;
      split = strtok(NULL, " ");
   }
   return count;
}

int main() {
   char line[MAX_LINE_LENGTH];   // variable to hold input line
   printf("Enter a string: ");
   fgets(line, MAX_LINE_LENGTH, stdin);

   // reverse the string
   reverse(line);
   printf("Reversed string: %s", line);

   // count the number of words in the string
   int word_count = count_words(line);
   printf("Number of words in the string: %d", word_count);

   return 0;
}