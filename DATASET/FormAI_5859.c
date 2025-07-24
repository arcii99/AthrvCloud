//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char filename[20];
  printf("Enter filename to scan: ");
  scanf("%s", filename);
  FILE *file = fopen(filename, "r");

  if (!file) {
    printf("Error opening file.\n");
    return 1;
  }

  char c;
  int line_num = 1;
  int virus_detected = 0;

  while ((c = fgetc(file)) != EOF) {
    if (c == '/') {
      c = fgetc(file);
      if (c == '/') {
        // virus detected
        printf("Virus detected on line %d.\n", line_num);
        virus_detected = 1;
        break;
      } else {
        ungetc(c, file);
      }
    } else if (c == '\n') {
      line_num++;
    }
  }

  fclose(file);

  if (!virus_detected) {
    printf("No virus detected.\n");
  }

  return 0;
}