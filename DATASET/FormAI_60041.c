//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
   char infectedFiles[5][20] = {"dragon.exe", "troll.dll", "wizard.vbs", "knight.bin", "queen.sys"};
   int numOfInfectedFiles = 5;
   char userFile[20];

   printf("Welcome to Medieval Antivirus Scanner. Our kingdom's security is our top priority!\n");
   printf("Please enter the file name you want to scan: ");
   scanf("%s", userFile);

   for(int i = 0; i < numOfInfectedFiles; i++) {
      if(strcmp(userFile, infectedFiles[i]) == 0) {
         printf("\nALERT! ALERT! %s is infected with a deadly virus.\n", userFile);
         printf("Our knights will immediately quarantine the file to prevent further damage.\n");
         printf("Thank you for using Medieval Antivirus Scanner, your trusted protector!\n");
         return 0;
      }
   }

   printf("\nYour file is safe and not infected with any virus.\n");
   printf("Thank you for using Medieval Antivirus Scanner, your trusted protector!\n");
   return 0;
}