//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 1000 // maximum length of a message
#define MAX_SPAM_WORDS 10 // maximum number of spam words that can be detected
#define THRESHOLD 3 // threshold for spam detection; number of spam words in a message to classify it as spam

// function to check if a given word is present in the message
int check_word(char message [], char word []){
  char *ptr = strstr(message, word);
  if(ptr != NULL){
    return 1;
  }else{
    return 0;
  }
}

// function to count number of spam words in the message
int count_spam_words(char message [], char spam_words [][MAX_MSG_LEN], int num_spam_words){
  int count = 0;
  for(int i=0; i<num_spam_words; i++){
    count += check_word(message, spam_words[i]);
  }
  return count;
}

int main(){
  // array of spam words to be detected
  char spam_words [MAX_SPAM_WORDS][MAX_MSG_LEN] = {"free", "offer", "guaranteed", "prize", "money", "limited time offer", "buy now", "click here", "discount", "act now"};

  // prompt user to enter a message
  char message[MAX_MSG_LEN];
  printf("Enter a message: ");
  fgets(message, MAX_MSG_LEN, stdin);
  message[strcspn(message, "\n")] = 0;

  // count number of spam words in the message
  int num_spam_words = count_spam_words(message, spam_words, MAX_SPAM_WORDS);

  // classify message as spam or not spam based on the threshold value
  if(num_spam_words >= THRESHOLD){
    printf("SPAM message detected!\n");
  }else{
    printf("Not a spam message.\n");
  }

  return 0;
}