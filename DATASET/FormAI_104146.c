//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char name[50];
    int votes;
};

struct candidate candidates[10];

int num_candidates = 0;

int main() {
    int choice;

    do {
        printf("1. Add candidate\n");
        printf("2. View candidates\n");
        printf("3. Vote\n");
        printf("4. View results\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                view_candidates();
                break;
            case 3:
                vote();
                break;
            case 4:
                view_results();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 0);

    return 0;
}

void add_candidate() {
    if(num_candidates == 10) {
        printf("Maximum limit of candidates reached! No more candidates can be added.\n");
        return;
    }

    printf("Enter name of candidate: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;

    printf("Candidate %s added successfully!\n", candidates[num_candidates].name);

    num_candidates++;
}

void view_candidates() {
    if(num_candidates == 0) {
        printf("No candidates added yet!\n");
        return;
    }

    printf("List of candidates:\n");

    for(int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void vote() {
    if(num_candidates == 0) {
        printf("No candidates added yet! Cannot vote.\n");
        return;
    }

    char name[50];
    int flag = 0;

    printf("Enter name of candidate: ");
    scanf("%s", name);

    for(int i = 0; i < num_candidates; i++) {
        if(strcmp(name, candidates[i].name) == 0) {
            candidates[i].votes++;
            printf("Your vote has been recorded for candidate %s.\n", candidates[i].name);
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        printf("Candidate not found!\n");
    }
}

void view_results() {
    if(num_candidates == 0) {
        printf("No candidates added yet! No votes casted.\n");
        return;
    }

    printf("Results:\n");

    for(int i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
}