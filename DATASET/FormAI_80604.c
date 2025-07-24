//FormAI DATASET v1.0 Category: System event logger ; Style: paranoid
#include <stdio.h>
#include <time.h>

/* Paranoid style event logger */
int main(){
  FILE *fptr;
  char filename[20], event[100], timestamp[50];
  time_t current_time;
  struct tm* timeinfo;
  
  /* Create log file */
  printf("Enter filename for log: ");
  scanf("%s", filename);
  fptr = fopen(filename, "w");
  
  /* Verify file exists */
  if(fptr == NULL)
    printf("Error creating log file!");
  else{
    printf("Log file created: %s\n", filename);
    /* Record every event */
    while(1){
      printf("Enter event (press Q to quit): ");
      scanf("%s", event);
      if(event[0] == 'Q' && event[1] == '\0')
        break;
      /* Get time of event */
      current_time = time(NULL);
      timeinfo = localtime(&current_time);
      strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S] ", timeinfo);
      /* Write event and timestamp to log file */
      fprintf(fptr, "%s %s\n", timestamp, event);
      fflush(fptr);
    }
    printf("Logging complete. Closing log file.\n");
    fclose(fptr);
  }
  return 0;
}