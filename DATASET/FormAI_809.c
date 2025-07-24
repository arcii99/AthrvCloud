//FormAI DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char text[1000], search_term[100], replace_term[100], new_text[1000];
  int i, j, k, l, flag = 0;

  // Getting input from user
  printf("Enter the text: ");
  fgets(text, sizeof(text), stdin);

  printf("Enter the term you want to replace: ");
  scanf("%s", search_term);

  printf("Enter the new term that you want to replace with: ");
  scanf("%s", replace_term);

  // Replacing search term with new term in the text
  l = strlen(search_term);
  for (i = 0; text[i] != '\0'; i++) {
    flag = 0;
    k = i;
    for (j = 0; j < l; j++) {
      if (text[k] == search_term[j]) {
        k++;
      } else {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      for (j = 0; replace_term[j] != '\0'; j++, k++) {
        new_text[j] = replace_term[j];
      }
      i = k - 1;
    } else {
      new_text[i] = text[i];
    }
  }

  // Displaying the updated text
  printf("\nUpdated text: ");
  for (i = 0; new_text[i] != '\0'; i++) {
    printf("%c", new_text[i]);
  }

  return 0;
}