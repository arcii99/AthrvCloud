//FormAI DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <string.h>

//function to check for spam
int checkForSpam(char *input) {
  char spamWords[][20] = { "buy", "sale", "discount", "win", "offer" }; //list of spam words
  int spamCount = 0; //counter for the number of spam words found

  //split the input into individual words
  char *token = strtok(input, " ");
  
  while(token != NULL) {
    //compare each word to the spam words list
    for(int i=0; i<5; i++) {
      if(strcmp(token, spamWords[i]) == 0) {
        spamCount++;
      }
    }
    token = strtok(NULL, " ");
  }

  //if more than two spam words are found, it is considered spam
  if(spamCount > 2) {
    return 1; //spam detected
  }
  else {
    return 0; //not spam
  }
}

int main() {
  char input[1000];

  printf("Enter text: ");
  fgets(input, 1000, stdin);

  int isSpam = checkForSpam(input);

  if(isSpam) {
    printf("SPAM DETECTED");
  }
  else {
    printf("NOT SPAM");
  }

  return 0;
}