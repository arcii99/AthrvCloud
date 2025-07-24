//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

struct candidate {
    char name[50];
    int votes;
};

struct voter {
    char name[50];
    int voted_for;
};

struct candidate candidates[MAX_CANDIDATES];
struct voter voters[MAX_VOTERS];
int num_candidates, num_voters;

void add_candidate() {
    if (num_candidates < MAX_CANDIDATES) {
        printf("Enter name of candidate: ");
        scanf("%s", candidates[num_candidates].name);
        candidates[num_candidates].votes = 0;
        num_candidates++;
        printf("Candidate added successfully!\n");
    } else {
        printf("Maximum number of candidates (%d) reached.\n", MAX_CANDIDATES);
    }
}

void list_candidates() {
    printf("List of candidates\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%d votes)\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

void register_to_vote() {
    if (num_voters < MAX_VOTERS) {
        printf("Enter your name: ");
        scanf("%s", voters[num_voters].name);
        voters[num_voters].voted_for = -1;
        num_voters++;
        printf("Registration successful. You are registered to vote!\n");
    } else {
        printf("Maximum number of voters (%d) reached.\n", MAX_VOTERS);
    }
}

void cast_vote() {
    char name[50];
    int candidate_index = -1;

    // check if voter is registered
    int voter_index;
    printf("Enter your name: ");
    scanf("%s", name);
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(name, voters[i].name) == 0) {
            voter_index = i;
            break;
        }
        if (i == num_voters - 1) {
            printf("You are not registered to vote.\n");
            return;
        }
    }

    // check if voter has already voted
    if (voters[voter_index].voted_for != -1) {
        printf("You have already cast your vote.\n");
        return;
    }

    // ask for candidate name and find candidate index
    printf("Enter name of candidate: ");
    scanf("%s", name);
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            candidate_index = i;
            break;
        }
        if (i == num_candidates - 1) {
            printf("Candidate not found.\n");
            return;
        }
    }

    // record vote and update candidate votes
    voters[voter_index].voted_for = candidate_index;
    candidates[candidate_index].votes++;
    printf("Vote recorded successfully.\n");
}

void display_results() {
    printf("Election results\n");
    list_candidates();
}

int main() {
    num_candidates = 0;
    num_voters = 0;

    // add some candidates
    strcpy(candidates[num_candidates].name, "John Smith");
    candidates[num_candidates].votes = 0;
    num_candidates++;

    strcpy(candidates[num_candidates].name, "Mary Johnson");
    candidates[num_candidates].votes = 0;
    num_candidates++;

    // display main menu
    while (1) {
        printf("\nElectronic Voting System\n");
        printf("------------------------\n");
        printf("1. Add candidate\n");
        printf("2. List candidates\n");
        printf("3. Register to vote\n");
        printf("4. Cast vote\n");
        printf("5. Display results\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                list_candidates();
                break;
            case 3:
                register_to_vote();
                break;
            case 4:
                cast_vote();
                break;
            case 5:
                display_results();
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}