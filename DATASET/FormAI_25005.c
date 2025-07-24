//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for the candidate
typedef struct {
    char name[20];
    int votes;
} candidate;

// Structure for the list of candidates
typedef struct {
    candidate* list[10];
    int count;
} candidate_list;

// Structure for the voter
typedef struct {
    char name[20];
    int age;
    int voted;
} voter;

// Structure for the list of voters
typedef struct {
    voter* list[100];
    int count;
} voter_list;

int main() {
    candidate_list candidates;
    voter_list voters;

    candidates.count = 0;
    voters.count = 0;

    // Adding candidates
    candidate c1;
    strcpy(c1.name, "Candidate 1");
    c1.votes = 0;
    candidates.list[candidates.count] = &c1;
    candidates.count++;

    candidate c2;
    strcpy(c2.name, "Candidate 2");
    c2.votes = 0;
    candidates.list[candidates.count] = &c2;
    candidates.count++;

    candidate c3;
    strcpy(c3.name, "Candidate 3");
    c3.votes = 0;
    candidates.list[candidates.count] = &c3;
    candidates.count++;

    // Adding voters
    voter v1;
    strcpy(v1.name, "Voter 1");
    v1.age = 25;
    v1.voted = 0;
    voters.list[voters.count] = &v1;
    voters.count++;

    voter v2;
    strcpy(v2.name, "Voter 2");
    v2.age = 30;
    v2.voted = 0;
    voters.list[voters.count] = &v2;
    voters.count++;

    // Voting process
    int option;
    while (1) {
        printf("Enter your option:\n");
        printf("1. Vote\n");
        printf("2. Show results\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        if (option == 1) {
            // Check if the voter is already voted
            char voter_name[20];
            printf("Enter your name:\n");
            scanf("%s", voter_name);

            int found_voter = 0;
            for (int i = 0; i < voters.count; i++) {
                if (strcmp(voters.list[i]->name, voter_name) == 0) {
                    found_voter = 1;

                    if (voters.list[i]->voted == 1) {
                        printf("You have already voted!\n");
                        break;
                    }

                    // Vote for the candidate
                    char candidate_name[20];
                    printf("Enter the candidate name:\n");
                    scanf("%s", candidate_name);

                    int found_candidate = 0;
                    for (int j = 0; j < candidates.count; j++) {
                        if (strcmp(candidates.list[j]->name, candidate_name) == 0) {
                            found_candidate = 1;
                            candidates.list[j]->votes++;
                            printf("Vote added!\n");
                            voters.list[i]->voted = 1;
                            break;
                        }
                    }

                    if (found_candidate == 0) {
                        printf("Candidate not found!\n");
                    }

                    break;
                }
            }

            if (found_voter == 0) {
                printf("Voter not found!\n");
            }
        }
        else if (option == 2) {
            printf("Results:\n");
            for (int i = 0; i < candidates.count; i++) {
                printf("%s: %d votes\n", candidates.list[i]->name, candidates.list[i]->votes);
            }
        }
        else if (option == 3) {
            break;
        }
        else {
            printf("Invalid option!\n");
        }
    }

    return 0;
}