//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char message[1000];
  int choice, length, i, j;

  printf("Welcome to the Text to Morse Code Converter!\n\n");
  printf("Enter your message:\n");
  fgets(message, 1000, stdin);
  length = strlen(message);

  printf("\nChoose an encoding option:\n");
  printf("1. Standard Morse Code\n");
  printf("2. Custom Morse Code\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      for (i = 0; i < length; i++) {
        switch (message[i]) {
          case 'a':
          case 'A':
            printf(".- ");
            break;
          case 'b':
          case 'B':
            printf("-... ");
            break;
          case 'c':
          case 'C':
            printf("-.-. ");
            break;
          case 'd':
          case 'D':
            printf("-.. ");
            break;
          case 'e':
          case 'E':
            printf(". ");
            break;
          case 'f':
          case 'F':
            printf("..-. ");
            break;
          case 'g':
          case 'G':
            printf("--. ");
            break;
          case 'h':
          case 'H':
            printf(".... ");
            break;
          case 'i':
          case 'I':
            printf(".. ");
            break;
          case 'j':
          case 'J':
            printf(".--- ");
            break;
          case 'k':
          case 'K':
            printf("-.- ");
            break;
          case 'l':
          case 'L':
            printf(".-.. ");
            break;
          case 'm':
          case 'M':
            printf("-- ");
            break;
          case 'n':
          case 'N':
            printf("-. ");
            break;
          case 'o':
          case 'O':
            printf("--- ");
            break;
          case 'p':
          case 'P':
            printf(".--. ");
            break;
          case 'q':
          case 'Q':
            printf("--.- ");
            break;
          case 'r':
          case 'R':
            printf(".-. ");
            break;
          case 's':
          case 'S':
            printf("... ");
            break;
          case 't':
          case 'T':
            printf("- ");
            break;
          case 'u':
          case 'U':
            printf("..- ");
            break;
          case 'v':
          case 'V':
            printf("...- ");
            break;
          case 'w':
          case 'W':
            printf(".-- ");
            break;
          case 'x':
          case 'X':
            printf("-..- ");
            break;
          case 'y':
          case 'Y':
            printf("-.-- ");
            break;
          case 'z':
          case 'Z':
            printf("--.. ");
            break;
          case ' ':
            printf("   ");
            break;
          case '\n':
            printf("\n");
            break;
          default:
            printf("%c", message[i]);
            break;
        }
      }
      break;
    case 2:
      printf("\nEnter your custom encoding:\n");
      char mapping[255];
      char temp[10];
      int position = 0;

      while (fgets(temp, 10, stdin) != NULL) {
        if (temp[0] == '\n') {
          break;
        }

        if (temp[0] == ' ') {
          mapping[32] = ' ';
          position++;
        } else {
          mapping[(int) temp[0]] = '\0';
          strncpy(&mapping[(int) temp[0]], &temp[2], strlen(temp) - 3);
          position += strlen(&mapping[(int) temp[0]]);
        }
      }

      for (i = 0; i < length; i++) {
        if (message[i] == '\n') {
          printf("\n");
          continue;
        }

        printf("%s ", mapping[(int) message[i]]);
      }
      break;
    default:
      printf("Invalid choice.\n");
      break;
  }

  return 0;
}