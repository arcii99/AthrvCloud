//FormAI DATASET v1.0 Category: QR code generator ; Style: funny
#include <stdio.h>

// Function to generate unique QR code
void generate_qr_code(char name[]) {
  printf("Generating QR code for %s...\n", name);
  // Let's add some randomness to the QR code generation process
  int random_num = 10 + (rand() % 90);
  printf("QR code generated successfully! Your code is: C%d%s\n", random_num, name);
}

int main() {
  char name[50];
  printf("Welcome to the QR code generator!\n");
  printf("Please enter your name: ");
  scanf("%s", name);
  printf("Nice to meet you, %s!\n", name);
  printf("Are you ready to generate a unique QR code? (y/n): ");
  char choice;
  scanf(" %c", &choice);
  if (choice == 'y' || choice == 'Y') {
    generate_qr_code(name);
  } else {
    printf("Okay, maybe next time.\n");
  }
  return 0;
}