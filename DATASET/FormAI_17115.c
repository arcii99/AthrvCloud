//FormAI DATASET v1.0 Category: String manipulation ; Style: single-threaded
#include <stdio.h>
#include <string.h>

int main() {
  char str[100], substr[20];

  printf("Enter a string: ");
  fgets(str, 100, stdin);

  printf("Enter a substring to search for: ");
  scanf("%s", substr);

  int len_str = strlen(str);
  int len_substr = strlen(substr);
  int count = 0;

  for (int i = 0; i <= len_str - len_substr; i++) {
    int j;
    for (j = 0; j < len_substr; j++) {
      if (str[i+j] != substr[j]) {
        break;
      }
    }
    if (j == len_substr) {
      count++;
    }
  }

  printf("The substring \"%s\" appears %d times in the string \"%s\"\n", substr, count, str);

  // Now let's reverse the string

  int start = 0;
  int end = strlen(str) - 1;

  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }

  printf("The reversed string is \"%s\"\n", str);

  return 0;
}