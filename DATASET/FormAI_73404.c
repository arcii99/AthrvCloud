//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  printf("#########################\n");
  printf("#  Cyber Fortune Teller #\n");
  printf("#  By: Your Name Here   #\n");
  printf("#########################\n\n");

  char input;
  int num;
  srand(time(0));

  do {
    printf("Ask a question: ");
    fflush(stdin);
    scanf("%c", &input);

    num = rand() % 5;
    switch(num) {
      case 0:
        printf("The future looks bleak, beware.\n\n");
        break;
      case 1:
        printf("I see success in your future.\n\n");
        break;
      case 2:
        printf("There is danger on the horizon, take caution.\n\n");
        break;
      case 3:
        printf("I sense a new opportunity coming your way.\n\n");
        break;
      case 4:
        printf("Your luck is about to change for the better.\n\n");
        break;
    }
    printf("Enter Q to quit or any other key to ask another question: ");
    fflush(stdin);
    scanf("%c", &input);
  } while(input != 'Q' && input != 'q');

  printf("\nThank you for using Cyber Fortune Teller. Goodbye...\n");
  return 0;
}