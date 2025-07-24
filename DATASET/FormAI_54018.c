//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 50

// Candidate struct
typedef struct Candidate {
  int candidateId;
  char name[50];
} Candidate;

// Voter struct
typedef struct Voter {
  int voterId;
  int votedForCandidateId;
  int hasVoted;
} Voter;

// Voting System struct
typedef struct VotingSystem {
  Candidate candidates[MAX_CANDIDATES];
  Voter voters[MAX_VOTERS];
  int numCandidates;
  int numVoters;
} VotingSystem;

// Function to initialize the voting system
void initializeVotingSystem(VotingSystem* system) {
  system->numCandidates = 0;
  system->numVoters = 0;
}

// Function to add a candidate to the voting system
void addCandidate(VotingSystem* system, char* name) {
  Candidate newCandidate;
  newCandidate.candidateId = system->numCandidates;
  strcpy(newCandidate.name, name);
  system->candidates[system->numCandidates++] = newCandidate;
}

// Function to find a candidate by name
int findCandidate(VotingSystem* system, char* name) {
  for (int i = 0; i < system->numCandidates; i++) {
    if (strcmp(system->candidates[i].name, name) == 0) {
      return system->candidates[i].candidateId;
    }
  }
  return -1;
}

// Function to add a voter to the voting system
void addVoter(VotingSystem* system, int id) {
  Voter newVoter;
  newVoter.voterId = id;
  newVoter.votedForCandidateId = -1;
  newVoter.hasVoted = 0;
  system->voters[system->numVoters++] = newVoter;
}

// Function to cast a vote
void castVote(VotingSystem* system, int voterId, int candidateId) {
  for (int i = 0; i < system->numVoters; i++) {
    if (system->voters[i].voterId == voterId) {
      if (!system->voters[i].hasVoted) {
        system->voters[i].votedForCandidateId = candidateId;
        system->voters[i].hasVoted = 1;
        printf("Vote cast successfully.\n");
        return;
      } else {
        printf("You have already casted a vote.\n");
        return;
      }
    }
  }
  printf("Voter ID not found.\n");
}

// Function to display the election results
void showElectionResults(VotingSystem* system) {
  printf("Election Results\n");
  printf("----------------\n");
  for (int i = 0; i < system->numCandidates; i++) {
    int numVotes = 0;

    for (int j = 0; j < system->numVoters; j++) {
      if (system->voters[j].votedForCandidateId == i) {
        numVotes++;
      }
    }

    printf("%s: %d votes\n", system->candidates[i].name, numVotes);
  }
}

int main() {
  VotingSystem system;

  initializeVotingSystem(&system);

  addCandidate(&system, "Alice");
  addCandidate(&system, "Bob");
  addCandidate(&system, "Charlie");

  addVoter(&system, 1);
  addVoter(&system, 2);
  addVoter(&system, 3);

  castVote(&system, 1, findCandidate(&system, "Alice"));
  castVote(&system, 2, findCandidate(&system, "Bob"));
  castVote(&system, 3, findCandidate(&system, "Charlie"));

  showElectionResults(&system);

  return 0;
}