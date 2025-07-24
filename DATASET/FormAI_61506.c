//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

  printf("Welcome to the Automated Fortune Teller Program!\n\n");

  int i, num;
  char name[20];

  printf("What's your name? ");
  scanf("%[^\n]%*c", name);

  printf("\nHello, %s! This program will predict your future based on a number you provide.\n", name);

  printf("\nEnter a positive integer between 1 and 10: ");
  scanf("%d", &num);

  srand(time(NULL));
  int random_num = rand() % 10 + 1;

  printf("\nThe randomly generated number is %d.\n", random_num);

  if(num == random_num){
    printf("\nWow! You will have great success in the near future!\n");
  }
  else{
    printf("\nHmmm... it appears that your future may not be as bright as you hoped.\n");
    printf("But don't worry, it is not set in stone. You can always change your future by making positive changes in your present.\n");
  }

  printf("\nThank you %s for using our Automated Fortune Teller Program. Have a great day!\n", name);

  return 0;
}