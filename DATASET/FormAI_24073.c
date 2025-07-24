//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to the Happy ASCII Art Generator!\n\n");
  printf("Enter your happy message: ");
  char message[100];
  fgets(message, 100, stdin);
  printf("\n");

  printf("Your ASCII art is:\n");

  // Creating the happy face
  printf("       ___       \n");
  printf("     .'   '.     \n");
  printf("    /       \\   \n");
  printf("   /  o     o  \\  \n");
  printf("  |             |   \n");
  printf("  |  \\   ^   /  |   \n");
  printf("   \\  '-._.-' /   \n");
  printf("    \\        /     \n");
  printf("     '------'\n\n");

  // Converting message to ASCII art
  int i = 0;
  while (message[i]) {
    switch (message[i]) {
      case 'a':
        printf(".~~.\n");
        printf("`..'\n");
        break;
      case 'b':
        printf(".~~.\n");
        printf("|__|_________\n");
        printf("|__|        )\n");
        printf("|  |  /     /\n");
        printf("|_/|_/____/\n");
        break;
      case 'c':
        printf("   __\n");
        printf(" /    \\\n");
        printf("|      |\n");
        printf("|      |\n");
        printf(" \\____/\n");
        break;
      case 'd':
        printf(".~~.\n");
        printf("|__|_______\n");
        printf("|__|_______|\n");
        printf("|           \\\n");
        printf("|___________|\n");
        break;
      case 'e':
        printf(".~~.\n");
        printf("|__|_________\n");
        printf("|__|        \n");
        printf("|           \n");
        printf("|___________\n");
        break;
      case 'f':
        printf(".~~.\n");
        printf("|__|_________\n");
        printf("|__|\n");
        printf("|   \n");
        printf("|   \n");
        break;
      // Add more cases for other characters and symbols as desired
      default:
        printf("   \n");
        printf("   \n");
        printf("   \n");
        printf("   \n");
        printf("   \n");
    }
    i++;
  }

  return 0;
}