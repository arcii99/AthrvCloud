//FormAI DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int solve_mystery(int suspects) {
   if (suspects == 1) {
      printf("Aha! Mr. X is the culprit!\n");
      return 0;
   } else {
      printf("Hmm, let's interrogate these suspects further...\n");
      for (int i = 1; i <= suspects; i++) {
         printf("Interrogating suspect %d...\n", i);
         printf("Did you do it?\n");
         printf("Enter y for yes and n for no: ");
         char answer;
         scanf("%c", &answer);
         switch(answer) {
            case 'y':
               printf("You are guilty, suspect %d!\n", i);
               return 0;
               break;
            case 'n':
               printf("You are innocent, suspect %d.\n", i);
               break;
            default:
               printf("Invalid answer. You are probably the culprit!\n");
               return 0;
         }
      }
      printf("We may need to interrogate again. Let's reduce the suspects.\n");
      solve_mystery(suspects/2);
   }
}

int main() {
   int num_of_suspects;
   printf("Sherlock Holmes Recursive Program\n");
   printf("Enter the number of suspects: ");
   scanf("%d", &num_of_suspects);
   solve_mystery(num_of_suspects);
   return 0;
}