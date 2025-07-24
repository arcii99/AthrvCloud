//FormAI DATASET v1.0 Category: Computer Biology ; Style: portable
#include <stdio.h>

int main() {
   int n, i, j, k, l;
   char dna[100][100], temp[100];
   
   printf("Enter number of DNA sequences: ");
   scanf("%d", &n);

   printf("Enter %d DNA sequences: \n", n);
   for(i=0; i<n; i++)
      scanf("%s", dna[i]);

   // Sorting the DNA sequences
   for(i=0; i<n-1; i++) {
      for(j=0; j<n-i-1; j++) {
         k=0;
         while(dna[j][k] == dna[j+1][k])
            k++;
         if(dna[j][k] > dna[j+1][k]) {
            // Swapping the sequences
            for(l=0; l<100; l++)
               temp[l] = dna[j][l];
            for(l=0; l<100; l++)
               dna[j][l] = dna[j+1][l];
            for(l=0; l<100; l++)
               dna[j+1][l] = temp[l];
         }
      }
   }
   
   printf("\nSorted DNA sequences are: \n");
   for(i=0; i<n; i++)
      printf("%s\n", dna[i]);

   return 0;
}