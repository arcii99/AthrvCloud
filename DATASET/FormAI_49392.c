//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <string.h>

int main(void) {
  printf("Hark ye, citizen of this realm! I am a humble word frequency counter, ready to tally thy chosen words.\n");
  
  char sentence[1000];
  char chosen_word[20];
  int count = 0;
  
  printf("What is thy message, good sir? ");
  fgets(sentence, 1000, stdin);
  
  printf("What word dost thou wish to tally? ");
  scanf("%s", chosen_word);
  
  int len_sent = strlen(sentence);
  int len_word = strlen(chosen_word);
  int i, j;
  
  for(i=0; i<len_sent; i++){
    if(sentence[i] == chosen_word[0]){
      int flag = 1;
      for(j=1; j<len_word; j++){
        if(sentence[i+j] != chosen_word[j]){
          flag = 0;
          break;
        }
      }
      if(flag){
        count++;
      }
    }
  }
  
  printf("The count of thy chosen word \"%s\" is %d.", chosen_word, count);
  return 0;
}