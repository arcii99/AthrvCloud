//FormAI DATASET v1.0 Category: QR code generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 21

char* generate_code() {
  char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *code = malloc(SIZE * sizeof(char));
  int index;

  srand(time(NULL));
  for (int i = 0; i < SIZE - 1; i++) {
    index = rand() % strlen(charset);
    code[i] = charset[index];
  }

  code[SIZE - 1] = '\0';

  return code;
}

void generate_qr_code(char *code) {
  // Cyberpunk-style QR code generation
  printf("Generating QR code for: %s\n", code);
  printf(" █  ████╗ █████╗  ██████╗██╗  ██╗    ██╗     ██╗██╗  ██╗██████╗ \n");
  printf(" ██╗██╔══██╗██╔══██╗██╔════╝██║ ██╔╝    ██║     ██║██║ ██╔╝██╔══██╗\n");
  printf(" ██║███████║███████║██║     █████╔╝     ██║     ██║█████╔╝ ██║  ██║\n");
  printf(" ██║██╔══██║██╔══██║██║     ██╔═██╗     ██║     ██║██╔═██╗ ██║  ██║\n");
  printf(" ██║██║  ██║██║  ██║╚██████╗██║  ██╗    ███████╗██║██║  ██╗██████╔╝\n");
  printf(" ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝    ╚══════╝╚═╝╚═╝  ╚═╝╚═════╝ \n");
  printf(" QR code generated.\n");
}

int main() {
  char *code = generate_code();

  generate_qr_code(code);

  free(code);
  
  return 0;
}