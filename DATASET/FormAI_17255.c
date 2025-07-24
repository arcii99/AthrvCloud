//FormAI DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>

int main() {
   char diaryEntry[500]; // array to store diary entries
   int dayOfMonth, month, year; // variables to record date
   char confirm; // variable to confirm entry saved
   int numEntries = 0; // variable to count number of diary entries
   
   printf("Welcome to your Digital Diary!\n\n");
   
   do {
      printf("Enter today's date (DD/MM/YYYY): ");
      scanf("%d/%d/%d", &dayOfMonth, &month, &year);
      printf("Write your entry (max 500 characters):\n");
      scanf(" %[^\n]s", diaryEntry);
      numEntries++;
      printf("Entry saved. Would you like to make another entry? (Y/N): ");
      scanf(" %c", &confirm);
   } while(confirm == 'Y' || confirm == 'y');

   printf("\n\nYour diary entries:\n\n");
   printf("**************************************\n");
   printf("Total entries: %d\n", numEntries);
   printf("**************************************\n\n");

   int i;
   for (i = 1; i <= numEntries; i++) {
      printf("Entry #%d:\n", i);
      printf("Date: %d/%d/%d\n", dayOfMonth, month, year);
      printf("Entry: %s\n", diaryEntry);
      printf("**************************************\n");
   }

   printf("Thank you for using your Digital Diary!");

   return 0;
}