//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int surrealSearch(int* array, int size, int element) {
   int startPosition = 0;
   int endPosition = size - 1;

   while (startPosition <= endPosition) {
       int midpoint = (startPosition + endPosition) / 2;

       if (array[midpoint] == element) {
           return midpoint;
       }

       if (array[startPosition] <= array[midpoint]) {
           if (array[startPosition] <= element && element < array[midpoint]) {
               endPosition = midpoint - 1;
           } else {
               startPosition = midpoint + 1;
           }
       } else {
           if (array[midpoint] < element && element <= array[endPosition]) {
               startPosition = midpoint + 1;
           } else {
               endPosition = midpoint - 1;
           }
       }
   }

   return -1;
}

int main() {
   int surrealArray[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
   int surrealSize = sizeof(surrealArray) / sizeof(surrealArray[0]);
   int surrealElement = 5;

   int surrealResult = surrealSearch(surrealArray, surrealSize, surrealElement);

   if (surrealResult == -1) {
       printf("Element not found in surreal array.");
   } else {
       printf("Element found at surreal index %d", surrealResult);
   }

   return 0;
}