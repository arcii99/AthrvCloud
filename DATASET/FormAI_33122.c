//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int year[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("No date given!\n");
    return 0;
  }
  char* date = argv[1];

  char temp[8];
  strncpy(temp, date + 4, 2);
  temp[2] = '\0';
  int day = atoi(temp);

  strncpy(temp, date + 2, 2);
  temp[2] = '\0';
  int monthNum = atoi(temp);

  strncpy(temp, date, 2);
  temp[2] = '\0';
  int yearNum = atoi(temp);

  printf("The converted date is: %s %d, %d\n", month[monthNum-1], day, yearNum);

  return 0;
}