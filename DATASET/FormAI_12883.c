//FormAI DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
   int i, n;
   float sum, mean, max, min;
   float data[MAX_SIZE];
   FILE *fp;

   fp = fopen("data.txt", "r");
   if (fp == NULL) {
      printf("Could not open file.");
      exit(1);
   }

   i = 0;
   while (fscanf(fp, "%f", &data[i]) != EOF && i < MAX_SIZE) {
      i++;
   }
   n = i;

   max = data[0];
   min = data[0];
   sum = data[0];

   for (i = 1; i < n; i++) {
      if (data[i] > max) {
         max = data[i];
      }
      if (data[i] < min) {
         min = data[i];
      }
      sum += data[i];
   }

   mean = sum / n;

   printf("Dataset Analysis:\n");
   printf("Number of data points: %d\n", n);
   printf("Maximum value: %f\n", max);
   printf("Minimum value: %f\n", min);
   printf("Mean value: %f\n", mean);

   fclose(fp);

   return 0;
}