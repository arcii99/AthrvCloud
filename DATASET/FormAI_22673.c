//FormAI DATASET v1.0 Category: HTML beautifier ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to Bob's HTML Code Beautifier! Hope you like rainbows and unicorns!\n");

  char *ugly_code = "<html><head><title>My Ugly Website</title></head><body><h1>Hello, World!</h1><p>Isn't this just a mess?</p></body></html>";
  printf("Here's some ugly code I found on the ground:\n%s\n", ugly_code);

  char *beauty_code = (char*) malloc(sizeof(char) * strlen(ugly_code));
  int indent_level = 0;
  printf("Let's beautify it!\n");

  for (int i = 0; i < strlen(ugly_code); i++) {
    if (ugly_code[i] == '<') {
      printf("\n");
      for (int j = 0; j < indent_level; j++) {
        printf(" ");
      }
      beauty_code[strlen(beauty_code)] = '\n';
      indent_level += 2;
    }
    beauty_code[strlen(beauty_code)] = ugly_code[i];

    if (ugly_code[i] == '>') {
      indent_level -= 2;
      for (int j = 0; j < indent_level; j++) {
        printf(" ");
      }
    }
    printf("%c", ugly_code[i]);
  }

  printf("\n\nVoila! Here's your new and improved code:\n%s\n", beauty_code);
  free(beauty_code);

  return 0;
}