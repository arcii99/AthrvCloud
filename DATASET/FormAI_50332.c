//FormAI DATASET v1.0 Category: QR code generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  char qr_code[21];

  printf("Generating a unique Cyberpunk-style C QR code...\n");

  for (int i = 0; i < 21; i++) {
    int random_num = (rand() % 26) + 65; // random capital letter
    if (i == 5 || i == 11 || i == 17) {
      sprintf(&qr_code[i], "-");
    } else {
      sprintf(&qr_code[i], "%c", random_num);
    }
  }

  printf("Generated QR code: %s\n", qr_code);

  return 0;
}