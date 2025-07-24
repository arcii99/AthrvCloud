//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: puzzling
#include <stdio.h>

int main() {
   char candidates[4][20] = {"Candidate A", "Candidate B", "Candidate C", "Candidate D"}; 
   int votes[4] = {0, 0, 0, 0}; // initializing vote count for each candidate
   
   int voter_id; 
   int vote;
   char answer[10];
   
   printf("Welcome to the Electronic Voting System!\n");
   printf("Enter your voter ID: ");
   scanf("%d", &voter_id);
   
   printf("Here are the candidates:\n");
   for (int i = 0; i < 4; i++) {
       printf("%d. %s\n", i+1, candidates[i]);
   }
   
   printf("Enter your vote (1-4): ");
   scanf("%d", &vote);
   
   if (vote >= 1 && vote <= 4) {
       votes[vote-1]++;
       printf("Thank you for your vote.\n");
   } else {
       printf("Invalid vote.\n");
   }
   
   printf("Do you want to see the vote count? (yes or no): ");
   scanf("%s", answer);
   
   if (strcmp(answer, "yes") == 0) {
       printf("Vote count:\n");
       for (int i = 0; i < 4; i++) {
           printf("%s: %d\n", candidates[i], votes[i]);
       }
   }
   
   return 0;
}