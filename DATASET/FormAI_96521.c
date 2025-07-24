//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 10000

int main() {
   char genome[GENOME_SIZE];
   int i;

   srand(time(NULL));
   for (i = 0; i < GENOME_SIZE; i++) {
      genome[i] = rand() % 4;
   }

   // Print genome as ACTG characters
   for (i = 0; i < GENOME_SIZE; i++) {
      switch (genome[i]) {
         case 0:
            printf("A");
            break;
         case 1:
            printf("C");
            break;
         case 2:
            printf("T");
            break;
         case 3:
            printf("G");
            break;
         default:
            printf("Error: Invalid genome value");
            exit(1);
      }
   }

   return 0;
}