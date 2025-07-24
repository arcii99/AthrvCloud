//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: paranoid
#include <stdio.h>

int main() {
   char input[1000];
   printf("Enter your text: ");
   fgets(input, sizeof(input), stdin);

   int i, pos_count = 0, neg_count = 0;
   for(i = 0; input[i] != '\0'; i++) {
      if(input[i] == 'g' || input[i] == 'G') {
         pos_count++;
      } else if(input[i] == 't' || input[i] == 'T') {
         neg_count++;
      }
   }

   printf("Number of positive mentions: %d\n", pos_count);
   printf("Number of negative mentions: %d\n", neg_count);

   if(pos_count > neg_count) {
      printf("Seems like you are in a good mood today! But maybe you're just trying to hide something...\n");
   } else if(neg_count > pos_count) {
      printf("Uh oh, seems like you are feeling a bit down today. Are you sure everything is okay?\n");
   } else {
      printf("It's hard to tell your mood from your text. Maybe you're just really good at being neutral?\n");
   }

   return 0;
}