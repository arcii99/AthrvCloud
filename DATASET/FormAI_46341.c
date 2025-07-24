//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h> 
#include <stdlib.h> 

void display_date(int day, int month, int year) { 
  char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  printf("%s %d, %d\n", months[month-1], day, year); 
} 

int main() { 
  int day, month, year; 
  char* date_str = NULL; 
  printf("Enter a date in the format DD/MM/YYYY: "); 
  scanf("%m[^/]/%m[^/]/%d", &day, &month, &year); 
  display_date(day, month, year); 
  return 0; 
}