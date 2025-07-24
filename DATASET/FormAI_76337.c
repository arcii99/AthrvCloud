//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char scanned_file[100];
   int virus_detected = 0;
   
   printf("Welcome to C Antivirus Scanner!\n");
   printf("Please enter the name of the file you wish to scan: ");
   scanf("%s", scanned_file);
   
   // Check file extension
   char* extension = strrchr(scanned_file, '.');
   if (extension == NULL || strcmp(extension, ".exe") != 0) {
      printf("\nERROR: This program only scans .exe files.\n");
      return 0;
   }
   
   FILE* file = fopen(scanned_file, "rb");
   if (file == NULL) {
      printf("\nERROR: Could not open file %s.\n", scanned_file);
      return 0;
   }
   
   // Scan for viruses
   printf("\nScanning file for viruses...");
   char signature[] = "This file contains a virus";
   char buffer[100];
   int read_count = 0;
   while (fgets(buffer, sizeof(buffer), file) != NULL) {
      if (strstr(buffer, signature) != NULL) {
         virus_detected = 1;
         break;
      }
      read_count++;
   }
   fclose(file);
   
   if (virus_detected) {
      printf("\n\nA virus has been detected in file %s.\n", scanned_file);
   }
   else {
      printf("\n\nNo viruses have been detected in file %s.\n", scanned_file);
   }
   
   return 0;
}