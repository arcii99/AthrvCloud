//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATE 10
#define MAX_VOTER 1000

int num_voters = 0;
int num_candidate = 0;
char candidate_name[MAX_CANDIDATE][50];

struct voter {
    int id;
    int voted_candidate;
};

struct voter list_of_voters[MAX_VOTER];

void initialize() {
    int i;
    for(i = 0; i < MAX_CANDIDATE; i++) {
        candidate_name[i][0] = '\0';
    }
}

void addCandidate() {

    if(num_candidate >= MAX_CANDIDATE) {
        printf("Sorry, maximum number of candidates reached!\n");
    } else {
        printf("Enter candidate name: ");
        scanf("%s", candidate_name[num_candidate]);
        num_candidate++;
    }
}

void listCandidates() {
    int i;

    printf("List of candidates:\n");

    for(i = 0; i < num_candidate; i++) {
        printf("%d. %s\n", i+1, candidate_name[i]);
    }
}

void castVote() {
    int voter_id, candidate_choice;

    printf("Enter voter id: ");
    scanf("%d", &voter_id);

    if(voter_id < 1 || voter_id > MAX_VOTER) {
        printf("Invalid voter id!\n");
        return;
    }

    if(list_of_voters[voter_id].id != 0) {
        printf("Sorry, you have already cast your vote!\n");
        return;
    }
    printf("List of candidates:\n");
    listCandidates();

    printf("Enter candidate choice: ");
    scanf("%d", &candidate_choice);

    if(candidate_choice < 1 || candidate_choice > num_candidate) {
        printf("Invalid candidate choice!\n");
        return;
    }
    list_of_voters[voter_id].id = voter_id;
    list_of_voters[voter_id].voted_candidate = candidate_choice-1;
    printf("Thanks for casting your vote!\n");
    num_voters++;
}

void countVotes() {
    int i, j, votes[MAX_CANDIDATE] = {0};

    if(num_voters == 0) {
        printf("No votes cast yet!\n");
        return;
    }

    for(i = 0; i < num_voters; i++) {
        votes[list_of_voters[i].voted_candidate]++;
    }

    printf("Vote count:\n");

    for(i = 0; i < num_candidate; i++) {
        printf("%s - %d votes\n", candidate_name[i], votes[i]);
    }

}

int main() {
    int choice;

    initialize();

    while(1) {
        printf("\nElectronic voting system\n");
        printf("-----------------------\n");
        printf("1. Add candidate\n");
        printf("2. List candidates\n");
        printf("3. Cast vote\n");
        printf("4. Count votes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                listCandidates();
                break;
            case 3:
                castVote();
                break;
            case 4:
                countVotes();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}