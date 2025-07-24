//FormAI DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main(void) {
  char sentence[100];
  char new_sentence[100];
  char* token;
  
  printf("Welcome to the Sentence Reverser Program!\n");
  printf("Please enter a sentence to be reversed:\n");
  
  // read input sentence
  fgets(sentence, 100, stdin);
  
  // remove newline character from the end
  sentence[strcspn(sentence, "\n")] = 0;
  
  // reverse sentence word by word
  token = strtok(sentence, " ");
  while (token != NULL) {
    char temp[100];
    strcpy(temp, token);
    new_sentence[0] = '\0';
    strcat(new_sentence, temp);
    strcat(new_sentence, " ");
    strcat(new_sentence, new_sentence);
    token = strtok(NULL, " ");
  }
  
  // remove extra space at the end
  new_sentence[strlen(new_sentence)-1] = '\0';
  
  printf("The reversed sentence is:\n%s\n", new_sentence);
  
  return 0;
}