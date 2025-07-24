//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VOTE 100
#define MAX_NAME 50

struct candidate{
    char name[MAX_NAME];
    int votes;
};

void clear_screen(){
    printf("\033[2J\033[H");
}

void print_banner(){
    clear_screen();
    printf("#############################################\n");
    printf("#                                           #\n");
    printf("#        CYBERPUNK ELECTRONIC VOTING         #\n");
    printf("#                                           #\n");
    printf("#############################################\n");
}

void print_candidate(struct candidate c){
    printf("%-30s %d\n", c.name, c.votes);
}

void print_results(struct candidate candidates[], int num_candidates){
    print_banner();
    printf("%-30s %s\n", "Candidate Name", "Votes Received");
    printf("---------------------------------------------\n");
    for(int i=0; i<num_candidates; i++){
        print_candidate(candidates[i]);
    }
    printf("---------------------------------------------\n");
}

void get_vote(struct candidate candidates[], int num_candidates){
    char selected_candidate[MAX_NAME];
    int candidate_found = 0;

    printf("Enter your vote: ");
    fgets(selected_candidate, MAX_NAME, stdin);

    for(int i=0; i<num_candidates; i++){
        if(strcmp(selected_candidate, candidates[i].name) == 0){
            candidates[i].votes++;
            candidate_found = 1;
            printf("Thank you for voting!\n");
            break;
        }
    }

    if(!candidate_found){
        printf("Error: Invalid candidate. Please try again.\n");
    }
}

void run_election(struct candidate candidates[], int num_candidates){
    int num_votes = 0;

    do{
        print_banner();
        printf("%d votes cast so far.\n", num_votes);
        printf("%-30s\n", "List of Candidates");
        printf("---------------------------------------------\n");
        for(int i=0; i<num_candidates; i++){
            printf("%d. %s\n", i+1, candidates[i].name);
        }
        printf("---------------------------------------------\n");

        get_vote(candidates, num_candidates);
        num_votes++;
    } while(num_votes < MAX_VOTE);
}

int main(){
    struct candidate candidates[] = {
        {"Jack Black", 0},
        {"Alice Green", 0},
        {"Mike Smith", 0},
        {"Samantha Lee", 0}
    };
    int num_candidates = sizeof(candidates) / sizeof(struct candidate);

    print_banner();
    printf("Welcome to the Cyberpunk Electronic Voting System!\n");

    run_election(candidates, num_candidates);

    print_results(candidates, num_candidates);

    printf("Press any key to exit.");
    getchar();

    return 0;
}