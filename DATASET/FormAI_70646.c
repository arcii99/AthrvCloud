//FormAI DATASET v1.0 Category: Scientific ; Style: enthusiastic
// Welcome to an exciting world of scientific programming in C!
// In this program, we will simulate the famous Monty Hall problem, 
// which is a probability puzzle named after the TV game show host, Monty Hall.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // Let's create some variables
  int num_doors = 3, num_trials = 1000000, wins_no_switch = 0, wins_with_switch = 0;
  
  srand(time(0)); // seed the random number generator with current time
  
  printf("Welcome to the Monty Hall problem simulation!\n\n");
  
  // First, let's simulate the case when the player always sticks with the initial choice
  printf("Scenario 1: Player doesn't switch doors after host reveals a goat behind one door.\n");
  
  for (int i = 0; i < num_trials; i++)
  {
    int door_with_prize = rand() % num_doors; // select a random door with the prize
    
    int player_choice = rand() % num_doors; // player makes an initial random choice
    
    int host_reveal;
    
    do {
      host_reveal = rand() % num_doors; // host randomly chooses a non-winning door to reveal
    } while (host_reveal == door_with_prize || host_reveal == player_choice);
    
    if (player_choice == door_with_prize) {
      wins_no_switch++;
    }
  }
  
  double win_pct_no_switch = (double) wins_no_switch / num_trials * 100;
  
  printf("Wins without switching: %d out of %d trials (%.2f%%)\n", wins_no_switch, num_trials, win_pct_no_switch);
  
  // Now, let's simulate the case when the player always switches to the other door after host reveals a goat
  printf("\nScenario 2: Player switches doors after host reveals a goat behind one door.\n");
  
  for (int i = 0; i < num_trials; i++)
  {
    int door_with_prize = rand() % num_doors; // select a random door with the prize
    
    int player_choice = rand() % num_doors; // player makes an initial random choice
    
    int host_reveal;
    
    do {
      host_reveal = rand() % num_doors; // host randomly chooses a non-winning door to reveal
    } while (host_reveal == door_with_prize || host_reveal == player_choice);
    
    int new_choice;
    
    do {
      new_choice = rand() % num_doors; // player switches to a random non-revealed door
    } while (new_choice == player_choice || new_choice == host_reveal);
    
    if (new_choice == door_with_prize) {
      wins_with_switch++;
    }
  }
  
  double win_pct_with_switch = (double) wins_with_switch / num_trials * 100;
  
  printf("Wins with switching: %d out of %d trials (%.2f%%)\n", wins_with_switch, num_trials, win_pct_with_switch);
  
  printf("\nConclusion: As we have shown, the player is more likely to win if they switch doors!\n");
  
  return 0;
}