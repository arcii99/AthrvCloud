//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: puzzling
#include <stdio.h>

int main() {
   int day, month, year;
   printf("Enter the date in natural language format (e.g March 14, 2002): ");
   scanf("%s %d, %d", month, &day, &year);
   
   if (month == "January") {
     month = 1;
   } else if (month == "February") {
     month = 2;
   } else if (month == "March") {
     month = 3;
   } else if (month == "April") {
     month = 4;
   } else if (month == "May") {
     month = 5;
   } else if (month == "June") {
     month = 6;
   } else if (month == "July") {
     month = 7;
   } else if (month == "August") {
     month = 8;
   } else if (month == "September") {
     month = 9;
   } else if (month == "October") {
     month = 10;
   } else if (month == "November") {
     month = 11;
   } else if (month == "December") {
     month = 12;
   } else {
     printf("Invalid month");
     return 0;
   }
   
   printf("The date in numerical format is: %d/%d/%d", month, day, year);
   
   return 0;
}