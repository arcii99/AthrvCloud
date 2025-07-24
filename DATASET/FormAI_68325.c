//FormAI DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define structure for storing name and age
struct person {
  char name[50];
  int age;
};

int parseAge(char* str) {
  // Function to parse age from a given string
  int i = 0;
  int num = 0;
  while(str[i] >= '0' && str[i] <= '9') {
    num = num * 10 + (str[i] - '0');
    i++;
  }
  return num;
}

int main() {
  // Declare variables
  char string[100];
  struct person p;

  // Get user input for name
  printf("Enter your name: ");
  fgets(p.name, 50, stdin);

  // Get user input for age
  printf("Enter your age: ");
  fgets(string, 100, stdin);
  p.age = parseAge(string);

  // Print out the user information
  printf("Your name is %s and you are %d years old.\n", p.name, p.age);

  return 0;
}