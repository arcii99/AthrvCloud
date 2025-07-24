//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>

int main()
{
  char text[100];
  
  printf("Enter your text: ");
  scanf("%[^\n]", text);
  
  for(int i=0; text[i]!='\0'; i++)
  {
    switch(text[i])
    {
      case 'a':
        printf("  .-. \n /   \\ \n|     |\n \\_v_/\n");
        break;
      case 'b':
        printf("  _  \n |_) \n |_) \n");
        break;
      case 'c':
        printf("  ___ \n / __|\n| (__ \n \\___|\n");
        break;
      case 'd':
        printf("   _  \n  | | \n  | | \n  |_| \n");
        break;
      case 'e':
        printf("  ___ \n | __|\n| _| \n|___|\n");
        break;
      case 'f':
        printf("  ___ \n | __|\n| _| \n|_|  \n");
        break;
      case 'g':
        printf("  ___ \n / __|\n| (_ \n \\___|\n");
        break;
      case 'h':
        printf("  _  _ \n | || |\n | __ |\n |_||_|\n");
        break;
      case 'i':
        printf("  _ \n (_)\n | |\n |_|");
        break;
      case 'j':
        printf("     _ \n    (_)\n    | |\n _  | |\n| |_| |\n \\___/ \n");
        break;
      case 'k':
        printf("  _  __\n | |/ /\n | ' < \n |_|\\_\\\n");
        break;
      case 'l':
        printf("  _    \n | |   \n | |   \n |_|__ \n |_|__|\n");
        break;
      case 'm':
        printf("  _  __\n | |/ /\n | ' < \n |_|\\_\\\n");
        break;
      case 'n':
        printf("  _  _ \n | \\| |\n | . ` |\n |_|\\_\\\n");
        break;
      case 'o':
        printf("  ___ \n / _ \\ \n| (_) |\n \___/\n");
        break;
      case 'p':
        printf("  ___ \n | _ \\ \n |  _/\n |_| \n");
        break;
      case 'q':
        printf("  ___ \n / _ \\ \n| (_) |\n \\__/\n   \\\\ \n");
        break;
      case 'r':
        printf("  ___ \n | _ \\ \n |   /\n |_|_\\\n");
        break;
      case 's':
        printf("  ___  \n / __| \n \\__ \\ \n |___/\n");
        break;
      case 't':
        printf("  _ \n |_|\n | |\n |_|\n");
        break;
      case 'u':
        printf("  _  _ \n | | | |\n | |_| |\n  \\___/\n");
        break;
      case 'v':
        printf("  _    _ \n | |  | |\n | |  | |\n  \\__/  \n");
        break;
      case 'w':
        printf("  _    _ \n | |  | |\n | |/\\| |\n |__/\\__|\n");
        break;
      case 'x':
        printf("  _  _ \n | \\/ |\n | |\\/|\n |_|  |\n");
        break;
      case 'y':
        printf("  _   _ \n | | | |\n | |_| |\n  \\__, |\n  |___/ \n");
        break;
      case 'z':
        printf(" ____ \n|___ /\n  |_ \\\n|___/\n");  
        break;
      case ' ':
        printf("\n");
        break;
      default:
        printf("Invalid character entered!\n");
        break;
    }
  }
  return 0;
}