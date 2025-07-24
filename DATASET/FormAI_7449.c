//FormAI DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>

int main() {

   FILE *fp;
   char path[100];

   // Open the log file
   fp = fopen("/var/log/syslog", "r");
   if (fp == NULL) {
      printf("Error opening file\n");
      return 1;
   }

   printf("*******************************************\n");
   printf("*                                         *\n");
   printf("*        Syslog Event Summary Report       *\n");
   printf("*                                         *\n");
   printf("*******************************************\n");
   printf("\n");

   // Start reading the log file line by line
   while (fgets(path, 100, fp) != NULL) {
       
       char keyword1[] = "usb";  // Look for events related to USB 
       char keyword2[] = "error";  // Look for events with the word "error"
       
       if (strstr(path, keyword1) != NULL && strstr(path, keyword2) != NULL) {
           printf("USB Error Event: %s", path);
       }

       char keyword3[] = "failed"; // Look for events with the word "failed"
       char keyword4[] = "authentication"; // Look for events with the word "authentication"
       
       if (strstr(path, keyword3) != NULL && strstr(path, keyword4) != NULL) {
           printf("Authentication Failed Event: %s", path);
       }
   }

   printf("\n");
   printf("*******************************************\n");
   printf("*                                         *\n");
   printf("*                 End Report              *\n");
   printf("*                                         *\n");
   printf("*******************************************\n");

   // Close the log file
   fclose(fp);

   return 0;
}