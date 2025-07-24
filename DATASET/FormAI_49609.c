//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int answer;
  char name[20];
  
  printf("Welcome to the Mind-Bending Automated Fortune Teller!\n");
  printf("Please enter your name: \n");
  scanf("%s",name);
  
  printf("\n%s, I'm here to predict your future...\n\n",name);
  printf("Just think of a question that you want answered...\n");
  printf("Once you have it in your mind, please press Enter.\n");
  
  getchar();
  
  printf("The answer to your question is...\n");
  
  srand(time(0));
  answer = rand() % 10;

  switch(answer){
    case 0:
      printf("Definitely, without a doubt\n");
      break;
    case 1:
      printf("As I see it, yes\n");
      break;
    case 2:
      printf("Most likely\n");
      break;
    case 3:
      printf("Outlook good\n");
      break;
    case 4:
      printf("Signs point to yes\n");
      break;
    case 5:
      printf("Reply hazy, try again later\n");
      break;
    case 6:
      printf("Better not tell you now\n");
      break;
    case 7:
      printf("Concentrate and ask again\n");
      break;
    case 8:
      printf("Cannot predict now\n");
      break;
    case 9:
      printf("Don't count on it\n");
      break;
    default:
      printf("Hmmm... I seem to be experiencing some technical difficulties...\n");
  }
  
  printf("\nThank you for using the Mind-Bending Automated Fortune Teller!\n");
  
  return 0;
}