//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vote, romeo_vote = 0, juliet_vote = 0;
    char choice;

    printf("Welcome to the Verona Electronic Voting System!\n\n");

    do {
        printf("\nPlease enter your vote:\n");
        printf("1. Romeo  2. Juliet\n");
        scanf("%d", &vote);

        switch (vote) {
            case 1:
                romeo_vote++;
                printf("You have voted for Romeo!\n");
                break;

            case 2:
                juliet_vote++;
                printf("You have voted for Juliet!\n");
                break;

            default:
                printf("Invalid vote! Please select either 1 or 2.\n");
                break;
        }

        printf("\nDo you wish to continue voting? (y/n)\n");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nVoting ends!\n\n");

    if (romeo_vote > juliet_vote) {
        printf("Romeo wins with %d votes!\n", romeo_vote);
    } else if (juliet_vote > romeo_vote) {
        printf("Juliet wins with %d votes!\n", juliet_vote);
    } else {
        printf("It's a tie! Both Romeo and Juliet have %d votes each.\n", romeo_vote);
    }

    return 0;
}