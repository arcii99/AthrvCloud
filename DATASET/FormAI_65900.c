//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: excited
#include<stdio.h>
#include<string.h>

int main(){
  printf("Hey there, let's convert some dates!\n");
  
  //get input from user
  printf("What date would you like to convert? (e.g. January 1st, 2022)\n");
  char input[25];
  fgets(input, 25, stdin);
  
  //convert month string to number
  char month[10];
  int monthNum = 0;
  sscanf(input, "%s", month);
  if(strcmp(month, "January") == 0) monthNum = 1;
  else if(strcmp(month, "February") == 0) monthNum = 2;
  else if(strcmp(month, "March") == 0) monthNum = 3;
  else if(strcmp(month, "April") == 0) monthNum = 4;
  else if(strcmp(month, "May") == 0) monthNum = 5;
  else if(strcmp(month, "June") == 0) monthNum = 6;
  else if(strcmp(month, "July") == 0) monthNum = 7;
  else if(strcmp(month, "August") == 0) monthNum = 8;
  else if(strcmp(month, "September") == 0) monthNum = 9;
  else if(strcmp(month, "October") == 0) monthNum = 10;
  else if(strcmp(month, "November") == 0) monthNum = 11;
  else if(strcmp(month, "December") == 0) monthNum = 12;
  
  //get day and year
  int day = 0;
  int year = 0;
  sscanf(input, "%*s %d%*c %d", &day, &year);
  
  //output converted date
  printf("%d/%d/%d\n", monthNum, day, year);
  
  printf("Woo-hoo, we did it! Time to convert some more dates!\n");
  return 0;
}