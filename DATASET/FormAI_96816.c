//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: thriller
#include <stdio.h>

int main() {
  char input[100];
  printf("Enter your text: ");
  fgets(input, 100, stdin);

  char output[500];

  for (int i = 0; input[i] != '\0'; i++) {
    char c = input[i];
    if (c == 'A') {
      strcat(output, "  /\\  \n /  \\ \n/    \\\n/------\\\n");
    } else if (c == 'B') {
      strcat(output, "|------\\\n|------/\n|_____/ \n|------\\\n|______\\ \n");
    } else if (c == 'C') {
      strcat(output, "  /\\  \n /    \n/      \n \\     \n  \\__/ \n");
    } else if (c == 'D') {
      strcat(output, "|-----\\ \n|     | \n|     | \n|     | \n|_____/ \n");
    } else if (c == 'E') {
      strcat(output, "|------- \n|_____   \n|      \\ \n|_____  |\n|______/ \n");
    } else if (c == 'F') {
      strcat(output, "|------- \n|_____   \n|      \\ \n|      |\n|      | \n");
    } else if (c == 'G') {
      strcat(output, "  ____   \n /  __\\  \n|  /__|  \n|     \\  \n \\___/|__\n");
    } else if (c == 'H') {
      strcat(output, "|      |\n|------|\n|      |\n|      |\n|      |\n");
    } else if (c == 'I') {
      strcat(output, " ------\n|      |\n|      |\n|      |\n ------\n");
    } else if (c == 'J') {
      strcat(output, " _______\n         |\n         |\n         |\n\\___/ \\__|");
    } else if (c == 'K') {
      strcat(output, "|      / \n|-----/  \n|----<   \n|-----\\  \n|      \\ \n");
    } else if (c == 'L') {
      strcat(output, "|      |\n|      |\n|      |\n|      |\n ------\n");
    } else if (c == 'M') {
      strcat(output, "|\\    /|\n| \\  / |\n|  \\/  |\n|      |\n|      |\n");
    } else if (c == 'N') {
      strcat(output, "|\\    |\n| \\   |\n|  \\  |\n|   \\ |\n|    \\|\n");
    } else if (c == 'O') {
      strcat(output, "  ____  \n / __ \\ \n| |  | |\n| |  | |\n \\___/ / \n");
    } else if (c == 'P') {
      strcat(output, "|-----\\\n|      \\\n|       |\n|       |\n|       |\n");
    } else if (c == 'Q') {
      strcat(output, "  ____  \n / __ \\ \n| |  | |\n| |__| |\n \\___\\_\_\n");
    } else if (c == 'R') {
      strcat(output, "|-----\\\n|      \\\n|       |\n|    \\  |\n|     \\ |\n");
    } else if (c == 'S') {
      strcat(output, "  _____\n / ____|\n| |     \n \\_____\\\n");
    } else if (c == 'T') {
      strcat(output, "-------\n   |    \n   |    \n   |    \n   |    \n");
    } else if (c == 'U') {
      strcat(output, "|      |\n|      |\n|      |\n|      |\n \\____/\n");
    } else if (c == 'V') {
      strcat(output, "\\       /\n \\     / \n  \\   /  \n   \\ /   \n    V    \n");
    } else if (c == 'W') {
      strcat(output, "|      |\n|      |\n|  /\\  |\n| /  \\ |\n|/    \\|\n");
    } else if (c == 'X') {
      strcat(output, "\\     /\n \\   / \n  \\ /  \n  / \\  \n /   \\ \n");
    } else if (c == 'Y') {
      strcat(output, "\\     /\n \\   / \n  \\ /  \n   |   \n   |   \n");
    } else if (c == 'Z') {
      strcat(output, " ______\n|_____/ \n     /  \n   /    \n /______\n");
    } else {
      strcat(output, "     \n     \n  XX  \n     \n     \n");
    }
  }

  printf("%s", output);

  return 0;
}