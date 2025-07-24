//FormAI DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
  char first_name[20] = "John";
  char last_name[20] = "Doe";
  char full_name[40];

  printf("Welcome to my string manipulation program!\n");

  // Concatenating two strings
  strcat(full_name, first_name);
  strcat(full_name, " ");
  strcat(full_name, last_name);

  printf("Your full name is: %s\n", full_name);

  // Reversing a string
  int length = strlen(full_name);
  char reversed[40];

  for (int i = 0; i < length; i++) {
    reversed[i] = full_name[length - i - 1];
  }

  printf("Your name spelled backwards is: %s\n", reversed);

  // Converting string to upper case
  char uppercase_name[40];

  for (int i = 0; i < length; i++) {
    uppercase_name[i] = toupper(full_name[i]);
  }

  printf("Your name in uppercase letters is: %s\n", uppercase_name);

  // Searching for a substring
  char search_for[10] = "Doe";
  char *ptr_to_substring;

  ptr_to_substring = strstr(full_name, search_for);

  if (ptr_to_substring != NULL) {
    printf("Found '%s' in '%s'\n", search_for, full_name);
  } else {
    printf("Could not find '%s' in '%s'\n", search_for, full_name);
  }

  return 0;
}