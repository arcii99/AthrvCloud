//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char elements[118][3] = {{"H"}, {"He"}, {"Li"}, {"Be"}, {"B"}, {"C"}, {"N"}, {"O"}, {"F"}, {"Ne"}, {"Na"}, {"Mg"}, {"Al"}, {"Si"}, {"P"}, {"S"}, {"Cl"}, {"Ar"}, {"K"}, {"Ca"}, {"Sc"}, {"Ti"}, {"V"}, {"Cr"}, {"Mn"}, {"Fe"}, {"Co"}, {"Ni"}, {"Cu"}, {"Zn"}, {"Ga"}, {"Ge"}, {"As"}, {"Se"}, {"Br"}, {"Kr"}, {"Rb"}, {"Sr"}, {"Y"}, {"Zr"}, {"Nb"}, {"Mo"}, {"Tc"}, {"Ru"}, {"Rh"}, {"Pd"}, {"Ag"}, {"Cd"}, {"In"}, {"Sn"}, {"Sb"}, {"Te"}, {"I"}, {"Xe"}, {"Cs"}, {"Ba"}, {"La"}, {"Ce"}, {"Pr"}, {"Nd"}, {"Pm"}, {"Sm"}, {"Eu"}, {"Gd"}, {"Tb"}, {"Dy"}, {"Ho"}, {"Er"}, {"Tm"}, {"Yb"}, {"Lu"}, {"Hf"}, {"Ta"}, {"W"}, {"Re"}, {"Os"}, {"Ir"}, {"Pt"}, {"Au"}, {"Hg"}, {"Tl"}, {"Pb"}, {"Bi"}, {"Po"}, {"At"}, {"Rn"}, {"Fr"}, {"Ra"}, {"Ac"}, {"Th"}, {"Pa"}, {"U"}, {"Np"}, {"Pu"}, {"Am"}, {"Cm"}, {"Bk"}, {"Cf"}, {"Es"}, {"Fm"}, {"Md"}, {"No"}, {"Lr"}, {"Rf"}, {"Db"}, {"Sg"}, {"Bh"}, {"Hs"}, {"Mt"}, {"Ds"}, {"Rg"}, {"Cn"}, {"Nh"}, {"Fl"}, {"Mc"}, {"Lv"}, {"Ts"}, {"Og"}};
  int atomic_numbers[118] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118};
  int randomized[118];
  
  // Randomize the atomic numbers to create a new game
  srand(time(NULL));
  for (int i=0; i<118; i++) {
    randomized[i] = atomic_numbers[i];
  }
  for (int i=117; i>=1; i--) {
    int j = rand() % (i+1);
    int temp = randomized[i];
    randomized[i] = randomized[j];
    randomized[j] = temp;
  }
  
  int score = 0;
  int num_answered = 0;
  
  // Start quiz
  printf("Welcome to the Periodic Table Quiz!\n");
  printf("You will be shown the names of elements and must input their atomic numbers.\n");
  
  while (num_answered < 118) {
    int index = rand() % 118;
    char element[3];
    sprintf(element, "%s", elements[index]);
    
    // Check if element has already been answered, skip if true
    int answered = 0;
    for (int i=0; i<num_answered; i++) {
      if (randomized[index] == randomized[i]) {
        answered = 1;
        break;
      }
    }
    if (answered) {
      continue;
    }
    
    printf("%s: ", element);
    int answer;
    scanf("%d", &answer);
    
    if (answer == randomized[index]) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect, the correct answer is %d\n", randomized[index]);
    }
    num_answered++;
  }
  
  // Display final score
  printf("Quiz completed! Your score is %d out of %d\n", score, 118);
  
  return 0;
}