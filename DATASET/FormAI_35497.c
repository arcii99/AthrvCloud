//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char sourceText[50], watermark[10], embeddedText[60];

  // Get the source text
  printf("Enter the source text (up to 50 characters): ");
  fgets(sourceText, 50, stdin);

  // Get the watermark
  printf("Enter the watermark (up to 10 characters): ");
  fgets(watermark, 10, stdin);

  // Embed the watermark
  int i, j = 0;
  for (i = 0; i < strlen(sourceText); i++) {
    if (j < strlen(watermark)) {
      embeddedText[i] = watermark[j];
      j++;
    } else {
      embeddedText[i] = sourceText[i - j];
    }
  }
  embeddedText[i] = '\0';

  // Print the embedded text
  printf("Embedded text: %s\n", embeddedText);

  // Detect the watermark
  int match = 1;
  for (i = 0; i < strlen(watermark); i++) {
    if (watermark[i] != embeddedText[i]) {
      match = 0;
      break;
    }
  }
  if (match) {
    printf("Watermark detected!\n");
  } else {
    printf("Watermark not detected.\n");
  }

  return 0;
}