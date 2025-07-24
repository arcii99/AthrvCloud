//FormAI DATASET v1.0 Category: System administration ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char command[50];
  printf("Welcome to the Mind-Bending System Administration Program!\n");
  printf("Please enter a command:\n");

  while(1) {
    printf(">> ");
    scanf("%s", command);

    if(strcmp(command, "enigma") == 0) {
      printf("You've discovered the Enigma command! Prepare for a mind-bending experience!\n");
      int num_chars;
      printf("Enter the number of characters you want to generate: ");
      scanf("%d", &num_chars);
      
      char* enigma_chars = (char*) malloc(num_chars * sizeof(char));

      for(int i = 0; i < num_chars; i++) {
        int rand_num = rand() % 94 + 32; // generate a random ASCII char between 32 and 126
        enigma_chars[i] = (char) rand_num;
      }

      printf("Enigma output: ");
      for(int i = 0; i < num_chars; i++) {
        printf("%c", enigma_chars[i]);
      }
      printf("\n");

      free(enigma_chars);
    }
    else if(strcmp(command, "recursive") == 0) {
      printf("You've discovered the Recursive command! Prepare for mind-bending recursion!\n");
      int num_loops;
      printf("Enter the number of times you want to loop recursively: ");
      scanf("%d", &num_loops);

      recursive(num_loops);

      printf("Recursive command complete!\n");
    }
    else if(strcmp(command, "hyperspace") == 0) {
      printf("You've discovered the Hyperspace command! Prepare for a mind-bending warp!\n");
      printf("Are you ready to enter Hyperspace? (y/n): ");
      
      char confirmation;
      scanf(" %c", &confirmation); // make sure to have a space before %c to ignore any whitespace in input
      
      if(confirmation == 'y' || confirmation == 'Y') {
        printf("Warping to Hyperspace...");
        // start warp animation
        printf("\n\n");
        printf("|\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/| \n");
        printf("|\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/| \n");
        printf("|\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/| \n");
        printf("|\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/| \n");
        printf("|\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/| \n");
        printf("|\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/| \n");
        printf("|\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/| \n");
        printf("|\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/| \n");
        printf("|\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/| \n");
        printf("|\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/| \n");
        printf("|____________________*_____*_____*_____*_______| \n");
        printf("|                                                 | \n");
        printf("|                   *     -^-     *               | \n");
        printf("|    *           .*    /_\\_\\_/_\\   *.             | \n");
        printf("|               .*.     * (_) *     *.     *      | \n");
        printf("|               .*.\'             \'.*.            | \n");
        printf("|__   *        .*.   \'  \'\')\'(\'\'  \'   *.   *    __| \n");
        printf("|                             *        .*.      __| \n");
        printf("|             *        *         .*.      .*.__.| \n");
        printf("|                                                 | \n");
        printf("|         *               *              .*.      | \n");
        printf("|    *           *       *           .*.        __| \n");
        printf("|               .*.                    .*.__.   __| \n");
        printf("|               .*.__.           *                 | \n");
        printf("|* ___.  .*.__.        *          .*.    *         | \n");
        printf("|.-\' &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\'-.        *    .*.                 __| \n");
        printf("|\'-=._.-\'-._.-\'-._.-\'-._.-\'-._.-\'-._.-\'-._.-\'-.__| \n");
        printf("\n\n");
        // end warp animation
        printf("You have successfully warped to Hyperspace. Enjoy your mind-bending journey!\n");
      }
      else {
        printf("Warp cancelled. Returning to main menu...\n");
      }
    }
    else {
      printf("Invalid command. Try again.\n");
    }
  }

  return 0;
}

void recursive(int count) {
  if(count <= 0) {
    printf("Recursive loop complete.\n");
    return;
  }

  printf("Recursive loop #%d\n", count);
  recursive(count - 1);
  printf("Exiting recursive loop #%d\n", count);
}