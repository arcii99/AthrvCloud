//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Zombie Apocalypse Administration Tool!\n");
  printf("Please select an option:\n\n");

  int choice;
  do {
    printf("1. Check for zombie processes\n");
    printf("2. Kill all zombies with your shotgun\n");
    printf("3. Stock up on supplies for the apocalypse\n");
    printf("4. Quit and prepare for the worst\n");
    printf("Enter 1-4: ");
  
    scanf("%d", &choice);
  
    switch (choice) {
      case 1:
        printf("\nChecking for zombie processes...\n");
        system("ps aux | grep Z");
        break;
      case 2:
        printf("\nLoading shotgun...\n");
        printf("BOOM! You killed all the zombies!\n");
        system("kill -9 $(ps aux | grep Z | awk '{print $2}')");
        break;
      case 3:
        printf("\nStocking up on supplies...\n");
        printf("You have collected:\n- 5 cans of beans\n- 3 bottles of water\n- 2 boxes of band-aids\n- 1 roll of toilet paper\n");
        break;
      case 4:
        printf("\nGoodbye! Remember to always aim for the head.\n");
        break;
      default:
        printf("\nInvalid choice. Please select 1-4.\n");
        break;
    }
  } while (choice != 4);

  return 0;
}