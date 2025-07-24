//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char name[50];
    int votes;
};

struct voter {
    char name[50];
    int voted; // 1 if voted, 0 if not
};

int main() {
    struct candidate candidates[5];
    struct voter voters[50];
    int num_voters = 0;
    int num_candidates = 5;
    int vote_count = 0;

    // Initialize candidates
    strcpy(candidates[0].name, "John Doe");
    candidates[0].votes = 0;
    strcpy(candidates[1].name, "Jane Smith");
    candidates[1].votes = 0;
    strcpy(candidates[2].name, "Joe Johnson");
    candidates[2].votes = 0;
    strcpy(candidates[3].name, "Sarah Lee");
    candidates[3].votes = 0;
    strcpy(candidates[4].name, "Billy James");
    candidates[4].votes = 0;

    while (1) {
        printf("Welcome to the Electronic Voting System.\n");
        printf("Enter '1' to add a voter.\n");
        printf("Enter '2' to start voting.\n");
        printf("Enter '3' to display results.\n");
        printf("Enter '4' to exit.\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_voters < 50) {
                    printf("Enter voter name: ");
                    char name[50];
                    scanf("%s", name);

                    // Check if voter already exists
                    int exists = 0;
                    for (int i = 0; i < num_voters; i++) {
                        if (strcmp(voters[i].name, name) == 0) {
                            printf("Voter already exists.\n");
                            exists = 1;
                            break;
                        }
                    }
                    if (exists == 0) {
                        strcpy(voters[num_voters].name, name);
                        num_voters++;
                        printf("Voter added successfully.\n");
                    }
                }
                else {
                    printf("Maximum number of voters reached.\n");
                }
                break;
            }
            case 2: {
                if (num_voters == 0) {
                    printf("No voters added yet.\n");
                }
                else {
                    printf("Voting has started.\n");
                    for (int i = 0; i < num_voters; i++) {
                        if (voters[i].voted == 0) {
                            printf("%s, please enter your vote.\n", voters[i].name);
                            printf("Enter '1' to vote for John Doe.\n");
                            printf("Enter '2' to vote for Jane Smith.\n");
                            printf("Enter '3' to vote for Joe Johnson.\n");
                            printf("Enter '4' to vote for Sarah Lee.\n");
                            printf("Enter '5' to vote for Billy James.\n");
                            printf("Enter your choice: ");

                            int vote_choice;
                            scanf("%d", &vote_choice);

                            if (vote_choice >= 1 && vote_choice <= 5) {
                                candidates[vote_choice - 1].votes++;
                                vote_count++;
                                voters[i].voted = 1;
                                printf("Vote recorded successfully.\n");
                            }
                            else {
                                printf("Invalid vote choice.\n");
                            }
                        }
                        else {
                            printf("%s has already voted.\n", voters[i].name);
                        }
                    }
                    printf("Voting has ended.\n");
                }
                break;
            }
            case 3: {
                if (vote_count == 0) {
                    printf("No votes recorded yet.\n");
                }
                else {
                    printf("Results:\n");
                    for (int i = 0; i < num_candidates; i++) {
                        float percentage = (float) candidates[i].votes / vote_count * 100;
                        printf("%s: %d votes (%.2f%%)\n", candidates[i].name, candidates[i].votes, percentage);
                    }
                }
                break;
            }
            case 4: {
                printf("Thank you for using the Electronic Voting System.\n");
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}