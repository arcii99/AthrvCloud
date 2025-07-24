//FormAI DATASET v1.0 Category: Log analysis ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
   char log[] = "SUCCESS: User login from IP address 192.168.0.101";
   char *token;
   
   printf("Analyzing log...\n");
   
   // Create a delimiter string
   char delimiter[] = " ";
   
   // Use strtok to tokenize the log string using the delimiter
   token = strtok(log, delimiter);
   
   // Loop through the tokens and check for login success
   while(token != NULL) {
      if(strcmp(token, "SUCCESS:") == 0) {
         printf("SUCCESS: User logged in successfully!\n");
         break;
      }
      
      token = strtok(NULL, delimiter);
   }
   
   // Extract the IP address from the log string
   char *ip_address = strtok(NULL, delimiter);
   if(ip_address != NULL) {
      printf("IP Address: %s\n", ip_address);
   }
   
   printf("Log analysis complete!\n");

   return 0;
}