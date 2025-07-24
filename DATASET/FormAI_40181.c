//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surprised
#include <stdio.h>
#include <string.h>

int main(void) {
  char alien_language[] = "xzzt lpoo efgt klop trre mmkk llop uuyo iuuu";
  char *alien_words[10] = {"xzzt", "lpoo", "efgt", "klop", "trre", "mmkk", "llop", "uuyo", "iuuu"};
  char english[100] = "";

  printf("Enter text in Alien Language: \n");
  fgets(alien_language, sizeof(alien_language), stdin);

  char *word = strtok(alien_language, " ");
  while (word != NULL) {
    for (int i = 0; i < 9; i++) {
      if (strcmp(alien_words[i], word) == 0) {
        strcat(english, " ");
        switch(i) {
          case 0:
            strcat(english, "hello");
            break;
          case 1:
            strcat(english, "world");
            break;
          case 2:
            strcat(english, "good");
            break;
          case 3:
            strcat(english, "bye");
            break;
          case 4:
            strcat(english, "love");
            break;
          case 5:
            strcat(english, "thanks");
            break;
          case 6:
            strcat(english, "sorry");
            break;
          case 7:
            strcat(english, "yes");
            break;
          case 8:
            strcat(english, "no");
            break;
        }
        break;
      }
    }
    word = strtok(NULL, " ");
  }
  
  printf("Text in English: %s", english);
  return 0;
}