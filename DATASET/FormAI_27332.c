//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mathematical
#include <stdio.h>

int main() {
  char string[100], charToPrint;
  printf("Enter a string for ASCII art:");
  scanf("%s", string);
  
  for (int i = 0; string[i] != '\0'; i++) {
    charToPrint = string[i];
    
    if (charToPrint == ' ') {
      printf("    ");
    } else {
      printf("   |\n");
      printf(" %d ", charToPrint);
      printf("(|) \n");
      printf("   |\n");
    }
  }
  
  return 0;
}