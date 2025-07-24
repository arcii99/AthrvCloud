//FormAI DATASET v1.0 Category: System event logger ; Style: Romeo and Juliet
/* Scene: a coding room */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_LOG "system_events.log"

/* Romeo's side */
int main() {
  FILE *fp;
  char message[100];
  time_t now;

  /* Opening the file */
  fp = fopen(EVENT_LOG, "a");

  /* Checking the file pointer */
  if (fp == NULL) {
    printf("Alas, error opening file! \n");
    exit(1);
  }

  /* Setting up the event message */
  sprintf(message, "\n[%s] System event: Program started running. \n", asctime(localtime(&now)));

  /* Writing the log to the file */
  fputs(message, fp);

  /* Closing the file */
  fclose(fp);

  /* Juliet's Side */
  printf(
    "Oh Romeo, what news have you today? \n" 
    "My fair Juliet, I have started the program's run today! \n"
    "Tell me more about this, oh brave Romeo! \n"
    "It is now logged in the system_events.log file, my sweet. \n"
  );

  return 0;
}