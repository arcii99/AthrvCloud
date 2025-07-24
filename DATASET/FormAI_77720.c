//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Define the periodic table
  char periodic_table[118][3] = {
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
    "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
    "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
    "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
    "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
    "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
    "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
    "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
  };

  // Define the element symbols to be used in the quiz
  char selected_elements[10][3] = {
    "Au", "Fe", "Hg", "Ne", "O", "Pb", "Se", "Si", "U", "Zn"
  };

  // Initialize the random number generator
  srand(time(0));

  // Print a welcome message
  printf("Welcome to the periodic table quiz!\n");
  printf("Can you identify the element symbol for each of the following elements?\n");

  // Shuffle the array of selected elements
  for (int i = 0; i < 10; i++) {
    // Generate a random index between i and 9
    int j = i + rand() % (10 - i);

    // Swap element i with element j
    char temp[3];
    strcpy(temp, selected_elements[i]);
    strcpy(selected_elements[i], selected_elements[j]);
    strcpy(selected_elements[j], temp);
  }

  // Initialize the score counter
  int score = 0;

  // Ask the user for the symbol of each element
  for (int i = 0; i < 10; i++) {
    char symbol[3];
    printf("\nWhat is the symbol for %s? ", selected_elements[i]);
    scanf("%s", symbol);

    // Check if the user entered the correct symbol
    if (strcmp(symbol, selected_elements[i]) == 0) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect! The correct symbol is %s.\n", selected_elements[i]);
    }
  }

  // Print the final score
  printf("\nYou scored %d out of 10.\n", score);

  // Print a message based on the score
  if (score == 10) {
    printf("Wow, you are a periodic table master!\n");
  } else if (score >= 7) {
    printf("Great job!\n");
  } else if(score >=4){
    printf("Not bad, but there is room for improvement.\n");
  }else{
    printf("Looks like you need to study the periodic table some more!\n");
  }

  return 0;
}