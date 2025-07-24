//FormAI DATASET v1.0 Category: Date and time ; Style: thoughtful
#include <stdio.h>
#include <time.h>
 
int main () {
   time_t rawtime;
   struct tm * timeinfo;
   char buffer [80];

   time (&rawtime);
   timeinfo = localtime (&rawtime);

   strftime (buffer,80,"Today is %A, %B %d, %Y.\n",timeinfo);
   printf("%s",buffer);

   strftime (buffer,80,"The time is %I:%M %p.\n",timeinfo);
   printf("%s",buffer);

   return 0;
}