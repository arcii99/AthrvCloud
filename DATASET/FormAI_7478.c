//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize the variables
  char elements[118][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
  int atomic_numbers[118] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118};
  int score = 0;
  int random_index;
  char user_input[3];
  srand(time(NULL));

  printf("Welcome to the Periodic Table Quiz!\n\n");
  printf("You'll be given a random element and you'll have to guess its atomic number.\n");
  printf("Enter 'quit' to exit the game.\n\n");

  // start the game loop
  while(1) {
    // generate a random index
    random_index = rand() % 118;

    // ask the user for input
    printf("What is the atomic number of %s? ", elements[random_index]);
    scanf("%s", user_input);

    // check if user wants to quit
    if(user_input[0] == 'q' && user_input[1] == 'u' && user_input[2] == 'i' && user_input[3] == 't') {
      printf("\nThanks for playing! Your final score is %d.\n", score);
      return 0;
    }

    // convert user input to integer
    int user_answer = atoi(user_input);

    // check if user input is correct
    if(user_answer == atomic_numbers[random_index]) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect. The atomic number of %s is %d.\n", elements[random_index], atomic_numbers[random_index]);
      score--;
    }
  }

  return 0;
}