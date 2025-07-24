//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: configurable
#include<stdio.h> //header files
#include<time.h>
#include<math.h>

int main() {
   int i, j;
   double temp, elapsedTime;
   clock_t start, end;
   
   printf("Welcome to Internet Speed Test Application!\n");
   
   start = clock(); //start time
   
   //Perform internet speed test calculations
   
   end = clock(); //end time
   elapsedTime = (end - start) / (double)CLOCKS_PER_SEC; //calculate elapsed time
   
   printf("\nElapsed Time: %.2lf seconds\n", elapsedTime); //print elapsed time
   
   return 0;
}