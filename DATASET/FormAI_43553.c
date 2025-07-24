//FormAI DATASET v1.0 Category: Spam Detection System ; Style: brave
#include<stdio.h>
#include<string.h>

#define MAX_MESSAGES 100
#define MAX_MESSAGE_LENGTH 200

int main(){
  char messages[MAX_MESSAGES][MAX_MESSAGE_LENGTH];
  int spam[MAX_MESSAGES];
  int n;

  printf("Enter number of messages: ");
  scanf("%d",&n);

  //reading messages and initializing spam to 0
  for(int i=0;i<n;i++){
    printf("Enter message %d: ",i+1);
    scanf("%s",messages[i]);
    spam[i] = 0;
  }

  //detecting spam based on keywords 'buy', 'sale', 'discount'
  for(int i=0;i<n;i++){
    if(strstr(messages[i],"buy") || strstr(messages[i],"sale") || strstr(messages[i],"discount")){
      spam[i] = 1;
    }
  }

  //printing spam message indices
  printf("Spam messages: ");
  for(int i=0;i<n;i++){
    if(spam[i]){
      printf("%d ",i+1);
    }
  }
  
  return 0;
}