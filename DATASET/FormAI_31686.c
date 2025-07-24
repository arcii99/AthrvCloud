//FormAI DATASET v1.0 Category: Game ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
  int user_choice, computer_choice, result;
  char options[3][20] = {"rock", "paper", "scissors"};  
  srand(time(0));
  printf("\n\nWelcome to Rock, Paper, Scissors game!\n\n");
  printf("1. Rock\n2. Paper\n3. Scissors\n\nPlease enter your choice: ");
  scanf("%d", &user_choice);
  if(user_choice < 1 || user_choice > 3){
    printf("\nInvalid input! Please enter 1, 2 or 3.\n");
    return 0;
  }
  computer_choice = rand() % 3 + 1;
  printf("\nYour choice: %s | Computer's choice: %s\n\n", options[user_choice-1], options[computer_choice-1]);
  if(user_choice == computer_choice){
    printf("Tie! Try again.\n");
    return 0;
  }
  if(user_choice == 1 && computer_choice == 3 || user_choice == 2 && computer_choice == 1 || user_choice == 3 && computer_choice == 2){
    result = 1;
  }else{
    result = -1;
  }
  if(result == 1){
    printf("Congratulations! You won!\n");
  }else{
    printf("Oops! You lost!\n");
  }
  return 0;
}