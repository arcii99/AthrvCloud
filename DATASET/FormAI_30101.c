//FormAI DATASET v1.0 Category: Educational ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {

   int score;

   printf("Enter your score: ");
   scanf("%d", &score);

   if (score >= 90 && score <= 100) {
      printf("Grade A\n");
   }
   else if (score >= 80 && score < 90) {
      printf("Grade B\n");
   }
   else if (score >= 70 && score < 80) {
      printf("Grade C\n");
   }
   else if (score > 0 && score < 70) {
      printf("Grade F\n");
   }
   else {
      printf("Invalid score entered\n");
   }
   
   return 0;
}