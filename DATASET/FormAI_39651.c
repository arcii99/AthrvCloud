//FormAI DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
   srand(time( NULL ));
   int data[20];
   int min = 1, max = 100;

  //Generate 20 random numbers between 1 and 100
  for(int i=0;i<20;i++) {
      data[i] = (rand() % (max - min + 1)) + min;
   }

  //Print the random numbers
   printf("Generated Data: ");
   for(int i=0;i<20;i++) {
      printf("%d ", data[i]);
   }

   int sum=0, mean=0, mode=0, maxfreq=0;

   //Calculate sum and mean
   for(int i=0;i<20;i++) {
      sum += data[i];
   }
   mean = sum/20;

   //Count occurences of each number and determine mode
   int count[100]={0};
   for(int i=0;i<20;i++) {
      count[data[i]-1]++;
      if(count[data[i]-1] > maxfreq) {
         maxfreq = count[data[i]-1];
         mode = data[i];
      }
   }

   //Print the results
   printf("\nSum: %d", sum);
   printf("\nMean: %d", mean);
   printf("\nMode: %d", mode);

   return 0;
}