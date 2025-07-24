//FormAI DATASET v1.0 Category: Weather simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
   int temp, i, j;
   
   srand(time(0));
   
   printf("\n\t\t Weather Simulation Program\n\n");
   printf("\nEnter the number of days you want to simulate: ");
   scanf("%d", &temp);
   
   printf("\nDay\t Temperature\n");
   
   for(i=1; i<=temp; i++) {
      printf("%d\t ", i);
      
      for(j=1; j<=3; j++) {
         temp = (rand() % 50) + 1;
         printf("%d ", temp);
      }
      printf("\n");
   }
   return 0;
}