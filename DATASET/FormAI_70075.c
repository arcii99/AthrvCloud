//FormAI DATASET v1.0 Category: Date and time ; Style: grateful
#include <stdio.h>
#include <time.h>

int main() {
  
  //get current system time
  time_t timer;
  time(&timer);
  
  //convert to local time
  struct tm* local_time = localtime(&timer);
  
  //display date and time
  printf("Grateful for this moment: %s\n", asctime(local_time));
  
  return 0;
}