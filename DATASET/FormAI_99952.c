//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main() {
   char str[1000];
   int pos = 0;
   int neg = 0;
   int neu = 0;

   printf("Enter your text: ");
   fgets(str, 1000, stdin);

   char *token = strtok(str, " ");

   while (token != NULL) {
      if (strstr("good nice lovely great", token)) {
         pos++;
      } else if (strstr("bad awful terrible horrible", token)) {
         neg++;
      } else {
         neu++;
      }

      token = strtok(NULL, " ");
   }

   if (pos > neg) {
      printf("Positive sentiment.\n");
   } else if (neg > pos) {
      printf("Negative sentiment.\n");
   } else {
      printf("Neutral sentiment.\n");
   }

   return 0;
}