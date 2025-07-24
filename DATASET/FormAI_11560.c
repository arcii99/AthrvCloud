//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  
  int num1 = rand() % 10 + 1;
  int num2 = rand() % 10 + 1;
  int correct_answer = num1 + num2;
  int user_answer;

  printf("Welcome to Mathematical Adventure!\n");
  printf("You find yourself in a room with two doors.\n");
  printf("Door 1 leads to addition land, and Door 2 leads to subtraction land.\n");

  int choice;
  printf("Which door do you want to go through? (1 or 2):\n");
  scanf("%d", &choice);

  if(choice == 1){
    printf("You have entered addition land.\n");
    printf("Your goal is to correctly answer the following question:\n");
    printf("%d + %d = ?", num1, num2);
    scanf("%d", &user_answer);

    if(user_answer == correct_answer){
      printf("Congratulations! You have solved the addition puzzle!\n");
    } else {
      printf("Sorry, that answer is incorrect. You have failed this challenge.\n");
      printf("Game over.\n");
      return 0;
    }
    
    printf("Next, you find yourself at a crossroads.\n");
    printf("You can either take the left path to multiplication land or the right path to division land.\n");
    printf("Which path will you choose? (L or R):\n");

    char path_choice;
    scanf(" %c", &path_choice);

    switch(path_choice){
      case 'L':
        printf("You have entered multiplication land.\n");
        printf("Your goal is to correctly answer the following question:\n");
        int num3 = rand() % 10 + 1;
        int num4 = rand() % 10 + 1;
        int correct_answer2 = num3 * num4;
        printf("%d * %d = ?", num3, num4);
        scanf("%d", &user_answer);
        if(user_answer == correct_answer2){
          printf("Congratulations! You have solved the multiplication puzzle!\n");
        } else {
          printf("Sorry, that answer is incorrect. You have failed this challenge.\n");
          printf("Game over.\n");
          return 0;
        }
        printf("You have solved all math puzzles and have completed your adventure!\n");
        break;
      case 'R':
        printf("You have entered division land.\n");
        printf("Your goal is to correctly answer the following question:\n");
        int num5 = rand() % 10 + 1;
        int num6 = rand() % 10 + 1;
        while(num5 % num6 != 0){
          num5 = rand() % 10 + 1;
          num6 = rand() % 10 + 1;
        }
        int correct_answer3 = num5 / num6;
        printf("%d / %d = ?", num5, num6);
        scanf("%d", &user_answer);
        if(user_answer == correct_answer3){
          printf("Congratulations! You have solved the division puzzle!\n");
        } else {
          printf("Sorry, that answer is incorrect. You have failed this challenge.\n");
          printf("Game over.\n");
          return 0;
        }
        printf("You have solved all math puzzles and have completed your adventure!\n");
        break;
      default:
        printf("Invalid input. Game over.\n");
        return 0;
    }
  } else if(choice == 2){
    printf("You have entered subtraction land.\n");
    printf("Your goal is to correctly answer the following question:\n");
    int num7 = rand() % 10 + 1;
    int num8 = rand() % 10 + 1;
    int correct_answer4 = num7 - num8;
    printf("%d - %d = ?", num7, num8);
    scanf("%d", &user_answer);

    if(user_answer == correct_answer4){
      printf("Congratulations! You have solved the subtraction puzzle!\n");
    } else {
      printf("Sorry, that answer is incorrect. You have failed this challenge.\n");
      printf("Game over.\n");
      return 0;
    }
    
    printf("Next, you find yourself at a crossroads.\n");
    printf("You can either take the left path to square root land or the right path to power land.\n");
    printf("Which path will you choose? (L or R):\n");

    char path_choice2;
    scanf(" %c", &path_choice2);

    switch(path_choice2){
      case 'L':
        printf("You have entered square root land.\n");
        printf("Your goal is to correctly answer the following question:\n");
        int num9 = rand() % 10 + 1;
        int correct_answer5 = sqrt(num9);
        printf("What is the square root of %d?\n", num9);
        scanf("%d", &user_answer);
        if(user_answer == correct_answer5){
          printf("Congratulations! You have solved the square root puzzle!\n");
        } else {
          printf("Sorry, that answer is incorrect. You have failed this challenge.\n");
          printf("Game over.\n");
          return 0;
        }
        printf("You have solved all math puzzles and have completed your adventure!\n");
        break;
      case 'R':
        printf("You have entered power land.\n");
        printf("Your goal is to correctly answer the following question:\n");
        int num10 = rand() % 10 + 1;
        int num11 = rand() % 3 + 2;
        int correct_answer6 = pow(num10, num11);
        printf("%d raised to the power of %d = ?", num10, num11);
        scanf("%d", &user_answer);
        if(user_answer == correct_answer6){
          printf("Congratulations! You have solved the power puzzle!\n");
        } else {
          printf("Sorry, that answer is incorrect. You have failed this challenge.\n");
          printf("Game over.\n");
          return 0;
        }
        printf("You have solved all math puzzles and have completed your adventure!\n");
        break;
      default:
        printf("Invalid input. Game over.\n");
        return 0;
    }
  } else {
    printf("Invalid input. You cannot proceed. Game over.\n");
    return 0;
  }

  return 0;
}