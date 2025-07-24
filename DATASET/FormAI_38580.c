//FormAI DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>

int main() {
   int day, month, year;
   float temperature;
   char entry[1000];

   printf("Enter the date (dd.mm.yyyy): ");
   scanf("%d.%d.%d", &day, &month, &year);

   printf("Enter the temperature in Celsius: ");
   scanf("%f", &temperature);

   printf("Enter your journal entry: ");
   scanf(" %[^\n]s", entry);

   FILE *filepointer;
   char filename[50];
   sprintf(filename, "%d%d%d.txt", day, month, year); // create filename based on date
   filepointer = fopen(filename, "w");

   fprintf(filepointer, "Date: %d.%d.%d\n", day, month, year);
   fprintf(filepointer, "Temperature (Celsius): %.2f\n", temperature);
   fprintf(filepointer, "\nJournal Entry:\n%s", entry);

   printf("Entry saved to file %s.\n", filename);
   fclose(filepointer);

   return 0;
}