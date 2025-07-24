//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Translation Translation;

struct Translation {
  char alien_char;
  char *translated_char;
};

int main() {
  char input[50];
  printf("Enter the alien language: ");
  fgets(input, 50, stdin);
  Translation translations[6];
  translations[0].alien_char = 'A';
  translations[0].translated_char = "10";
  translations[1].alien_char = 'B';
  translations[1].translated_char = "11";
  translations[2].alien_char = 'C';
  translations[2].translated_char = "12";
  translations[3].alien_char = 'D';
  translations[3].translated_char = "13";
  translations[4].alien_char = 'E';
  translations[4].translated_char = "14";
  translations[5].alien_char = 'F';
  translations[5].translated_char = "15";
  int i;
  for(i = 0; i < strlen(input); i++) {
    int j;
    for(j = 0; j < 6; j++) {
      if(input[i] == translations[j].alien_char) {
        printf("%s ", translations[j].translated_char);
        break;
      }
    }
    if(j == 6) {
      printf("Invalid character: %c ", input[i]);
    }
  }
  printf("\n");
  return 0;
}