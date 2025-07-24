//FormAI DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>

void printNaturalNumbers(int start, int end) {
   if(start <= end) {
      printf("%d\n", start);

      printNaturalNumbers(start + 1, end);
   }
}

int main() {
   printf("Natural Numbers from 1 to 10: \n");
   printNaturalNumbers(1, 10);

   return 0;
}