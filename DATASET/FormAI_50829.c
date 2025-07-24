//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
  char virus[10] = "ILOVEYOU";
  char buffer[100];
  int i = 0;
  printf("My love, please enter the file name to scan for viruses: ");
  scanf("%s", buffer);
  FILE* file = fopen(buffer, "r");
  if (file == NULL) {
    printf("My love, the file does not exist");
    exit(1);
  }
  printf("My love, scanning file: %s \n", buffer);
  while (fread(buffer, 1, 1, file) == 1) {
    if (buffer[0] == virus[i]) {
      i++;
      if (i == strlen(virus)) {
        printf("My love, a virus is detected in file: %s \n", buffer);
        exit(0);
      }
    } else {
      i = 0;
    }
  }
  printf("My love, no viruses found in file: %s \n", buffer);
  fclose(file);
  return 0;
}