//FormAI DATASET v1.0 Category: QR code reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

// function to check if a given string is a valid QR code
bool isQRCode(char* str) {
  int len = strlen(str);
  int i = 0;

  // check if QR code starts with 'C' and ends with '!'
  if (len >= 3 && str[0] == 'C' && str[len-1] == '!') {
    // check if all characters in between are alphanumeric
    for (i = 1; i < len-1; i++) {
      if (!isalnum(str[i])) {
        return false;
      }
    }
    return true;
  }
  return false;
}

int main() {
  char input[MAX_LENGTH];
  bool validQRCode = false;

  printf("Welcome to the QR code reader!\n");
  printf("Please scan a QR code for processing: ");

  // read input from user
  fgets(input, MAX_LENGTH, stdin);
  // remove newline character from input
  input[strcspn(input, "\n")] = 0;

  // check if input is a valid QR code
  validQRCode = isQRCode(input);
  
  // print output based on validity of QR code
  if (validQRCode) {
    printf("Processing QR code...\n");
    // add code here for processing the QR code
    printf("QR code processed successfully!\n");
  } else {
    printf("Invalid QR code! Please try again.\n");
  }

  return 0;
}