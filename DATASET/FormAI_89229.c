//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char date[11], month[4], year[5], *p;
   int d, m, y;
   printf("Enter the date in natural language format (eg: March 1, 2022): ");
   fgets(date, sizeof(date), stdin);
   strtok(date, " ,\n");
   strncpy(month, date, 3);
   month[3] = '\0';
   p = strtok(NULL, " ,\n");
   d = atoi(p);
   p = strtok(NULL, " ,\n");
   strcpy(year, p);
   y = atoi(year);
   if (strcmp(month, "January") == 0) {
      m = 1;
   } else if (strcmp(month, "February") == 0) {
      m = 2;
   } else if (strcmp(month, "March") == 0) {
      m = 3;
   } else if (strcmp(month, "April") == 0) {
      m = 4;
   } else if (strcmp(month, "May") == 0) {
      m = 5;
   } else if (strcmp(month, "June") == 0) {
      m = 6;
   } else if (strcmp(month, "July") == 0) {
      m = 7;
   } else if (strcmp(month, "August") == 0) {
      m = 8;
   } else if (strcmp(month, "September") == 0) {
      m = 9;
   } else if (strcmp(month, "October") == 0) {
      m = 10;
   } else if (strcmp(month, "November") == 0) {
      m = 11;
   } else if (strcmp(month, "December") == 0) {
      m = 12;
   }
   printf("The date in C natural language format is: %d/%d/%d\n", m, d, y);
   return 0;
}