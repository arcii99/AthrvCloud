//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

struct Candidate {
    int id;
    char name[50];
    int votes;
} candidates[3] = {{1, "Candidate 1", 0}, {2, "Candidate 2", 0}, {3, "Candidate 3", 0}};

void printCandidates() {
    printf("\nCandidates:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
}

void castVote(int id) {
    for (int i = 0; i < 3; i++) {
        if (candidates[i].id == id) {
            candidates[i].votes++;
            printf("Vote for %s recorded.\n", candidates[i].name);
            return;
        }
    }
    printf("Invalid candidate ID.\n");
}

void printResults() {
    printf("\nResults:\n");
    int max_votes = 0;
    int winner_index;
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }
    printf("Winner: %s\n", candidates[winner_index].name);
}

int main() {
    int choice;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. View Candidates\n");
        printf("2. Cast Vote\n");
        printf("3. View Results\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printCandidates();
                break;
            case 2:
                int id;
                printf("Enter candidate ID: ");
                scanf("%d", &id);
                castVote(id);
                break;
            case 3:
                printResults();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}