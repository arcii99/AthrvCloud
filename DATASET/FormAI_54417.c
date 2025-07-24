//FormAI DATASET v1.0 Category: System event logger ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int event_id = 0;
   char event_desc[100];
   FILE *event_log;

   event_log = fopen("system_events.log", "a");

   if(event_log == NULL) {
      printf("Error: Unable to open log file.");
      exit(1);
   }

   printf("Welcome to the Mind-Bending System Event Logger!\n");
   printf("Please enter the events in the following format:\n\n");
   printf("[event_id]:[event_description]\n\n");

   while(1) {
      printf("Enter event: ");
      scanf("%d:%[^\n]", &event_id, event_desc);

      time_t current_time = time(NULL);
      char *timestamp = ctime(&current_time);
      timestamp[strlen(timestamp) - 1] = '\0';

      fprintf(event_log, "[%s] Event ID: %d\n", timestamp, event_id);
      fprintf(event_log, "[%s] Description: %s\n\n", timestamp, event_desc);

      printf("Event recorded successfully!\n");

      printf("Do you want to enter another event? (Y/N): ");
      char choice;
      scanf(" %c", &choice);

      if(choice == 'N' || choice == 'n') {
         break;
      }
   }

   printf("Thank you for using the Mind-Bending System Event Logger!");
   fclose(event_log);

   return 0;
}