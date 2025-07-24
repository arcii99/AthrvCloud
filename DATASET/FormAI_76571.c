//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char * symbol;
   char * name;
   int atomicNumber;
   float atomicWeight;
} Element;

void printTable(Element table[118]);
int getAnswer();
void printResult(int score, int totalQuestions);

int main() {

   Element periodicTable[118];

   periodicTable[0].symbol = "H";
   periodicTable[0].name = "Hydrogen";
   periodicTable[0].atomicNumber = 1;
   periodicTable[0].atomicWeight = 1.008;

   periodicTable[1].symbol = "He";
   periodicTable[1].name = "Helium";
   periodicTable[1].atomicNumber = 2;
   periodicTable[1].atomicWeight = 4.0026;

   periodicTable[2].symbol = "Li";
   periodicTable[2].name = "Lithium";
   periodicTable[2].atomicNumber = 3;
   periodicTable[2].atomicWeight = 6.94;

   periodicTable[3].symbol = "Be";
   periodicTable[3].name = "Beryllium";
   periodicTable[3].atomicNumber = 4;
   periodicTable[3].atomicWeight = 9.0122;

   periodicTable[4].symbol = "B";
   periodicTable[4].name = "Boron";
   periodicTable[4].atomicNumber = 5;
   periodicTable[4].atomicWeight = 10.81;

   periodicTable[5].symbol = "C";
   periodicTable[5].name = "Carbon";
   periodicTable[5].atomicNumber = 6;
   periodicTable[5].atomicWeight = 12.011;

   // Add more elements...


   printTable(periodicTable);

   // Ask user questions
   int totalQuestions = 5;
   int score = 0;
   
   printf("\nWelcome to the C Programming Periodic Table Quiz!\n");
   printf("Answer the following %d questions:\n", totalQuestions);

   for (int i = 0; i < totalQuestions; i++) {
      int randomIndex = rand() % 118;
      printf("\nQuestion %d: What is the symbol for %s?\n", i+1, periodicTable[randomIndex].name);

      // Get user input
      int answer = getAnswer();

      // Check answer
      if (answer == randomIndex) {
         printf("Correct!\n");
         score++;
      } else {
         printf("Incorrect! The correct answer was %s.\n", periodicTable[randomIndex].symbol);
      }
   }

   printResult(score, totalQuestions);

   return 0;
}

void printTable(Element table[118]) {
   printf("%-4s %-10s %-20s %s\n", "No.", "Symbol", "Name", "Atomic Weight (amu)");
   printf("-----------------------------------------------------------\n");
   
   for (int i = 0; i < 118; i++) {
      printf("%-4d %-10s %-20s %.4f\n", table[i].atomicNumber, table[i].symbol, table[i].name, table[i].atomicWeight);
   }
}

int getAnswer() {
   printf("Enter the atomic number for the element: ");
   int answer;
   scanf("%d", &answer);
   getchar(); // Clear input buffer
   return answer - 1; // Convert to 0-based index
}

void printResult(int score, int totalQuestions) {
   printf("\nYour score is %d out of %d.\n", score, totalQuestions);
   if (score == totalQuestions) {
      printf("Wow, you got a perfect score! Congratulations!\n");
   } else if (score >= totalQuestions * 0.8) {
      printf("Good job, you did well!\n");
   } else {
      printf("Better luck next time!\n");
   }
}