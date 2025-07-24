//FormAI DATASET v1.0 Category: Memory Game ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  printf("Welcome to the Memory Game! Let's test your memory skills!\n\n");
  printf("First, let's choose the range of numbers in the game.\n");
  printf("Enter the lower limit of the range: ");
  int lower; scanf("%d", &lower);
  printf("Enter the upper limit of the range: ");
  int upper; scanf("%d", &upper);
  int range = upper - lower + 1;
  int *numbers = (int*) calloc(range, sizeof(int));
  if(numbers==NULL) {
    printf("Sorry, but I forgot to allocate some memory!\n");
    return 0;
  } //Just kidding, I am always prepared!
  printf("Great! Now, let's create a sequence of numbers in the range of %d to %d.\n\n", lower, upper);
  srand(time(NULL)); int index = 0;
  while(index < range){
    int num = rand() % range + lower;
    int i = 0; int temp = 1;
    while(i < index){
      if(num==numbers[i]) temp = 0;
      i++;
    }
    if(temp) numbers[index++] = num;
  }
  printf("Here is the sequence! Memorize it carefully!\n\n");
  for(int i=0; i<range; i++) printf("%d ", numbers[i]);
  printf("\n\nPress any key to continue...\n");
  getchar(); getchar();
  system("clear");
  printf("Okay, now it's time to test your memory!\n\n");
  for(int i=0; i<range; i++) {
    printf("What was the %dth number in the sequence? ", i+1);
    int guess; scanf("%d", &guess);
    if(guess != numbers[i]) {
      printf("Oops! That's not correct. You lost the game!\n");
      return 0;
    }
    printf("Good job! You remembered the correct number!\n\n");
  }
  printf("Congratulations! You won the game! You have an amazing memory!\n");
  free(numbers);
  return 0;
}