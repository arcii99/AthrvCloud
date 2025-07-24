//FormAI DATASET v1.0 Category: String manipulation ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {
  char s1[] = "The purple giraffe spoke to the flying toaster";
  char s2[50];

  // surrealistically manipulate the string
  int i, j;
  for (i = 0, j = strlen(s1) - 1; j >= 0; i++, j--) {
    s2[i] = s1[j];
  }

  printf("Original String: %s\n", s1);
  printf("Surrealistically Manipulated String: %s\n", s2);

  // replace every odd letter with 'z'
  for (i = 0; s2[i] != '\0'; i++) {
    if (i % 2 == 0) {
      s2[i] = 'z';
    }
  }

  printf("String with Every Odd Letter Replaced by 'z': %s\n", s2);

  // replace every occurrence of the word 'purple' with 'plaid'
  char *pos = strstr(s2, "purple");
  while (pos != NULL) {
    strncpy(pos, "plaid", 5);
    pos = strstr(s2, "purple");
  }

  printf("Final String with 'purple' replaced by 'plaid': %s\n", s2);

  return 0;
}