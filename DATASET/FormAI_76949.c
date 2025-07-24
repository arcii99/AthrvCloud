//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 3
#define MAX_QUESTIONS 5

int main() {
  srand(time(NULL));
  int attempts = 0;
  int correctAnswers = 0;
  char element[3];
  char userAnswer[3];
  int questionNumber[MAX_QUESTIONS];
  int i, j, k;

  // Generate random question numbers
  for(i = 0; i < MAX_QUESTIONS; i++) {
    int randomNumber = rand() % 118; // There are 118 elements in the periodic table
    // Check if question number already exists
    for(j = 0; j < i; j++) {
      if(questionNumber[j] == randomNumber) {
        i--;
        break;
      }
    }
    questionNumber[i] = randomNumber;
  }

  printf("Welcome to the Periodic Table Quiz!\n");
  printf("You will be given the atomic symbol of an element and you will have to guess its name.\n");
  printf("You have %d attempts per question and there are %d questions.\n", MAX_ATTEMPTS, MAX_QUESTIONS);

  // Loop through questions
  for(k = 0; k < MAX_QUESTIONS; k++) {
    printf("\nQuestion %d: What is the name of the element with atomic symbol %s?\n", k+1, element);
    // Get element name from atomic symbol
    switch(questionNumber[k]) {
      case 0:
        strcpy(element, "H");
        break;
      case 1:
        strcpy(element, "He");
        break;
      case 2:
        strcpy(element, "Li");
        break;
      case 3:
        strcpy(element, "Be");
        break;
      case 4:
        strcpy(element, "B");
        break;
      case 5:
        strcpy(element, "C");
        break;
      case 6:
        strcpy(element, "N");
        break;
      case 7:
        strcpy(element, "O");
        break;
      case 8:
        strcpy(element, "F");
        break;
      case 9:
        strcpy(element, "Ne");
        break;
      case 10:
        strcpy(element, "Na");
        break;
      case 11:
        strcpy(element, "Mg");
        break;
      case 12:
        strcpy(element, "Al");
        break;
      case 13:
        strcpy(element, "Si");
        break;
      case 14:
        strcpy(element, "P");
        break;
      case 15:
        strcpy(element, "S");
        break;
      case 16:
        strcpy(element, "Cl");
        break;
      case 17:
        strcpy(element, "Ar");
        break;
      case 18:
        strcpy(element, "K");
        break;
      case 19:
        strcpy(element, "Ca");
        break;
      case 20:
        strcpy(element, "Sc");
        break;
      case 21:
        strcpy(element, "Ti");
        break;
      case 22:
        strcpy(element, "V");
        break;
      case 23:
        strcpy(element, "Cr");
        break;
      case 24:
        strcpy(element, "Mn");
        break;
      case 25:
        strcpy(element, "Fe");
        break;
      case 26:
        strcpy(element, "Co");
        break;
      case 27:
        strcpy(element, "Ni");
        break;
      case 28:
        strcpy(element, "Cu");
        break;
      case 29:
        strcpy(element, "Zn");
        break;
      case 30:
        strcpy(element, "Ga");
        break;
      case 31:
        strcpy(element, "Ge");
        break;
      case 32:
        strcpy(element, "As");
        break;
      case 33:
        strcpy(element, "Se");
        break;
      case 34:
        strcpy(element, "Br");
        break;
      case 35:
        strcpy(element, "Kr");
        break;
      case 36:
        strcpy(element, "Rb");
        break;
      case 37:
        strcpy(element, "Sr");
        break;
      case 38:
        strcpy(element, "Y");
        break;
      case 39:
        strcpy(element, "Zr");
        break;
      case 40:
        strcpy(element, "Nb");
        break;
      case 41:
        strcpy(element, "Mo");
        break;
      case 42:
        strcpy(element, "Tc");
        break;
      case 43:
        strcpy(element, "Ru");
        break;
      case 44:
        strcpy(element, "Rh");
        break;
      case 45:
        strcpy(element, "Pd");
        break;
      case 46:
        strcpy(element, "Ag");
        break;
      case 47:
        strcpy(element, "Cd");
        break;
      case 48:
        strcpy(element, "In");
        break;
      case 49:
        strcpy(element, "Sn");
        break;
      case 50:
        strcpy(element, "Sb");
        break;
      case 51:
        strcpy(element, "Te");
        break;
      case 52:
        strcpy(element, "I");
        break;
      case 53:
        strcpy(element, "Xe");
        break;
      case 54:
        strcpy(element, "Cs");
        break;
      case 55:
        strcpy(element, "Ba");
        break;
      case 56:
        strcpy(element, "La");
        break;
      case 57:
        strcpy(element, "Ce");
        break;
      case 58:
        strcpy(element, "Pr");
        break;
      case 59:
        strcpy(element, "Nd");
        break;
      case 60:
        strcpy(element, "Pm");
        break;
      case 61:
        strcpy(element, "Sm");
        break;
      case 62:
        strcpy(element, "Eu");
        break;
      case 63:
        strcpy(element, "Gd");
        break;
      case 64:
        strcpy(element, "Tb");
        break;
      case 65:
        strcpy(element, "Dy");
        break;
      case 66:
        strcpy(element, "Ho");
        break;
      case 67:
        strcpy(element, "Er");
        break;
      case 68:
        strcpy(element, "Tm");
        break;
      case 69:
        strcpy(element, "Yb");
        break;
      case 70:
        strcpy(element, "Lu");
        break;
      case 71:
        strcpy(element, "Hf");
        break;
      case 72:
        strcpy(element, "Ta");
        break;
      case 73:
        strcpy(element, "W");
        break;
      case 74:
        strcpy(element, "Re");
        break;
      case 75:
        strcpy(element, "Os");
        break;
      case 76:
        strcpy(element, "Ir");
        break;
      case 77:
        strcpy(element, "Pt");
        break;
      case 78:
        strcpy(element, "Au");
        break;
      case 79:
        strcpy(element, "Hg");
        break;
      case 80:
        strcpy(element, "Tl");
        break;
      case 81:
        strcpy(element, "Pb");
        break;
      case 82:
        strcpy(element, "Bi");
        break;
      case 83:
        strcpy(element, "Po");
        break;
      case 84:
        strcpy(element, "At");
        break;
      case 85:
        strcpy(element, "Rn");
        break;
      case 86:
        strcpy(element, "Fr");
        break;
      case 87:
        strcpy(element, "Ra");
        break;
      case 88:
        strcpy(element, "Ac");
        break;
      case 89:
        strcpy(element, "Th");
        break;
      case 90:
        strcpy(element, "Pa");
        break;
      case 91:
        strcpy(element, "U");
        break;
      case 92:
        strcpy(element, "Np");
        break;
      case 93:
        strcpy(element, "Pu");
        break;
      case 94:
        strcpy(element, "Am");
        break;
      case 95:
        strcpy(element, "Cm");
        break;
      case 96:
        strcpy(element, "Bk");
        break;
      case 97:
        strcpy(element, "Cf");
        break;
      case 98:
        strcpy(element, "Es");
        break;
      case 99:
        strcpy(element, "Fm");
        break;
      case 100:
        strcpy(element, "Md");
        break;
      case 101:
        strcpy(element, "No");
        break;
      case 102:
        strcpy(element, "Lr");
        break;
      case 103:
        strcpy(element, "Rf");
        break;
      case 104:
        strcpy(element, "Db");
        break;
      case 105:
        strcpy(element, "Sg");
        break;
      case 106:
        strcpy(element, "Bh");
        break;
      case 107:
        strcpy(element, "Hs");
        break;
      case 108:
        strcpy(element, "Mt");
        break;
      case 109:
        strcpy(element, "Ds");
        break;
      case 110:
        strcpy(element, "Rg");
        break;
      case 111:
        strcpy(element, "Cn");
        break;
      case 112:
        strcpy(element, "Nh");
        break;
      case 113:
        strcpy(element, "Fl");
        break;
      case 114:
        strcpy(element, "Mc");
        break;
      case 115:
        strcpy(element, "Lv");
        break;
      case 116:
        strcpy(element, "Ts");
        break;
      case 117:
        strcpy(element, "Og");
        break;
    }

    // Loop through attempts
    for(attempts = 0; attempts < MAX_ATTEMPTS; attempts++) {
      printf("Attempt %d: ", attempts+1);
      scanf("%s", userAnswer);
      
      // Check if answer is correct or incorrect
      if(strcmp(userAnswer, element) == 0) {
        printf("Correct! The element is %s.\n", element);
        correctAnswers++;
        break; // Break out of attempts loop to go to next question
      }
      else {
        printf("Incorrect. Try again.\n");
      }
    }
  }

  printf("\nYou got %d out of %d questions correct! Well done!", correctAnswers, MAX_QUESTIONS);

  return 0;
}