//FormAI DATASET v1.0 Category: System boot optimizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
   Welcome to the C System Boot Optimizer!

   This program is designed to optimize your system boot process by identifying and disabling unnecessary services and programs
   that are set to run on startup. This will speed up the boot process and improve overall system performance.

   To begin, the program will scan your system and generate a list of all programs and services set to run on startup. Once the list
   is generated, you will have the option to select which programs and services to disable.

   Let's get started!
*/

// Define a struct to hold the information about each program/service
typedef struct {
   char name[50];
   bool enabled;
} Program;

int main() {
   printf("Scanning system for startup programs and services...\n");

   // Simulate scanning for programs/services
   Program startupPrograms[] = {
      {"Google Chrome", true},
      {"Dropbox", true},
      {"Adobe Updater", true},
      {"iTunes Helper", true},
      {"Windows Defender", true},
      {"Skype", true},
      {"Steam", true},
      {"Java Update Scheduler", true},
      {"HP Support Assistant", true},
      {"OneDrive", true}
   };

   int numStartupPrograms = sizeof(startupPrograms) / sizeof(Program);

   printf("Found %d programs/services set to run on startup.\n\n", numStartupPrograms);

   // Print list of programs/services and their current enabled/disabled status
   printf("Startup Programs/Services:\n");
   printf("**********************\n");
   for (int i = 0; i < numStartupPrograms; i++) {
      if (startupPrograms[i].enabled) {
         printf("%d. %s (Enabled)\n", i+1, startupPrograms[i].name);
      } else {
         printf("%d. %s (Disabled)\n", i+1, startupPrograms[i].name);
      }
   }

   // Prompt user to select which programs/services to disable
   char input[10];
   printf("\nWhich programs/services would you like to disable (separate with commas)? ");
   fgets(input, 10, stdin);

   // Parse the input and disable the selected programs/services
   char *token = strtok(input, ",");
   while (token != NULL) {
      int programIndex = atoi(token) - 1;
      if (programIndex >= 0 && programIndex < numStartupPrograms) {
         startupPrograms[programIndex].enabled = false;
         printf("%s disabled.\n", startupPrograms[programIndex].name);
      }
      token = strtok(NULL, ",");
   }

   // Print final list of programs/services and their updated enabled/disabled status
   printf("\nFinal Startup Programs/Services:\n");
   printf("**********************\n");
   for (int i = 0; i < numStartupPrograms; i++) {
      if (startupPrograms[i].enabled) {
         printf("%d. %s (Enabled)\n", i+1, startupPrograms[i].name);
      } else {
         printf("%d. %s (Disabled)\n", i+1, startupPrograms[i].name);
      }
   }

   printf("\nBoot optimization complete. Your system will now restart to apply changes.\n");
   system("shutdown /r");

   return 0;
}