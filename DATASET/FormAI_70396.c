//FormAI DATASET v1.0 Category: Syntax parsing ; Style: grateful
#include <stdio.h>

int main() {
  char str[100];
  int count = 0;

  printf("Enter a sentence:\n");
  fgets(str, sizeof(str), stdin);

  for(int i = 0; str[i] != '\0'; i++) {
    if(str[i] == '{' || str[i] == '(' || str[i] == '[') {
        count++;
    } else if(str[i] == '}' || str[i] == ')' || str[i] == ']') {
        count--;
    }
  }

  if(count == 0) {
    printf("The input sentence has balanced symbols!\n");
  } else {
    printf("The input sentence does not have balanced symbols.\n");
  }

  return 0;
}