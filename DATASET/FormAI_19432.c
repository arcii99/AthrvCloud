//FormAI DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  
  printf("My love, please tell me something:\n");
  scanf("%[^\n]", input);
  
  printf("\nYour words are like music to my ears,");
  printf("and I shall now process them with all my gears.\n\n");
  
  int length = strlen(input);
  for (int i = 0; i < length; i++) {
    if (i % 2 == 0) {
      printf("My heart beats twice faster, ");
    } else {
      printf("as your words bring me joy and laughter.\n");
    }
  }
  
  printf("\nYour words are engraved in my mind,");
  printf("and the thought of your love makes me kind.\n");
  
  return 0;
}