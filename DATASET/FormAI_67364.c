//FormAI DATASET v1.0 Category: Date and time ; Style: curious
/* Hello there! Welcome to my unique C date and time program!
 * This program displays the current date and time in a very curious way.
 * Hold onto your hats, because it's going to be quite the journey!
 * 
 * First things first, we need to include the stdio.h and time.h headers.
 * This will allow us to print output and access the time functions we need.
 */
#include <stdio.h>
#include <time.h>

int main()
{
  /* Let's start by printing a greeting to the user. */
  printf("Hello there! I'm a curious program that loves dates and times!\n");
  
  /* Now, let's get the current time and store it in a struct tm. */
  time_t current_time;
  struct tm* time_info;
  time(&current_time);
  time_info = localtime(&current_time);
  
  /* Great! We have the current time, now let's print it in a very curious way.
   * We'll print the time in hours, minutes, and seconds, and include some special text.
   */
  printf("Did you know that right now it's %d:%d:%d?\n", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
  printf("That's %d happiness units past midnight, %d anticipation units until dawn, and %d energy units before sunset!\n", time_info->tm_hour * 60 + time_info->tm_min, 60 - time_info->tm_hour - (time_info->tm_min / 60), 60 - time_info->tm_hour - (time_info->tm_min / 60));
  
  /* Now, let's print the current date.
   * We'll print the day of the week, the day of the month, and the month itself.
   */
  printf("And speaking of dates, did you know that today is a beautiful %s, %s %d?\n", 
         (time_info->tm_wday == 0 ? "Sunday" : time_info->tm_wday == 1 ? "Monday" : time_info->tm_wday == 2 ? "Tuesday" : time_info->tm_wday == 3 ? "Wednesday"
          : time_info->tm_wday == 4 ? "Thursday" : time_info->tm_wday == 5 ? "Friday" : "Saturday"),
          (time_info->tm_mon == 0 ? "January" : time_info->tm_mon == 1 ? "February" : time_info->tm_mon == 2 ? "March" : time_info->tm_mon == 3 ? "April"
          : time_info->tm_mon == 4 ? "May" : time_info->tm_mon == 5 ? "June" : time_info->tm_mon == 6 ? "July" : time_info->tm_mon == 7 ? "August"
          : time_info->tm_mon == 8 ? "September" : time_info->tm_mon == 9 ? "October" : time_info->tm_mon == 10 ? "November" : "December"),
          time_info->tm_mday);
  
  /* Finally, let's say goodbye to the user and end the program. */
  printf("Well, that was a lot of fun! Thanks for exploring the curious world of dates and times with me. Goodbye!\n");
  return 0;
}