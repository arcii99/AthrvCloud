//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: artistic
#include <stdio.h>

int main() {
  char virus[7] = {'M', 'a', 'l', 'w', 'a', 'r', 'e'};
  char input[256] = "";
  int match = 0;
  
  printf("Welcome to C Antivirus!\n");
  printf("Please enter the file name to be scanned: ");
  scanf("%s", input);

  FILE *file;
  file = fopen(input, "r");

  if (file == NULL) {
    printf("File not found or could not be opened.\n");
    return 1;
  }

  while (!feof(file)) {
    char c = fgetc(file);

    if (c == virus[match]) {
      match++;

      if (match == 7) {
        printf("Virus detected!\n");
        fclose(file);
        return 0;
      }
    }
    else {
      match = 0;
    }
  }

  printf("No virus found.\n");
  fclose(file);
  return 0;
}