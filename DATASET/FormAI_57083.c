//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the C Antivirus Scanner!\n");
  printf("Let me make sure your code is nice and clean\n");
  
  char code[2000];
  printf("Please enter your code: ");
  scanf("%s", code);
  
  int isVirus = 0;
  for (int i = 0; i < strlen(code); i++) {
    if (code[i] == 'v' && code[i+1] == 'i' && code[i+2] == 'r' && code[i+3] == 'u' && code[i+4] == 's') {
      printf("Virus detected! Deleting all files... just kidding. False alarm.\n");
      isVirus = 1;
      break;
    }
  }
  
  if (!isVirus) {
    printf("No viruses detected! Your code is squeaky clean!\n");
  }
  
  printf("Hope you had a fun time with our C Antivirus Scanner. Good luck with your coding!\n");
  return 0;
}