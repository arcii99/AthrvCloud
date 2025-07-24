//FormAI DATASET v1.0 Category: Educational ; Style: Ada Lovelace
#include <stdio.h>

int main() {
   int n;
   printf("Enter a number between 1 and 100: ");
   scanf("%d", &n);

   for(int i=1; i<=n; i++) {
      if(i % 3 == 0 && i % 5 == 0) {
         printf("AdaLovelace ");
      }
      else if(i % 3 == 0) {
         printf("Ada ");
      }
      else if(i % 5 == 0) {
         printf("Lovelace ");
      }
      else {
         printf("%d ", i);
      }
   }

   return 0;
}