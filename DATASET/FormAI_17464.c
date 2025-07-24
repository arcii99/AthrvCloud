//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
   int ID;
   char name[50];
   float score;
};

void printData(struct Data d[], int size) {
   int i;
   for(i=0; i<size; i++) 
      printf("ID: %d, Name: %s, Score: %0.2f\n", d[i].ID, d[i].name, d[i].score);
}

void dataMining(struct Data d[], int size) {
   float bestScore = d[0].score;
   int i, bestIdx = 0;
   for(i=1; i<size; i++) {
      if(d[i].score > bestScore) {
         bestIdx = i;
         bestScore = d[i].score;
      }
   }
   printf("\nThe student with the highest score is:\n");
   printf("ID: %d, Name: %s, Score: %0.2f\n\n", d[bestIdx].ID, d[bestIdx].name, d[bestIdx].score);
}

int main() {
   struct Data student[5];
   strcpy(student[0].name, "John");
   student[0].ID = 101;
   student[0].score = 76.5;

   strcpy(student[1].name, "Mary");
   student[1].ID = 102;
   student[1].score = 84.3;

   strcpy(student[2].name, "Peter");
   student[2].ID = 103;
   student[2].score = 92.7;

   strcpy(student[3].name, "Alice");
   student[3].ID = 104;
   student[3].score = 80.0;

   strcpy(student[4].name, "Bob");
   student[4].ID = 105;
   student[4].score = 88.6;

   printf("The students and their scores are:\n");
   printData(student, 5);
   dataMining(student, 5);

   return 0;
}