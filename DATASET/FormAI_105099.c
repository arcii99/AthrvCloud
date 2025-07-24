//FormAI DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>

int main() {
  char text[100], search[20], replace[20], result[100];
  int i, j, start;

  printf("Enter some text: ");
  fgets(text, sizeof(text), stdin);

  printf("\nEnter the word to replace: ");
  scanf("%s", search);

  printf("\nEnter the word to replace with: ");
  scanf("%s", replace);

  start = 0;

  for(i = 0; text[i] != '\0'; i++) {
    if(text[i] == search[0]) {
      for(j = 0; search[j] != '\0' && text[i+j] == search[j]; j++);
      if(search[j] == '\0') {
        for(j = 0; replace[j] != '\0'; j++, start++) {
          result[start] = replace[j];
        }
        i += j - 1;
      } else {
        result[start] = text[i];
        start++;
      }
    } else {
      result[start] = text[i];
      start++;
    }
  }

  result[start] = '\0';

  printf("\n\nOriginal text:\n%s\n", text);
  printf("\nText after replacement:\n%s\n", result);

  return 0;
}