//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  const char *fortune[] = {
    "You will find happiness within yourself.",
    "You will meet someone special today.",
    "You will have great success in your career.",
    "Good things come to those who wait. Keep waiting.",
    "Beware of the color purple.",
    "The best things in life are free, but the second best things are expensive.",
    "You will travel to a foreign land.",
    "Do not eat the yellow snow.",
    "You will make a new friend today.",
    "Your lucky number is 42.",
    "You will find the answer you are looking for.",
    "All good things come to those who work hard.",
    "You are destined to be great."
  };

  srand(time(NULL));
  int index = rand() % (sizeof(fortune) / sizeof(fortune[0]));

  printf("\n\n\n");
  printf("=========== C Automated Fortune Teller ===========\n");
  printf("||                                             ||\n");
  printf("||           **  **            **              ||\n");
  printf("||         **      **           **             ||\n");
  printf("||        **        **           **            ||\n");
  printf("||        **        **           **            ||\n");
  printf("||        **  **  **            **            ||\n");
  printf("||        **      **            **            ||\n");
  printf("||        **        **          **             ||\n");
  printf("||         **       **         **              ||\n");
  printf("||           **  **           **               ||\n");
  printf("||                                             ||\n");
  printf("================================================\n");
  printf("\n\n\n");
  printf(">> Your fortune for today:\n\n%s\n", fortune[index]);

  return 0;
}