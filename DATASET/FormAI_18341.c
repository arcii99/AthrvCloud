//FormAI DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <time.h> 

int main () {

  int hour;
  struct tm medieval_time;
  
  // get current time
  time_t raw_time = time(NULL);
  struct tm *current_time = localtime(&raw_time);
  
  // convert current time to medieval time
  medieval_time.tm_hour = current_time->tm_hour + 6; // add 6 hours (medieval time is ahead of our time)
  medieval_time.tm_min = current_time->tm_min;
  medieval_time.tm_sec = current_time->tm_sec;
  medieval_time.tm_year = current_time->tm_year;
  medieval_time.tm_mon = current_time->tm_mon;
  medieval_time.tm_mday = current_time->tm_mday;
  
  // check if it's day or night
  if (medieval_time.tm_hour >= 6 && medieval_time.tm_hour < 19) {
    printf("Good day, sire!\n");
    turn_on_light();
  } else {
    printf("Good evening, sire!\n");
    turn_off_light();
  }
  
  return 0;
}

void turn_on_light() {
  printf("The torches are lit!\n");
  // code to turn on lights in the house
}

void turn_off_light() {
  printf("The castle is shrouded in darkness...\n");
  // code to turn off lights in the house
}