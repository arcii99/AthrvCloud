//FormAI DATASET v1.0 Category: System boot optimizer ; Style: active
#include <stdio.h>

int main() {
   int boot_time;
   printf("Enter the current boot time in seconds: ");
   scanf("%d", &boot_time);
   
   if (boot_time > 60) {
      printf("The system took %d seconds to boot.\n", boot_time);
      printf("This can be optimized by disabling unnecessary services.\n");
      printf("Would you like to disable these services? (Y/N)");
      
      char response;
      scanf(" %c", &response);
      
      if (response == 'Y' || response == 'y') {
         printf("Disabling services...\n");
         //Code to disable unnecessary services goes here
         printf("Services successfully disabled. System will now reboot.\n");
         printf("Press any key to reboot.");
         getchar(); //Flush newline character from input buffer
         getchar(); //Wait for user input
         //Code to initiate system reboot goes here
      } else if (response == 'N' || response == 'n') {
         printf("Okay. System will continue to run with all services enabled.\n");
      } else {
         printf("Invalid response. System cannot continue.\n");
      }
   } else {
      printf("The system took %d seconds to boot. No optimization needed.\n", boot_time);
   }
   
   return 0;
}