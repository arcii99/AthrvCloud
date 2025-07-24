//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
/*
* The following is an Electronic Voting System program written in the Ada Lovelace style.
* This program is designed to handle electronic voting for an election with multiple candidates
* and multiple voters, as well as output the results of the election.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

/*
* This struct represents a candidate in the election.
* It contains a name and a vote count.
*/
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

/*
* This struct represents a voter in the election.
* It contains a name and a list of the candidates they voted for.
*/
typedef struct voter {
    char name[50];
    int votes[MAX_CANDIDATES];
} voter;

/*
* This function takes a candidate struct and initializes it with a given name and 0 votes.
*/
void init_candidate(candidate *c, char *name) {
    strcpy(c->name, name);
    c->votes = 0;
}

/*
* This function takes a voter struct and initializes it with a given name and empty votes list.
*/
void init_voter(voter *v, char *name) {
    int i;
    strcpy(v->name, name);
    for (i = 0; i < MAX_CANDIDATES; i++) {
        v->votes[i] = -1;
    }
}

/*
* This function takes an array of candidate structs and initializes them with given names.
*/
void init_candidates(candidate candidates[MAX_CANDIDATES], char *names[MAX_CANDIDATES], int num_candidates) {
    int i;
    for (i = 0; i < num_candidates; i++) {
        init_candidate(&candidates[i], names[i]);
    }
}

/*
* This function takes an array of voter structs and initializes them with given names.
*/
void init_voters(voter voters[MAX_VOTERS], char *names[MAX_VOTERS], int num_voters) {
    int i;
    for (i = 0; i < num_voters; i++) {
        init_voter(&voters[i], names[i]);
    }
}

/*
* This function takes a candidate struct and a voter struct and adds a vote to the candidate from the voter.
*/
void vote(candidate *c, voter *v, int candidate_index) {
    v->votes[candidate_index] = 1;
    c->votes++;
}

/*
* This function takes an array of candidate structs and an array of voter structs and runs the election,
* tallying the votes and outputting the results.
*/
void run_election(candidate candidates[MAX_CANDIDATES], voter voters[MAX_VOTERS], int num_candidates, int num_voters) {
    int i, j, candidate_index, max_votes = -1, total_votes = 0;
    for (i = 0; i < num_voters; i++) {
        for (j = 0; j < num_candidates; j++) {
            candidate_index = voters[i].votes[j];
            if (candidate_index != -1) {
                vote(&candidates[candidate_index], &voters[i], candidate_index);
            }
        }
    }

    printf("Election Results:\n\n");

    for (i = 0; i < num_candidates; i++) {
        printf("Candidate %s received %d votes.\n", candidates[i].name, candidates[i].votes);
        total_votes += candidates[i].votes;
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }

    printf("\n%d votes were cast in total.\n\n", total_votes);

    printf("Winner(s):\n");

    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes == max_votes) {
            printf("%s\n", candidates[i].name);
        }
    }
}

int main() {
    candidate candidates[MAX_CANDIDATES];
    char *candidate_names[MAX_CANDIDATES] = {"Candidate 1", "Candidate 2", "Candidate 3"};
    int num_candidates = 3;

    voter voters[MAX_VOTERS];
    char *voter_names[MAX_VOTERS] = {"Voter 1", "Voter 2", "Voter 3"};
    int num_voters = 3;

    init_candidates(candidates, candidate_names, num_candidates);
    init_voters(voters, voter_names, num_voters);

    /* Temporary hard-coded voting for test purposes */
    vote(&candidates[0], &voters[0], 0);
    vote(&candidates[1], &voters[0], 1);
    vote(&candidates[0], &voters[1], 0);
    vote(&candidates[2], &voters[1], 2);
    vote(&candidates[1], &voters[2], 1);
    vote(&candidates[2], &voters[2], 2);

    run_election(candidates, voters, num_candidates, num_voters);

    return 0;
}