//FormAI DATASET v1.0 Category: System event logger ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 10240

int main()
{
  char log[MAX_LOG_SIZE], event[512];
  FILE *fp;
  time_t current_time;
  char* c_time_string;
  
  printf("Enter the event to log: ");          
  fflush(stdout);                             
  fgets(event, sizeof(event), stdin);          
  event[strcspn(event, "\n")] = 0;             
  
  current_time = time(NULL);                  
  c_time_string = ctime(&current_time);        
        
  snprintf(log, MAX_LOG_SIZE, "[%s] %s\n", c_time_string, event);
  
  fp = fopen("system_events.log", "a");        
  fputs(log, fp);                             
  fclose(fp);                                  
  
  printf("Event logged.\n");                  
  return 0;
}