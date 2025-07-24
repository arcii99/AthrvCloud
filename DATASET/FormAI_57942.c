//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: artistic
#include <stdio.h>
#include <string.h>

int main() {
   char buffer[1024];
   char attack_string[] = "SELECT * FROM users WHERE username='admin'--";

   printf("Enter your command:\n");
   fgets(buffer, 1024, stdin);

   if(strstr(buffer, attack_string)) {
      printf("Intrusion detected! Attack string found.\n");
      // Add actions to be taken when an intrusion is detected
   }
   else {
      printf("Command executed successfully.\n");
      // Add normal actions to be taken when no intrusion is detected
   }

   return 0;
}