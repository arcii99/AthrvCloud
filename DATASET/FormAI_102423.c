//FormAI DATASET v1.0 Category: Log analysis ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main(void) {

   char log[10000][200];
   char *line = NULL;
   int i = 0;

   // Read log file
   FILE *file = fopen("example.log", "r");
   if (file) {
      while (fgets(log[i], 200, file)) {
         i++;
      }
      fclose(file);
   }

   // Parse log file
   for (int j = 0; j < i; j++) {
      char *token = strtok(log[j], " ");

      if (strcmp(token, "ERROR") == 0) {
         printf("Error found: %s\n", log[j]);
         continue;
      }

      int count = 1;
      while (token != NULL) {
         if (count == 3) {
            printf("IP Address: %s\n", token);
         }
         if (count == 4) {
            printf("Date: %s %s\n", token, strtok(NULL, "]"));
         }
         if (count == 5) {
            printf("Request Type: %s %s\n", token, strtok(NULL, "\""));
         }

         count++;
         token = strtok(NULL, " ");
      }
   }

   return 0;
}