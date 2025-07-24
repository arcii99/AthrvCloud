//FormAI DATASET v1.0 Category: System event logger ; Style: Sherlock Holmes
/* A Sherlock Holmes style C system event logger example program */

#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{
   printf("The game is afoot!\n"); 
   printf("Initializing event logger...\n"); 
   
   FILE *log_file = fopen("event_log.txt", "w"); 

   if (log_file == NULL) 
   {
      printf("An error occurred while opening the log file. The game is over.\n");
      exit(EXIT_FAILURE); 
   }

   printf("Event logger successfully initialized. Ready to log events.\n"); 
   printf("Let's simulate some events...\n\n"); 

   fprintf(log_file, "***** EVENT LOG *****\n"); 

   printf("The smell of tobacco smoke fills the air as a man in a deerstalker hat walks into the room.\n"); 
   fprintf(log_file, "Event type: Suspicious character\n"); 
   fprintf(log_file, "Description: Man in deerstalker hat enters the room. Tobacco smoke detected.\n\n"); 

   printf("A shriek pierces the air as a woman runs out of the room.\n"); 
   fprintf(log_file, "Event type: Disturbance\n"); 
   fprintf(log_file, "Description: Woman runs out of the room, emitting a loud shriek.\n\n"); 

   printf("The man in the deerstalker hat follows the woman out of the room.\n"); 
   fprintf(log_file, "Event type: Potential suspect\n"); 
   fprintf(log_file, "Description: Man in deerstalker hat follows the woman out of the room.\n\n"); 

   printf("A gunshot is heard in the distance.\n"); 
   fprintf(log_file, "Event type: Gunshot\n"); 
   fprintf(log_file, "Description: Single gunshot heard in the distance.\n\n"); 

   printf("The man in the deerstalker hat returns, his coat stained with blood.\n"); 
   fprintf(log_file, "Event type: Murder suspect\n"); 
   fprintf(log_file, "Description: Man in deerstalker hat returns with bloodstained coat.\n\n"); 

   printf("The game is afoot, Watson!\n"); 

   fclose(log_file); 

   return 0; 
}