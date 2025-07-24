//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t current_time;
  char* c_time_string;

  // Get the current time
  current_time = time(NULL);

  // Convert the current time to string format
  c_time_string = ctime(&current_time);

  // Print the current time to the console
  printf("Welcome to the Retro Time Travel Simulator!\n");
  printf("The current date and time is: %s", c_time_string);

  // Pause the program for a moment
  printf("Initializing time travel sequence...\n\n");
  sleep(2);

  // Travel back to the 1950s
  struct tm travel_time = {0};
  travel_time.tm_year = 50;
  travel_time.tm_mon = 0;
  travel_time.tm_mday = 1;
  time_t travel_time_raw = mktime(&travel_time);
  c_time_string = ctime(&travel_time_raw);

  // Print the new time to the console
  printf("You have arrived in the 1950s!\n");
  printf("The date and time is now: %s", c_time_string);

  // Pause the program for a moment
  printf("Scanning for local landmarks...\n");
  sleep(2);

  // Set the location to Roswell, New Mexico
  char* location = "Roswell, New Mexico";

  // Print the location to the console
  printf("You have arrived in %s!\n", location);

  // Pause the program for a moment
  printf("Searching for famous events...\n");
  sleep(2);

  // Set the event to the Roswell UFO incident
  char* event = "the Roswell UFO incident";

  // Print the event to the console
  printf("You are witnessing %s!\n", event);

  // Pause the program for a moment
  printf("Returning to present day...\n");
  sleep(2);

  // Return to the present day
  current_time = time(NULL);
  c_time_string = ctime(&current_time);

  // Print the current time to the console
  printf("You have returned to the present day!\n");
  printf("The current date and time is now: %s", c_time_string);

  return 0;
}