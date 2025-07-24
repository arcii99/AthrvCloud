//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 20

struct Candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

struct Voter {
    int id;
    int voted_for; // candidate index
};

int total_candidates = 0;
struct Candidate candidates[MAX_CANDIDATES];

int total_voters = 0;
struct Voter voters[MAX_VOTERS];

void print_candidates() {
    printf("Candidates:\n");
    for (int i = 0; i < total_candidates; i++) {
        printf("%d. %s (%d votes)\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

void print_voters() {
    printf("Voters:\n");
    for (int i = 0; i < total_voters; i++) {
        printf("%d. %d\n", i+1, voters[i].id);
    }
}

int get_candidate_index(char* name) {
    for (int i = 0; i < total_candidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int get_voter_index(int id) {
    for (int i = 0; i < total_voters; i++) {
        if (voters[i].id == id) {
            return i;
        }
    }
    return -1;
}

void add_candidate(char* name) {
    if (total_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    strcpy(candidates[total_candidates].name, name);
    candidates[total_candidates].votes = 0;
    total_candidates++;
}

void add_voter(int id) {
    if (get_voter_index(id) >= 0) { // already exists
        printf("Voter already exists.\n");
        return;
    }
    if (total_voters >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }
    voters[total_voters].id = id;
    voters[total_voters].voted_for = -1; // not voted yet
    total_voters++;
}

void vote(int voter_id, char* candidate_name) {
    int candidate_index = get_candidate_index(candidate_name);
    if (candidate_index == -1) {
        printf("Invalid candidate name.\n");
        return;
    }
    int voter_index = get_voter_index(voter_id);
    if (voter_index == -1) {
        printf("Invalid voter ID.\n");
        return;
    }
    if (voters[voter_index].voted_for != -1) {
        printf("This voter has already voted.\n");
        return;
    }
    candidates[candidate_index].votes++;
    voters[voter_index].voted_for = candidate_index;
    printf("Vote casted successfully.\n");
}

void print_winner() {
    int max_votes = -1;
    int winner_index = -1;
    for (int i = 0; i < total_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }
    printf("Winner: %s (%d votes)\n", candidates[winner_index].name, candidates[winner_index].votes);
}

int main() {
    add_candidate("John");
    add_candidate("Mike");
    add_candidate("Alice");
    
    add_voter(1);
    add_voter(2);
    add_voter(3);
    
    vote(1, "Mike");
    vote(2, "John");
    vote(3, "Alice");
    
    print_candidates();
    print_voters();
    print_winner();
    
    return 0;
}