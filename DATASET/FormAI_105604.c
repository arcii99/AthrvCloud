//FormAI DATASET v1.0 Category: Spam Detection System ; Style: scientific
#include <stdio.h>
#include <string.h>
#define MAX_MSG_LEN 1000
#define SPAM_THRESHOLD 0.8

int main(){
  char msg[MAX_MSG_LEN];
  printf("Enter the message: ");
  fgets(msg,MAX_MSG_LEN,stdin);

  int i, num_words=0, spam_words=0;
  char *word;
  word = strtok(msg," ,.!?\n");
  while(word!=NULL){
    for(i=0;i<strlen(word);i++){
      if(word[i]>='A' && word[i]<='Z'){
        word[i] = word[i]+32; 
      }
    }
    if(strcmp(word,"buy")==0||strcmp(word,"discount")==0|| strcmp(word,"cheap")==0||strcmp(word,"offer")==0){
      spam_words++;
    }
    num_words++;
    word = strtok(NULL," ,.!?\n");
  }

  if(spam_words/(float)num_words >= SPAM_THRESHOLD){
    printf("SPAM DETECTED!\n");
  }
  else{
    printf("Clean message\n");
  }
  
  return 0;
}