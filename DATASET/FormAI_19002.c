//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int score = 0;
   srand(time(NULL));
   printf("Welcome to the Happy Periodic Table Quiz!\n");
   printf("Can you name the element based on its atomic number? Let's find out!\n");
   printf("You will have 10 questions. Good luck!\n\n");
   for (int i = 1; i <= 10; i++) {
      int atomic_num = rand() % 118 + 1;
      printf("Question %d: What element has an atomic number of %d?\n", i, atomic_num);
      char answer[15];
      scanf("%s", answer);
      if ((atomic_num == 1 && strcmp(answer, "Hydrogen") == 0) ||
          (atomic_num == 2 && strcmp(answer, "Helium") == 0) ||
          (atomic_num == 3 && strcmp(answer, "Lithium") == 0) ||
          (atomic_num == 4 && strcmp(answer, "Beryllium") == 0) ||
          (atomic_num == 5 && strcmp(answer, "Boron") == 0) ||
          (atomic_num == 6 && strcmp(answer, "Carbon") == 0) ||
          (atomic_num == 7 && strcmp(answer, "Nitrogen") == 0) ||
          (atomic_num == 8 && strcmp(answer, "Oxygen") == 0) ||
          (atomic_num == 9 && strcmp(answer, "Fluorine") == 0) ||
          (atomic_num == 10 && strcmp(answer, "Neon") == 0) ||
          (atomic_num == 11 && strcmp(answer, "Sodium") == 0) ||
          (atomic_num == 12 && strcmp(answer, "Magnesium") == 0) ||
          (atomic_num == 13 && strcmp(answer, "Aluminum") == 0) ||
          (atomic_num == 14 && strcmp(answer, "Silicon") == 0) ||
          (atomic_num == 15 && strcmp(answer, "Phosphorus") == 0) ||
          (atomic_num == 16 && strcmp(answer, "Sulfur") == 0) ||
          (atomic_num == 17 && strcmp(answer, "Chlorine") == 0) ||
          (atomic_num == 18 && strcmp(answer, "Argon") == 0) ||
          (atomic_num == 19 && strcmp(answer, "Potassium") == 0) ||
          (atomic_num == 20 && strcmp(answer, "Calcium") == 0) ||
          (atomic_num == 21 && strcmp(answer, "Scandium") == 0) ||
          (atomic_num == 22 && strcmp(answer, "Titanium") == 0) ||
          (atomic_num == 23 && strcmp(answer, "Vanadium") == 0) ||
          (atomic_num == 24 && strcmp(answer, "Chromium") == 0) ||
          (atomic_num == 25 && strcmp(answer, "Manganese") == 0) ||
          (atomic_num == 26 && strcmp(answer, "Iron") == 0) ||
          (atomic_num == 27 && strcmp(answer, "Cobalt") == 0) ||
          (atomic_num == 28 && strcmp(answer, "Nickel") == 0) ||
          (atomic_num == 29 && strcmp(answer, "Copper") == 0) ||
          (atomic_num == 30 && strcmp(answer, "Zinc") == 0) ||
          (atomic_num == 31 && strcmp(answer, "Gallium") == 0) ||
          (atomic_num == 32 && strcmp(answer, "Germanium") == 0) ||
          (atomic_num == 33 && strcmp(answer, "Arsenic") == 0) ||
          (atomic_num == 34 && strcmp(answer, "Selenium") == 0) ||
          (atomic_num == 35 && strcmp(answer, "Bromine") == 0) ||
          (atomic_num == 36 && strcmp(answer, "Krypton") == 0) ||
          (atomic_num == 37 && strcmp(answer, "Rubidium") == 0) ||
          (atomic_num == 38 && strcmp(answer, "Strontium") == 0) ||
          (atomic_num == 39 && strcmp(answer, "Yttrium") == 0) ||
          (atomic_num == 40 && strcmp(answer, "Zirconium") == 0) ||
          (atomic_num == 41 && strcmp(answer, "Niobium") == 0) ||
          (atomic_num == 42 && strcmp(answer, "Molybdenum") == 0) ||
          (atomic_num == 43 && strcmp(answer, "Technetium") == 0) ||
          (atomic_num == 44 && strcmp(answer, "Ruthenium") == 0) ||
          (atomic_num == 45 && strcmp(answer, "Rhodium") == 0) ||
          (atomic_num == 46 && strcmp(answer, "Palladium") == 0) ||
          (atomic_num == 47 && strcmp(answer, "Silver") == 0) ||
          (atomic_num == 48 && strcmp(answer, "Cadmium") == 0) ||
          (atomic_num == 49 && strcmp(answer, "Indium") == 0) ||
          (atomic_num == 50 && strcmp(answer, "Tin") == 0) ||
          (atomic_num == 51 && strcmp(answer, "Antimony") == 0) ||
          (atomic_num == 52 && strcmp(answer, "Tellurium") == 0) ||
          (atomic_num == 53 && strcmp(answer, "Iodine") == 0) ||
          (atomic_num == 54 && strcmp(answer, "Xenon") == 0) ||
          (atomic_num == 55 && strcmp(answer, "Cesium") == 0) ||
          (atomic_num == 56 && strcmp(answer, "Barium") == 0) ||
          (atomic_num == 57 && strcmp(answer, "Lanthanum") == 0) ||
          (atomic_num == 58 && strcmp(answer, "Cerium") == 0) ||
          (atomic_num == 59 && strcmp(answer, "Praseodymium") == 0) ||
          (atomic_num == 60 && strcmp(answer, "Neodymium") == 0) ||
          (atomic_num == 61 && strcmp(answer, "Promethium") == 0) ||
          (atomic_num == 62 && strcmp(answer, "Samarium") == 0) ||
          (atomic_num == 63 && strcmp(answer, "Europium") == 0) ||
          (atomic_num == 64 && strcmp(answer, "Gadolinium") == 0) ||
          (atomic_num == 65 && strcmp(answer, "Terbium") == 0) ||
          (atomic_num == 66 && strcmp(answer, "Dysprosium") == 0) ||
          (atomic_num == 67 && strcmp(answer, "Holmium") == 0) ||
          (atomic_num == 68 && strcmp(answer, "Erbium") == 0) ||
          (atomic_num == 69 && strcmp(answer, "Thulium") == 0) ||
          (atomic_num == 70 && strcmp(answer, "Ytterbium") == 0) ||
          (atomic_num == 71 && strcmp(answer, "Lutetium") == 0) ||
          (atomic_num == 72 && strcmp(answer, "Hafnium") == 0) ||
          (atomic_num == 73 && strcmp(answer, "Tantalum") == 0) ||
          (atomic_num == 74 && strcmp(answer, "Tungsten") == 0) ||
          (atomic_num == 75 && strcmp(answer, "Rhenium") == 0) ||
          (atomic_num == 76 && strcmp(answer, "Osmium") == 0) ||
          (atomic_num == 77 && strcmp(answer, "Iridium") == 0) ||
          (atomic_num == 78 && strcmp(answer, "Platinum") == 0) ||
          (atomic_num == 79 && strcmp(answer, "Gold") == 0) ||
          (atomic_num == 80 && strcmp(answer, "Mercury") == 0) ||
          (atomic_num == 81 && strcmp(answer, "Thallium") == 0) ||
          (atomic_num == 82 && strcmp(answer, "Lead") == 0) ||
          (atomic_num == 83 && strcmp(answer, "Bismuth") == 0) ||
          (atomic_num == 84 && strcmp(answer, "Polonium") == 0) ||
          (atomic_num == 85 && strcmp(answer, "Astatine") == 0) ||
          (atomic_num == 86 && strcmp(answer, "Radon") == 0) ||
          (atomic_num == 87 && strcmp(answer, "Francium") == 0) ||
          (atomic_num == 88 && strcmp(answer, "Radium") == 0) ||
          (atomic_num == 89 && strcmp(answer, "Actinium") == 0) ||
          (atomic_num == 90 && strcmp(answer, "Thorium") == 0) ||
          (atomic_num == 91 && strcmp(answer, "Protactinium") == 0) ||
          (atomic_num == 92 && strcmp(answer, "Uranium") == 0) ||
          (atomic_num == 93 && strcmp(answer, "Neptunium") == 0) ||
          (atomic_num == 94 && strcmp(answer, "Plutonium") == 0) ||
          (atomic_num == 95 && strcmp(answer, "Americium") == 0) ||
          (atomic_num == 96 && strcmp(answer, "Curium") == 0) ||
          (atomic_num == 97 && strcmp(answer, "Berkelium") == 0) ||
          (atomic_num == 98 && strcmp(answer, "Californium") == 0) ||
          (atomic_num == 99 && strcmp(answer, "Einsteinium") == 0) ||
          (atomic_num == 100 && strcmp(answer, "Fermium") == 0) ||
          (atomic_num == 101 && strcmp(answer, "Mendelevium") == 0) ||
          (atomic_num == 102 && strcmp(answer, "Nobelium") == 0) ||
          (atomic_num == 103 && strcmp(answer, "Lawrencium") == 0) ||
          (atomic_num == 104 && strcmp(answer, "Rutherfordium") == 0) ||
          (atomic_num == 105 && strcmp(answer, "Dubnium") == 0) ||
          (atomic_num == 106 && strcmp(answer, "Seaborgium") == 0) ||
          (atomic_num == 107 && strcmp(answer, "Bohrium") == 0) ||
          (atomic_num == 108 && strcmp(answer, "Hassium") == 0) ||
          (atomic_num == 109 && strcmp(answer, "Meitnerium") == 0) ||
          (atomic_num == 110 && strcmp(answer, "Darmstadtium") == 0) ||
          (atomic_num == 111 && strcmp(answer, "Roentgenium") == 0) ||
          (atomic_num == 112 && strcmp(answer, "Copernicium") == 0) ||
          (atomic_num == 113 && strcmp(answer, "Nihonium") == 0) ||
          (atomic_num == 114 && strcmp(answer, "Flerovium") == 0) ||
          (atomic_num == 115 && strcmp(answer, "Moscovium") == 0) ||
          (atomic_num == 116 && strcmp(answer, "Livermorium") == 0) ||
          (atomic_num == 117 && strcmp(answer, "Tennessine") == 0) ||
          (atomic_num == 118 && strcmp(answer, "Oganesson") == 0)) {
         printf("Correct! You earned a point!\n");
         score++;
      } 
      else {
         printf("Sorry, the correct answer was %s.\n", answer);
      }
   }
   printf("\nCongratulations! You scored %d out of 10!\n", score);
   if (score == 10) {
      printf("Wow, you really know your elements! You must be an A+ student!\n");
   } 
   else if (score >= 7) {
      printf("Great job! You really know your elements!\n");
   } 
   else {
      printf("Don't worry, you'll do better next time! Keep studying those elements!\n");
   }
   return 0;
}