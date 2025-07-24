//FormAI DATASET v1.0 Category: Table Game ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
  int number, guess, nguesses=1;
  srand(time(0));
  number = rand()%100 + 1;
  printf("\nWelcome to the Guess the Number game!\n");
  
  do{
    printf("\nGuess the Number between 1 to 100:");
    scanf("%d", &guess);

    if(guess > number){
      printf("\nOops! Lower your number.\n");
    }
    else if(guess < number){
      printf("\nHurry up! Increase your number.\n");
    }
    else{
      printf("\nCongratulations! You guessed the number in %d attempts.\n",nguesses);
    }
    nguesses++;
  }while(guess!=number);
  printf("\nThank you for playing!");
  return 0;
}