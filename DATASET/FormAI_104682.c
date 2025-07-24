//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char name[50];
    int votes;
};

void display_menu() {
    printf("\n-- Welcome to the Electronic Voting System --\n\n");
    printf("1. Add candidate\n");
    printf("2. List candidates\n");
    printf("3. Cast vote\n");
    printf("4. Display results\n");
    printf("5. Exit\n\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, num_candidates = 0, num_voters = 0;
    struct candidate candidates[20];
    
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // add candidate
                if(num_candidates < 20) {
                    printf("\nEnter the name of the candidate: ");
                    scanf("%s", candidates[num_candidates].name);
                    candidates[num_candidates].votes = 0;
                    num_candidates++;
                    printf("Candidate added successfully!\n");
                }
                else {
                    printf("\nMaximum number of candidates reached!\n");
                }
                break;
                
            case 2: // list candidates
                printf("\n-- List of Candidates --\n\n");
                for(int i=0; i<num_candidates; i++) {
                    printf("%d. %s (%d votes)\n", i+1, candidates[i].name, candidates[i].votes);
                }
                break;
                
            case 3: // cast vote
                if(num_candidates == 0) {
                    printf("\nNo candidates added yet!\n");
                    break;
                }
                char name[50];
                int found = 0;
                printf("\nEnter the name of the candidate you want to vote for: ");
                scanf("%s", name);
                for(int i=0; i<num_candidates; i++) {
                    if(strcmp(candidates[i].name, name) == 0) {
                        candidates[i].votes++;
                        num_voters++;
                        found = 1;
                        printf("\nThank you for voting!\n");
                        break;
                    }
                }
                if(found == 0) {
                    printf("\nInvalid candidate name!\n");
                }
                break;
                
            case 4: // display results
                int max_votes = 0, max_index = 0, winner_found = 0;
                printf("\n-- Election Results --\n\n");
                for(int i=0; i<num_candidates; i++) {
                    printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
                    if(candidates[i].votes > max_votes) {
                        max_votes = candidates[i].votes;
                        max_index = i;
                    }
                    if(candidates[i].votes > (num_voters/2)) {
                        printf("\nWinner: %s!\n", candidates[i].name);
                        winner_found = 1;
                        break;
                    }
                }
                if(winner_found == 0) {
                    printf("\nLeader: %s\n", candidates[max_index].name);
                }
                break;
                
            case 5: // exit
                printf("\nThank you for using the Electronic Voting System!\n\n");
                break;
                
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
        
    } while(choice != 5);
    
    return 0;
}