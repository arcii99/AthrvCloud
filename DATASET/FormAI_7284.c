//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
  int votes[5] = {0}; // An array to store the vote counts
  int choice;
  printf("Welcome to the Electronic Voting System!\n");

  while (1) { // An infinite loop will keep the program running until it is manually terminated
    printf("\nPlease select your candidate (1-5):\n");
    printf("1. John Snow\n2. Daenerys Targaryen\n3. Tyrion Lannister\n4. Sansa Stark\n5. Arya Stark\n");
    printf("Choice: ");
    scanf("%d", &choice); // Read the user's choice

    switch (choice) { // Use a switch statement to add a vote to the corresponding candidate's count
      case 1:
        votes[0] += 1;
        break;
      case 2:
        votes[1] += 1;
        break;
      case 3:
        votes[2] += 1;
        break;
      case 4:
        votes[3] += 1;
        break;
      case 5:
        votes[4] += 1;
        break;
      default:
        printf("Invalid choice! Please try again.\n");
    }

    printf("Current Vote Count:\n"); // Display the current vote count after each vote is added
    printf("John Snow: %d\n", votes[0]);
    printf("Daenerys Targaryen: %d\n", votes[1]);
    printf("Tyrion Lannister: %d\n", votes[2]);
    printf("Sansa Stark: %d\n", votes[3]);
    printf("Arya Stark: %d\n", votes[4]);
  }

  return 0; // End of program
}