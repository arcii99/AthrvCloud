//FormAI DATASET v1.0 Category: Date and time ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>

int main() {
   time_t t = time(NULL);
   struct tm *tm = localtime(&t);

   printf("Today's date is: %02d/%02d/%d\n", tm->tm_mday, tm->tm_mon+1, tm->tm_year+1900);
   printf("Current time is: %02d:%02d:%02d\n", tm->tm_hour, tm->tm_min, tm->tm_sec);

   return 0;
}