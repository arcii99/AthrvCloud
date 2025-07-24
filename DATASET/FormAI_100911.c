//FormAI DATASET v1.0 Category: System boot optimizer ; Style: detailed
#include <stdio.h>

int main() {

   int bootTime;
   int optimizedTime;

   printf("Enter boot time: ");
   scanf("%d", &bootTime);

   optimizedTime = bootTime - 25; // Optimizing boot time by 25 seconds

   printf("Boot time has been optimized by 25 seconds!");
   printf("\nYour original boot time was %d seconds.", bootTime);
   printf("\nYour new optimized boot time is %d seconds.", optimizedTime);

   return 0;
}