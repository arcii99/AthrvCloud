//FormAI DATASET v1.0 Category: File handling ; Style: happy
#include<stdio.h>

int main(void)
{
   printf("Welcome to the Happy File handling program!\n");
   
   // Creating and opening file for writing
   FILE *fp;
   fp = fopen("happyfile.txt", "w");

   if(fp == NULL)
   {
      printf("Error opening file...Exiting program.");
      return 0;
   }

   // Writing to file
   char happyMessage[] = "This is a happy message written to a file!";
   fputs(happyMessage, fp);

   printf("Successfully written to file!\n");

   // Closing file
   fclose(fp);

   // Opening file for reading
   fp = fopen("happyfile.txt", "r");

   if(fp == NULL)
   {
      printf("Error opening file...Exiting program.");
      return 0;
   }

   // Reading from file
   char readMessage[1000];
   fgets(readMessage, 1000, fp);

   printf("The following message was read from file:\n");
   printf("%s", readMessage);

   // Closing file
   fclose(fp);

   printf("Thank you for using the Happy File handling program!");


   return 0;
}