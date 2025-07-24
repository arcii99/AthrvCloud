//FormAI DATASET v1.0 Category: Date and time ; Style: creative
#include <stdio.h>
#include <time.h>

int main() {
   time_t now = time(NULL);
   struct tm *t = localtime(&now);

   printf("Today's date is %02d/%02d/%04d.\n", t->tm_mday, t->tm_mon+1, t->tm_year+1900);
   printf("The current time is %02d:%02d:%02d.\n", t->tm_hour, t->tm_min, t->tm_sec);

   int yearOfBirth, currentYear, age;

   printf("What year were you born? ");
   scanf("%d", &yearOfBirth);

   currentYear = t->tm_year+1900;
   age = currentYear - yearOfBirth;

   printf("You are currently %d years old.\n", age);

   int hoursLeftInDay = 24 - t->tm_hour;
   int minutesLeftInHour = 60 - t->tm_min;
   int secondsLeftInMinute = 60 - t->tm_sec;

   printf("There are %d hours, %d minutes and %d seconds left in the day.\n", hoursLeftInDay, minutesLeftInHour, secondsLeftInMinute);

   printf("Enter a number of weeks: ");
   int weeks;
   scanf("%d", &weeks);

   int secondsInWeek = 604800;
   int totalSeconds = weeks * secondsInWeek;

   printf("%d weeks is equal to %d seconds.\n", weeks, totalSeconds);

   return 0;
}