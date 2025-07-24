//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: standalone
#include <stdio.h>

int main() {
  char str[100];
  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  printf("The ASCII art representation of the string is:\n");
  for (int i = 0; i < strlen(str); i++) {
    switch(str[i]) {
      case 'A':
        printf("  /\\  \n /  \\ \n/----\\\n");
        break;
      case 'B':
        printf(" ___ \n|_  )\n / / \n/___|\n");
        break;
      case 'C':
        printf("  ___ \n / __)\n( (__ \n \\___)\n");
        break;
      case 'D':
        printf(" ___ \n|_  )\n | | \n|___)\n");
        break;
      case 'E':
        printf(" ____\n|___ \\\n ___) |\n|____/\n");
        break;
      case 'F':
        printf(" ____\n|___ \\\n ___) |\n|    |\n");
        break;
      case 'G':
        printf("  ___ \n / __)\n( (_ \\ \n \\___/\n");
        break;
      case 'H':
        printf(" _   _ \n| | | |\n| |_| |\n \\___/ \n");
        break;
      case 'I':
        printf(" ___ \n|_  )\n / / \n/___|\n");
        break;
      case 'J':
        printf("    _ \n   | |\n   | |\n\\__/ \n");
        break;
      case 'K':
        printf(" _  __\n| |/ /_\n| ' / /\n|_|\\_\\\n");
        break;
      case 'L':
        printf(" _    \n| |   \n| |___\n|_____| \n");
        break;
      case 'M':
        printf(" __  __ \n|  \\/  |\n| |\\/| |\n|_|  |_|\n");
        break;
      case 'N':
        printf(" _   _ \n| \\ | |\n|  \\| |\n|_|\\__|\n");
        break;
      case 'O':
        printf("  ___ \n / _ \\\n| (_) |\n \\___/\n");
        break;
      case 'P':
        printf(" ___ \n|_  )\n / / \n/___|\n");
        break;
      case 'Q':
        printf("  ___ \n / _ \\\n| (_) |\n \\__, |\n    |_|\n");
        break;
      case 'R':
        printf(" ___ \n|_  )\n / /_\n/____|\n");
        break;
      case 'S':
        printf(" ____ \n/ ___)\n\\___ \\\n(____/\n");
        break;
      case 'T':
        printf(" _____\n|_   _|\n  | |  \n  |_|  \n");
        break;
      case 'U':
        printf(" _   _ \n| | | |\n| | | |\n \\___/ \n");
        break;
      case 'V':
        printf(" _   _ \n| | | |\n| | | |\n \\ V / \n  \\_/  \n");
        break;
      case 'W':
        printf(" _    _ \n| |  | |\n| |/\\| |\n|__/\\__/ |\n\\____/\\__/\n");
        break;
      case 'X':
        printf("__  __\n\\ \\/ /\n \\  / \n /  \\ \n/_/\\_\\\n");
        break;
      case 'Y':
        printf("__   __\n\\ \\ / /\n \\ V / \n  | |  \n  |_|  \n");
        break;
      case 'Z':
        printf(" ____\n|___ \\\n  __) |\n |____/\n");
        break;
      case ' ':
        printf("\n\n\n");
        break;
      default:
        printf("  /\_/\\ \n ( o.o )\n/ > ^ <\\n");
        break;
    }
  }

  return 0;
}