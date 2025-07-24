//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: surrealist
#include <stdio.h>

int main() {
  char text[50];
  
  printf("Enter the text you want to convert to ASCII art: ");
  scanf("%[^\n]", text);
  
  int length = strlen(text);
  
  for(int i = 0; i < length; i++) {
    switch(text[i]) {
      case 'a':
        printf("   /\\  \n  /  \\ \n /----\\\n/      \\\n");
        break;
      case 'b':
        printf("|------| \n|      |\n|------|\n|      |\n|------|\n");
        break;
      case 'c':
        printf("  ____ \n /     \\\n|       \\\n|_______|\n");
        break;
      case 'd':
        printf("|-----\\\n|      \\\n|       |\n|      /\n|_____/\n");
        break;
      case 'e':
        printf(" ______\n|       \n|__     \n   |    \n|______ \n");
        break;
      case 'f':
        printf(" ______\n|       \n|__     \n   |    \n   |    \n");
        break;
      case 'g':
        printf(" ______\n/      \n|   __ \n|____| |\n\\______|\n");
        break;
      case 'h':
        printf("|      |\n|------|\n|      |\n|      |\n|      |\n");
        break;
      case 'i':
        printf("  ___ \n    |\n    |\n    |\n \\__|\n");
        break;
      case 'j':
        printf("     /\n    /\n    |\n    |\n\\__/ \n");
        break;
      case 'k':
        printf("|      /\n|-----/\n|  |\\  \n|  | \\ \n|   \\ \\\n");
        break;
      case 'l':
        printf("|      \n|      \n|      \n|      \n|______\n");
        break;
      case 'm':
        printf("|\\    /|\n| \\  / |\n|  \\/  |\n|      |\n|      |\n");
        break;
      case 'n':
        printf("|\\     |\n| \\    |\n|  \\   |\n|   \\  |\n|    \\ |\n");
        break;
      case 'o':
        printf("  ___ \n /   \\\n|     |\n|     |\n \\___/\n");
        break;
      case 'p':
        printf("|------|\n|      |\n|------|\n|       \n|       \n");
        break;
      case 'q':
        printf("  ____ \n /    \\\n|      |\n|      |\n \\____/\n      \\\n       \\\\_\n");
        break;
      case 'r':
        printf("|------|\n|      |\n|------|\n|  \\   \n|   \\  |\n");
        break;
      case 's':
        printf(" _____\n/     \\\n\\_____/\n      \\\n\\_____/\n");
        break;
      case 't':
        printf(" ______\n    |\n    |\n    |\n    |\n");
        break;
      case 'u':
        printf("|      |\n|      |\n|      |\n|      |\n \\____/\n");
        break;
      case 'v':
        printf("\\      /\n \\    / \n  \\  /  \n   \\/   \n");
        break;
      case 'w':
        printf("|      |\n|      |\n|  /\\  |\n| /\\/\\ |\n|/    \\|\n");
        break;
      case 'x':
        printf("\\    /\n \\/\\/\n /\\ \\\n/  \\\\\n");
        break;
      case 'y':
        printf("\\    /\n \\/\\/ \n  ||   \n  ||   \n /  \\\n");
        break;
      case 'z':
        printf(" ______\n     /\n    /\n   /\n  /____\n");
        break;
      case ' ':
        printf("\n     \n     \n     \n     \n");
        break;
      default:
        printf("\n     \n     \n     \n     \n");
        break;
    }
  }
  
  return 0;
}