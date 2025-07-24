//FormAI DATASET v1.0 Category: QR code reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODES 50

void read_code(char* code); // function prototype for reading a code
void print_code(char* code); // function prototype for printing a code

int main() {
  char codes[MAX_CODES][30]; // array to store the codes
  int num_codes = 0; // variable to keep track of the number of codes

  printf("Welcome to the surrealist QR code reader!\n");
  printf("Enter up to 50 codes, or enter 'stop' to finish:\n");

  // loop to read in the codes
  while (num_codes < MAX_CODES) {
    char code[30];
    read_code(code);
    if (strcmp(code, "stop") == 0) {
      break;
    }
    strcpy(codes[num_codes], code);
    num_codes++;
  }

  // print out the codes in reverse order
  printf("\n\nThe codes you entered, in reverse order:\n");
  for (int i = num_codes - 1; i >= 0; i--) {
    print_code(codes[i]);
    printf("\n");
  }

  return 0;
}

void read_code(char* code) {
  printf("Enter a code: ");
  fgets(code, 30, stdin);
  strtok(code, "\n"); // get rid of the newline character
}

void print_code(char* code) {
  int len = strlen(code);
  for (int i = 0; i < len; i++) {
    if (code[i] == '0') {
      printf("[:||:]"); // print a surreal face for '0'
    } else {
      printf("[%c]", code[i]); // otherwise just print the character
    }
  }
}