//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
   int rating;
   printf("O Romeo, Romeo, wherefore art thou rating?\n");
   scanf("%d", &rating);
   
   if (rating == 10) {
      printf("By any other score would smell as sweet;\n");
   } else if (rating >= 8 && rating < 10) {
      printf("But, soft! What score through yonder window breaks?\n");
   } else if (rating >= 6 && rating < 8) {
      printf("It seems she hangs upon the cheek of night\n");
   } else if (rating >= 4 && rating < 6) {
      printf("One score both alike in dignity\n");
   } else if (rating >= 2 && rating < 4) {
      printf("Parting is such a low rated sorrow\n");
   } else if (rating >= 0 && rating < 2) {
      printf("My only love Sprung from my only hate\nToo early seen unknown, and known too late!\n");
   } else {
      printf("What's in a name? That which we call a score\nBy any other name would smell as sweet.\n");
   }
   return 0;
}