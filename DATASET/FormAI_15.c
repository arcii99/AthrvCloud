//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct activity_log {
   char ip_address[20];
   char username[50];
   char activity_type[50];
};

int main() {
   struct activity_log activity_logs[1000];
   int log_counter = 0;
   char input[100];
   char *token;

   while (1) {
      printf("\nEnter activity log (IP_Address, Username, Activity_Type): ");
      fgets(input, sizeof(input), stdin);

      token = strtok(input, ", ");
      if (token == NULL) {
         printf("Invalid input.\n");
         continue;
      }
      else {
         strcpy(activity_logs[log_counter].ip_address, token);
      }

      token = strtok(NULL, ", ");
      if (token == NULL) {
         printf("Invalid input.\n");
         continue;
      }
      else {
         strcpy(activity_logs[log_counter].username, token);
      }

      token = strtok(NULL, ", ");
      if (token == NULL) {
         printf("Invalid input.\n");
         continue;
      }
      else {
         strcpy(activity_logs[log_counter].activity_type, token);
      }

      printf("\nActivity log recorded.\n");

      // Intrusion detection algorithm
      int count = 0;
      for (int i = 0; i < log_counter; i++) {
         if (strcmp(activity_logs[log_counter].ip_address, activity_logs[i].ip_address) == 0) {
            count++;
            if (count >= 3) {
               printf("\nINTRUSION DETECTED!!\nIP address %s has been used for suspicious activity.\n", activity_logs[log_counter].ip_address);
            }
         }
      }

      log_counter++;
   }

   return 0;
}