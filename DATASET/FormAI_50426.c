//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <ctype.h>

int main() {
  int count_upper = 0, count_lower = 0, count_digit = 0;
  char text[100];

  printf("Enter a text: ");
  fgets(text, 100, stdin);

  for(int i = 0; text[i] != '\0'; i++) {
    if(isupper(text[i]))
      count_upper++;
    else if(islower(text[i]))
      count_lower++;
    else if(isdigit(text[i]))
      count_digit++;
  }

  printf("Number of uppercase letters: %d\n", count_upper);
  printf("Number of lowercase letters: %d\n", count_lower);
  printf("Number of digits: %d\n", count_digit);

  return 0;
}