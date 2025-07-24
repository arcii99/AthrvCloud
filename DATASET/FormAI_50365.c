//FormAI DATASET v1.0 Category: File handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char ch;

  fp = fopen("data.txt", "r");

  if (fp == NULL) {
    printf("Error reading data from file");
    exit(0);
  }

  printf("Welcome to the cyberpunk world\n");
  printf("Here is an encrypted message for you\n");

  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch ^ 0x1F); // XOR with 0x1F to decrypt the message
  }

  fclose(fp);

  printf("\nMission complete. Have a nice day!");
  return 0;
}