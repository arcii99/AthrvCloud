//FormAI DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int day;
   int month;
   int year;
} Date;

typedef struct {
   Date date;
   char message[255];
} DiaryEntry;

int main() {
   int numOfEntries;
   printf("How many entries would you like to make? ");
   scanf("%d", &numOfEntries);
   
   DiaryEntry *entries = (DiaryEntry*) malloc(numOfEntries * sizeof(DiaryEntry));
   for (int i = 0; i < numOfEntries; i++) {
      printf("\nEntry #%d:\n", i+1);
      printf("Date (dd/mm/yyyy): ");
      scanf("%d/%d/%d", &entries[i].date.day, &entries[i].date.month, &entries[i].date.year);
      printf("Message: ");
      scanf("%s", entries[i].message);
   }
   
   printf("\n*** Diary Entries ***\n");
   for (int i = 0; i < numOfEntries; i++) {
      printf("\nEntry #%d:\n", i+1);
      printf("Date: %02d/%02d/%04d\n", entries[i].date.day, entries[i].date.month, entries[i].date.year);
      printf("Message: %s\n", entries[i].message);
   }
   
   free(entries);
   return 0;
}