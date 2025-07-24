//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char alien[] = {'!', ',', '?', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '<', '>', '/', '\\', '|', '[',
                  ']', '{', '}', ':', ';', '.', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                  'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  char english[] = {'!', ',', '?', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '<', '>', '/', '\\', '|', '[',
                    ']', '{', '}', ':', ';', '.', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  char input[1000];
  int length = 0;

  printf("Enter an alien word or phrase in C Alien Language: ");
  gets(input);
  length = strlen(input);

  printf("\nParsed to English: ");
  for(int i = 0; i < length; i++) {
    for(int j = 0; j < 47; j++) {
      if(input[i] == alien[j]) {
        printf("%c", english[j]);
      }
    }
  }

  return 0;
}