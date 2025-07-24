//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

void peacefulMessage(int count) {
   if (count == 1) {
      printf("Peace begins with a smile.\n");
      return;
   }
   peacefulMessage(count-1);
   printf("Peace begins with a smile.\n");
}

int main() {
   int count = 10;
   peacefulMessage(count);
   return 0;
}