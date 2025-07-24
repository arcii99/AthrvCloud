//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: complete
#include <stdio.h>

int main() {
  char correctAnswer[119] = "H He Li Be B C N O F Ne Na Mg Al Si P S Cl Ar K Ca Sc Ti V Cr Mn Fe Co Ni Cu Zn Ga Ge As Se Br Kr Rb Sr Y Zr Nb Mo Tc Ru Rh Pd Ag Cd In Sn Sb Te I Xe Cs Ba La Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu Hf Ta W Re Os Ir Pt Au Hg Tl Pb Bi Po At Rn Fr Ra Ac Th Pa U Np Pu Am Cm Bk Cf Es Fm Md No Lr Rf Db Sg Bh Hs Mt Ds Rg Cn Nh Fl Mc Lv Ts Og";
  char inputAnswer[119];
  int score = 0;

  printf("Welcome to the Periodic Table Quiz!\n");
  printf("Enter the element symbol for each element name listed.\n");
  printf("Type 'quit' at any time to exit the quiz.\n");
  printf("Get ready...\n\n");

  // split the correct answer string into individual element symbols
  char* token = strtok(correctAnswer, " ");
  char* elements[118];
  int count = 0;
  while (token != NULL) {
    elements[count++] = token;
    token = strtok(NULL, " ");
  }

  // ask for user input and check if it's correct
  for (int i = 0; i < count; i++) {
    printf("%d.) %s: ", i+1, elements[i]);
    scanf("%s", inputAnswer);
    if (strcmp(inputAnswer, "quit") == 0) {
      printf("\nYou quit the quiz. Final score: %d/%d\n", score, count);
      return 0;
    }
    if (strcmp(inputAnswer, elements[i]) == 0) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect. The correct answer is %s.\n", elements[i]);
    }
  }

  printf("\nCongratulations, you completed the quiz!\n");
  printf("Final score: %d/%d\n", score, count);

  return 0;
}