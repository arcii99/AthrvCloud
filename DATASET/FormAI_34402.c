//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

int main() {
  // Define the language alphabet
  char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                     'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                     'u', 'v', 'w', 'x', 'y', 'z', ' '};
                     
  // Define the language vocabulary
  char vocabulary[][20] = {"zod", "fiq", "buv", "nop", "azd",
                           "cho", "lag", "mik", "rup", "tic",
                           "sin", "wac", "daf", "nem", "siv",
                           "pub", "jat", "kic", "hol", "ren",
                           "vok", "bud", "fax", "wip", "zav",
                           "gol", " "};
                           
  // Get user input
  char input[100];
  printf("Enter a sentence in the C Alien language: ");
  gets(input);
  
  // Convert the input to lower case
  int len = strlen(input);
  for(int i=0; i<len; i++) {
    input[i] = tolower(input[i]);
  }
  
  // Translate the input
  char output[100] = "";
  for(int i=0; i<len; i++) {
    for(int j=0; j<26; j++) {
      if(input[i] == alphabet[j]) {
        strcat(output, vocabulary[j]);
      }
    }
  }
  
  // Print the output
  printf("Translated sentence: %s", output);
  
  return 0;
}