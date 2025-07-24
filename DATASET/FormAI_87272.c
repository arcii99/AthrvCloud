//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>

int main() {
  // Excited Error Handling Program
  printf("Welcome to the Excited Error Handling Program!\n");
  printf("This program will help you handle any errors with an amazing flair!\n");

  // Step 1: Define the error codes
  #define ERROR_CODE_1 1
  #define ERROR_CODE_2 2
  #define ERROR_CODE_3 3

  // Step 2: Create the error handling function
  void handle_error(int error_code) {
    switch (error_code) {
      case ERROR_CODE_1:
        printf("Oh no, we have encountered Error Code 1!\n");
        printf("Don't worry, we will fix it in a jiffy!\n");
        break;
      case ERROR_CODE_2:
        printf("Not again, we have stumbled upon Error Code 2!\n");
        printf("But fear not, we will rectify it like a pro!\n");
        break;
      case ERROR_CODE_3:
        printf("Ahh, the dreaded Error Code 3 has appeared!\n");
        printf("Alas, we shall conquer it with our mighty skills!\n");
        break;
      default:
        printf("Oh my, we have encountered an unknown error code!\n");
        printf("Our skilled programmers are on it as we speak!\n");
        break;
    }
  }

  // Step 3: Use the error handling function
  printf("Let's test the error handling function with some sample codes:\n\n");

  int sample_code_1 = ERROR_CODE_1;
  int sample_code_2 = ERROR_CODE_2;
  int sample_code_3 = ERROR_CODE_3;
  int sample_code_4 = 4; // unknown error code

  handle_error(sample_code_1); // should output: Oh no, we have encountered Error Code 1! Don't worry, we will fix it in a jiffy!
  handle_error(sample_code_2); // should output: Not again, we have stumbled upon Error Code 2! But fear not, we will rectify it like a pro!
  handle_error(sample_code_3); // should output: Ahh, the dreaded Error Code 3 has appeared! Alas, we shall conquer it with our mighty skills!
  handle_error(sample_code_4); // should output: Oh my, we have encountered an unknown error code! Our skilled programmers are on it as we speak!

  // Step 4: Party!
  printf("\n\nHooray! We have successfully handled all the errors with an exciting twist!\n");
  printf("Now let's dance and celebrate this amazing achievement!\n");
  
  return 0;
}