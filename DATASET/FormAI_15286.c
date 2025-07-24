//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {

  char cCatLang[] = "Meow, purr, hiss, scratch, meow!";
  char english[] = "Hello, how are you doing today?";

  printf("Cat Language: %s\n", cCatLang);
  printf("English: %s\n", english);

  // Translation from English to Cat Language
  for(int i = 0; i < strlen(english); i++) {
    switch (english[i]) {
      case 'a':
        printf("meow ");
        break;
      case 'e':
        printf("purr ");
        break;
      case 'i': 
        printf("hiss ");
        break;
      case 'o':
        printf("scratch ");
        break;
      case 'u':
        printf("meow ");
        break;
      case ' ':
        printf(" ");
        break;
      case ',':
        printf(",");
        break;
      default:
        printf("%c", english[i]);
    }
  }

  printf("\n");

  // Translation from Cat Language to English
  char word[10] = "";
  for(int i = 0; i < strlen(cCatLang); i++) {
    if(cCatLang[i] == ' ' || cCatLang[i] == '!') {
      if(strcmp(word, "meow") == 0) {
        printf("a");
      } else if(strcmp(word, "purr") == 0) {
        printf("e");
      } else if(strcmp(word, "hiss") == 0) {
        printf("i");
      } else if(strcmp(word, "scratch") == 0) {
        printf("o");
      } else {
        printf("%s", word);
      }
      memset(word, 0, sizeof(word));
      if(cCatLang[i] == ' ') {
        printf(" ");
      } else {
        printf("!");
      }
    } else {
      sprintf(word, "%s%c", word, cCatLang[i]);
    }
  }

  printf("\n");

  return 0;
}