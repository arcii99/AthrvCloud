//FormAI DATASET v1.0 Category: String manipulation ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#define MAX_CHARS 100

int main() {
  char input_str[MAX_CHARS];
  char sub_str[MAX_CHARS];
  int index = 0, count = 0, len = 0;
   
  printf("Enter a string:\n");
  scanf("%[^\n]s", input_str);
   
  printf("Enter a substring to search:\n");
  scanf(" %[^\n]s", sub_str);
   
  len = strlen(sub_str);
   
  while (input_str[index] != '\0') {
    if (strncmp(&input_str[index], sub_str, len) == 0) {
      count++;
      index += len;
    } else {
      index++;
    }
  }
   
  printf("The substring %s occured %d times in %s\n", sub_str, count, input_str);
   
  return 0;
}