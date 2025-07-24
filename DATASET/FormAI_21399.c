//FormAI DATASET v1.0 Category: Date and time ; Style: innovative
#include <stdio.h>
#include <time.h>

int main() {
   time_t now;
   struct tm *timeinfo;
   char buffer[80];

   time(&now);
   timeinfo = localtime(&now);

   strftime(buffer, 80, "Today is %A, %B %d, %Y and the time is %I:%M:%S %p.", timeinfo);

   printf("Hello! Welcome to the C date and time program.\n");
   printf("Here is the current date and time:\n\n");
   printf("%s\n", buffer);

   return 0;
}