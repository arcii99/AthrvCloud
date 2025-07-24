//FormAI DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* first_name = (char*) malloc(25 * sizeof(char)); // Allocate memory for first name
  char* last_name = (char*) malloc(25 * sizeof(char)); // Allocate memory for last name
  int birth_year, current_year;
  
  printf("Enter your first name: ");
  scanf("%s", first_name);
  
  printf("Enter your last name: ");
  scanf("%s", last_name);
  
  printf("Enter your birth year: ");
  scanf("%d", &birth_year);
  
  printf("Enter current year: ");
  scanf("%d", &current_year);
  
  printf("\n****************************\n");
  printf("Welcome %s %s!\n", first_name, last_name);
  printf("You are %d years old.\n", current_year - birth_year);
  printf("You were born in %d.\n", birth_year);
  
  if (current_year - birth_year >= 18) {
    printf("You are eligible to vote.\n");
  } else {
    printf("You are not eligible to vote yet.\n");
  }
  
  free(first_name); // Free memory for first name
  free(last_name); // Free memory for last name
  
  return 0;
}