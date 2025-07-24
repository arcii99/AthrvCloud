//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t now = time(NULL);
  struct tm *t = localtime(&now);

  int year;
  printf("Enter year to travel to: ");
  scanf("%d", &year);

  printf("\nToday is %d-%02d-%02d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
  printf("Travelling to %d...\n", year);

  int years_travelled = year - (t->tm_year + 1900);
  t->tm_year += years_travelled;
  
  time_t new_time = mktime(t);
  t = localtime(&new_time);

  printf("You have travelled %d years into the future.\n", years_travelled);
  printf("The date is now %d-%02d-%02d.\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

  return 0;
}