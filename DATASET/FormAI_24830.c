//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include <stdio.h>
#include <string.h>

int main(){

  char input[100];
  printf("Enter a sentence in C Cat language: ");
  fgets(input, 100, stdin);

  const char* c_cat_words[25] = {"meow", "purr", "hiss", "scratch", "tail", "whiskers", "paw", "feline", "kitten", "claws", "fish", "bird", "milk", "nap", "yarn", "mouse", "litter", "scratchpost", "sardine", "tuna", "canopener", "chase", "play", "sleep", "purrfect"};

  const char* english_words[25] = {"hello", "happy", "angry", "scrape", "back", "facehairs", "foot", "cat", "baby", "fingers", "food", "animal", "drink", "rest", "knitting", "toy", "garbage", "scratchingpost", "sardines", "tuna", "openingcan", "follow", "fun", "nap", "perfect"};

  char output[100];

  int i, j;
  char* tok = strtok(input, " ");
  while(tok != NULL){
    for(i = 0; i<25; i++){
      if(strcmp(c_cat_words[i], tok) == 0){
        strcat(output, english_words[i]);
        strcat(output, " ");
        break;
      }
    }
    if(i == 25){
      strcat(output, tok);
      strcat(output, " ");
    }
    tok = strtok(NULL, " ");
  }

  printf("\nThe English version is: %s\n", output);

  return 0;
}