//FormAI DATASET v1.0 Category: System event logger ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char *message){

  //get the current time
  time_t t = time(NULL);
  char *timestamp = asctime(localtime(&t));

  //open the log file
  FILE *file = fopen("event_log.txt", "a");

  //check if the file was opened successfully
  if(file == NULL){
    printf("Error opening file!\n");
    exit(1);
  }

  //write the event to the file along with the timestamp
  fprintf(file, "%s - %s\n", timestamp, message);

  //close the file
  fclose(file);
}

int main(){

  //log some sample events
  logEvent("Application started.");
  logEvent("User logged in.");
  logEvent("Data saved successfully.");
  logEvent("Error: Could not connect to database.");
  logEvent("Application closed.");

  return 0;
}