//FormAI DATASET v1.0 Category: Spam Detection System ; Style: curious
#include<stdio.h>
#include<string.h>

// declaring function to check for the spam
int isSpam(char message[]);

int main(){
  char message[100];
  printf("Please enter your message: ");
  fgets(message, 100, stdin);

  if(isSpam(message)){
    printf("Alert! Your message contains spam content.\n");
  }else{
    printf("Good news! Your message is free of spam.\n");
  }

  return 0;
}

int isSpam(char message[]){
  char spamWords[][20] = {"offer", "free", "money", "discount", "click here"};
  int spamCount = 0;

  for(int i = 0; i < sizeof(spamWords) / sizeof(spamWords[0]); i++){
    if(strstr(message, spamWords[i])){
      spamCount++;
    }
  }

  if(spamCount > 2){ // if there are more than 2 spam words in the message
    return 1;
  }else{
    return 0;
  }
}