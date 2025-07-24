//FormAI DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main() {
   char str[MAX_LEN];
   int i, j, len;
   printf("Enter a sentence in the post-apocalyptic style: ");
   fgets(str, MAX_LEN, stdin);
   len = strlen(str);
   
   // Convert all characters to uppercase
   for (i = 0; i < len; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
         str[i] -= 32;
      }
   }
   printf("Post-apocalyptic style text in uppercase: %s", str);
   
   // Reverse the order of words in the sentence
   char *words[100];
   int word_count = 0;
   char *token = strtok(str, " ");
   while (token != NULL) {
      words[word_count] = token;
      word_count++;
      token = strtok(NULL, " ");
   }
   for (i = word_count - 1; i >= 0; i--) {
      printf("%s ", words[i]);
   }
   printf("\n");
   
   // Add a random number at the end of the sentence
   int random_num = rand() % 100;
   char num_str[10];
   sprintf(num_str, "%d", random_num);
   strcat(str, num_str);
   printf("Post-apocalyptic style text with a random number at the end: %s", str);
   
   return 0;
}