//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_LENGTH 50

int main() {
  char spam_list[5][MAX_SPAM_LENGTH] = {"FREE", "BUY NOW", "ACT NOW", "LIMITED TIME", "CLICK HERE"};
  char input_message[MAX_SPAM_LENGTH];
  int is_spam = 0;

  printf("Enter your message: ");
  fgets(input_message, MAX_SPAM_LENGTH, stdin); // take input from user

  for(int i=0; i < strlen(input_message); i++) {
    char word[MAX_SPAM_LENGTH];
    int j=0;
    // extract each word from the input message
    while(input_message[i]!=' ' && i < strlen(input_message)) {
      word[j] = input_message[i];
      j++;
      i++;
    }
    word[j] = '\0';

    // check if the extracted word is in the spam list
    for(int k=0; k < 5; k++) {
      if(strcmp(word, spam_list[k]) == 0) {
        is_spam = 1;
        break;
      }
    }
    if(is_spam) break; // no need to check further if it's already identified as spam
  }

  // print the result
  if(is_spam) {
    printf("SPAM DETECTED!");
  } else {
    printf("NOT SPAM");
  }
  return 0;
}