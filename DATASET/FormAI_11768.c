//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include<stdio.h>
#include<string.h>

char* month_code(char month_name[]) {
  if(strcmp(month_name, "January")==0) return "01";
  else if (strcmp(month_name, "February")==0) return "02";
  else if (strcmp(month_name, "March")==0) return "03";
  else if (strcmp(month_name, "April")==0) return "04";
  else if (strcmp(month_name, "May")==0) return "05";
  else if (strcmp(month_name, "June")==0) return "06";
  else if (strcmp(month_name, "July")==0) return "07";
  else if (strcmp(month_name, "August")==0) return "08";
  else if (strcmp(month_name, "September")==0) return "09";
  else if (strcmp(month_name, "October")==0) return "10";
  else if (strcmp(month_name, "November")==0) return "11";
  else if (strcmp(month_name, "December")==0) return "12";
}

int main() {
  char date[80], day[3], month_name[10], year[5];
  printf("Enter date in natural language: ");
  gets(date);
  sscanf(date, "%s %s %s", day, month_name, year);
  printf("Date in C Natural Language format: %s-%s-%s\n",year,month_code(month_name),day);
  return 0;
}