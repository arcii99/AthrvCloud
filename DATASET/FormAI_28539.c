//FormAI DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h>

int main() {
   printf("Welcome to the System Event Logger!\n");
   printf("This program will log all the funny things that happen in your system.\n");

   char event[100];
   FILE *fp;
   fp = fopen("event_log.txt", "a");

   printf("Enter an event: ");
   scanf("%[^\n]s", event);

   fprintf(fp, "[TIME]: %s\n", __TIME__);
   fprintf(fp, "[DATE]: %s\n", __DATE__);
   fprintf(fp, "[EVENT]: %s\n\n", event);

   printf("Event logged successfully! Check event_log.txt file to see what happened :)");

   fclose(fp);

   return 0;
}