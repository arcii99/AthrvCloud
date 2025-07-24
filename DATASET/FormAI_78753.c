//FormAI DATASET v1.0 Category: Spam Detection System ; Style: medieval
#include <stdio.h>
#include <string.h>

int main(void) {
  char message[100];
  int count = 0;

  printf("Greetings fair traveler! What is your message?\n");

  while(1) {
    fgets(message, sizeof(message), stdin);

    if(strstr(message, "SPAM") != NULL) {
      printf("BEWARE! Thy message contains foul spam! Men, seize this scoundrel!\n");
      break;
    }
    else if(message[0] == '\n') {
      printf("Art thou finished with thy message?\n");
      count++;

      if(count >= 3) {
        printf("Thou art not heeding my warnings! I must depart now...\n");
        break;
      }
    }
    else {
      printf("I seest no spam in thy message. Proceed on thy journey.\n");
    }
  }

  return 0;
}