//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <string.h>

int main() {
  char alien_language[30][10] = {
      "a", "na", "ti", "glo", "prom",
      "flum", "kri", "danto", "mela", "tina",
      "zorp", "loki", "enu", "quar", "tik",
      "vorg", "spor", "plon", "riva", "nort",
      "yurp", "wex", "jik", "axi", "spim",
      "plox", "zico", "mern", "hix", "glorf"
  };
  char english_language[30][10] = {
      "b", "c", "d", "f", "g",
      "h", "j", "k", "l", "m",
      "n", "p", "q", "r", "s",
      "t", "v", "w", "x", "y",
      "z", "ae", "oi", "ua", "ie",
      "ou", "ch", "th", "sh", "ng"
  };
  char input[1000], output[1000] = "";
  int i, j, k, index, found;
  
  printf("Enter text in alien language: ");
  fgets(input, sizeof(input), stdin);
  
  for(i=0; i<strlen(input); i++) {
    if(input[i] == ' ') {
      strcat(output, " ");
    }
    else {
      found = 0;
      index = -1;
      for(j=0; j<30; j++) {
        if(strncmp(&input[i], alien_language[j], strlen(alien_language[j])) == 0) {
          found = 1;
          index = j;
          break;
        }
      }
      if(found == 1) {
        strcat(output, english_language[index]);
        i += strlen(alien_language[index])-1;
      }
      else {
        strncat(output, &input[i], 1);
      }
    }
  }
  
  printf("The translated text in English language is: %s\n", output);
  
  return 0;
}