//FormAI DATASET v1.0 Category: System event logger ; Style: enthusiastic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
   srand(time(NULL)); // seed random number generator
   int rand_num = rand() % 100 + 1; // generate random number between 1 and 100
   FILE *file; // declare file pointer
   file = fopen("eventlog.txt", "a"); // open file in append mode
   if (file != NULL) { // check if file was successfully opened
      time_t current_time;
      char* c_time_string;
      current_time = time(NULL); // get current time
      c_time_string = ctime(&current_time); // convert time to string
      fprintf(file, "Event #%d occurred at %s", rand_num, c_time_string); // write event to file
      printf("Event #%d successfully logged!\n", rand_num); // inform user that event was logged
      fclose(file); // close file
   } else {
      printf("Error opening file!\n"); // inform user of file opening error
   }
   return 0;
}