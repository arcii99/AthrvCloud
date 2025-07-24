//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: happy
#include <stdio.h>
#include <string.h>

void digital_watermark(char *message, char* watermark) {
  int len = strlen(watermark) - 1;
  int i = 0;
  while (*message != '\0' && *watermark != '\0') {
    *message += *watermark;
    watermark++;
    i++;
    if (i == len && *(watermark + 1) != '\0') {
      watermark = watermark - i;
      i = 0;
    }
    message++;
  }
}

int main() {
  char message[1024] = "The quick brown fox jumps over the lazy dog";
  char watermark[1024] = "Watermark";

  printf("Before Watermarking: %s\n", message);

  digital_watermark(message, watermark);

  printf("After Watermarking: %s\n", message);

  return 0;
}