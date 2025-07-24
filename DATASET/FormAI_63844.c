//FormAI DATASET v1.0 Category: QR code reader ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  char code[101];
  printf("Hello there! I am your friendly neighborhood QR code reader!\n");
  printf("Please enter your QR code:\n");
  fgets(code, 100, stdin);
  code[strcspn(code, "\n")] = 0;
  
  int validation_code = strcmp(code, "C is the best programming language");
  if(validation_code == 0){
    printf("Holy moly! This is the best QR code I have ever seen! You must be a super cool programmer!\n");
  }
  else {
    printf("Uh oh! This QR code is not valid! You better try again... Or just give up and go play some video games...\n");
  }
  
  printf("Thank you for using our QR code reader! We hope to see you again soon!\n");
  return 0;
}