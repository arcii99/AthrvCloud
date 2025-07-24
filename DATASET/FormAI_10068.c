//FormAI DATASET v1.0 Category: Robot movement control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 20
#define MAX_COL 20
#define MAX_ENERGY 1000
#define MOVE_COST 10
#define ATTACK_COST 50

typedef struct {
  int row;
  int col;
  int energy;
  int attack;
} robot_t;

void print_map(char map[][MAX_COL+1], int row, int col){
  int i, j;

  printf("\n");
  for(i=0; i<row; i++){
    for(j=0; j<col; j++){
      printf("%c ", map[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void print_stats(robot_t *bot) {
  printf("Energy: %d\n", bot->energy);
  printf("Attack: %d\n", bot->attack);
  printf("\n");
}

void move_up(char map[][MAX_COL+1], robot_t *bot) {
  if(bot->row > 0 && bot->energy >= MOVE_COST){
    bot->row--;
    bot->energy -= MOVE_COST;
    printf("Moved up\n");
  }
  else{
    printf("Cannot move up\n");
  }
}

void move_down(char map[][MAX_COL+1], robot_t *bot, int row) {
  if(bot->row < row-1 && bot->energy >= MOVE_COST){
    bot->row++;
    bot->energy -= MOVE_COST;
    printf("Moved down\n");
  }
  else{
    printf("Cannot move down\n");
  }
}

void move_left(char map[][MAX_COL+1], robot_t *bot) {
  if(bot->col > 0 && bot->energy >= MOVE_COST){
    bot->col--;
    bot->energy -= MOVE_COST;
    printf("Moved left\n");
  }
  else{
    printf("Cannot move left\n");
  }
}

void move_right(char map[][MAX_COL+1], robot_t *bot, int col) {
  if(bot->col < col-1 && bot->energy >= MOVE_COST){
    bot->col++;
    bot->energy -= MOVE_COST;
    printf("Moved right\n");
  }
  else{
    printf("Cannot move right\n");
  }
}

void attack(char map[][MAX_COL+1], robot_t *bot) {
  if(bot->energy >= ATTACK_COST){
    switch(map[bot->row][bot->col]){
      case 'M':
        map[bot->row][bot->col] = '_';
        bot->attack += 10;
        printf("Attacked a mutant\n");
        break;
      case 'H':
        map[bot->row][bot->col] = '_';
        bot->energy += 50;
        printf("Attacked a human and gained 50 energy\n");
        break;
      case 'R':
        map[bot->row][bot->col] = '_';
        bot->energy += 100;
        printf("Attacked a robot and gained 100 energy\n");
        break;
      default:
        printf("No target to attack\n");
        break;
    }
    bot->energy -= ATTACK_COST;
  }
  else{
    printf("Not enough energy to attack\n");
  }
}

int main() {
  char map[MAX_ROW][MAX_COL+1] = {
    "MMMMMMMMMMMMMMMMMMMM",
    "M__________HMMMMMMM",
    "M___________MMMMMMH",
    "MMMMMMM_____M_____M",
    "M______M_____M_____M",
    "M______M_____M_____M",
    "M______M_____M_____M",
    "M____________RMMMMM",
    "MMMMMMM_____MMMMMMM",
    "MMMMMMM_____MMMMMMM",
    "M_____M_____M_____M",
    "M_____M_____M_____M",
    "M_____M_____M_____M",
    "M___________RMMMMM.",
    "M_____MMMMMMMMMMMMM",
    "M______________RMMM",
    "M_____MMMMMMMMMMMMM",
    "M_____H____________",
    "MMMMMMMMMMMMMMMMMMM",
    ".__________________"
  };
  int row = MAX_ROW, col = MAX_COL, i, j;
  robot_t bot = {1, 2, MAX_ENERGY/2, 0};
  char action;

  printf("Welcome to the post-apocalyptic world!\n");
  
  while(bot.energy > 0){
    print_stats(&bot);
    print_map(map, row, col);
    printf("Action (U/D/L/R/A/Q): ");
    scanf("%c", &action);
    fflush(stdin);

    switch(action){
      case 'U':
        move_up(map, &bot);
        break;
      case 'D':
        move_down(map, &bot, row);
        break;
      case 'L':
        move_left(map, &bot);
        break;
      case 'R':
        move_right(map, &bot, col);
        break;
      case 'A':
        attack(map, &bot);
        break;
      case 'Q':
        printf("Bye!\n");
        exit(0);
      default:
        printf("Invalid action\n");
        break;
    }

    for(i=0; i<row; i++){
      for(j=0; j<col; j++){
        if(map[i][j] == 'M'){
          if(abs(i-bot.row) <= 2 && abs(j-bot.col) <=2){
            printf("Mutant attacked you! ");
            bot.energy -= 50;
            if(bot.energy <= 0){
              printf("You died!\n");
              exit(0);
            }
            else{
              printf("Energy: %d\n", bot.energy);
            }
          }
        }
      }
    }

    bot.energy += 10;
    if(bot.energy > MAX_ENERGY){
      bot.energy = MAX_ENERGY;
    }
  }

  printf("You run out of energy and died!\n");
  
  return 0;
}