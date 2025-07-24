//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

struct Candidate{
  char name[50];
  int votes;
}candidates[MAX_CANDIDATES];

int main(int argc, char*argv[]){
  int num_voters = 0;
  int voter_id[MAX_VOTERS];
  int vote_list[MAX_VOTERS];
  char buf[256];

  // Ask for number of voters
  printf("Enter the number of voters: ");
  fgets(buf, 256, stdin);
  num_voters = atoi(buf);

  // Ask for voter IDs
  printf("Enter the voter IDs:\n");
  for(int i = 0; i < num_voters; i++){
    printf("Voter #%d's ID: ", i+1);
    fgets(buf, 256, stdin);
    voter_id[i] = atoi(buf);
  }

  // Ask for candidates
  printf("Enter the candidates' names:\n");
  for(int i = 0; i < MAX_CANDIDATES; i++){
    printf("Candidate #%d's name: ", i+1);
    fgets(buf, 256, stdin);
    strtok(buf, "\n");
    strcpy(candidates[i].name, buf);
    candidates[i].votes = 0;
  }

  // Start voting process
  printf("Voting has started. Enter the candidate's number to vote for them or type 'done' to end voting.\n");
  int done = 0;
  int candidate_num = 0;
  while(!done){
    fgets(buf, 256, stdin);

    // Check if the user is done
    if(strcmp(buf, "done\n") == 0){
      done = 1;
      continue;
    }

    // Get the candidate's number
    candidate_num = atoi(buf);

    // Check if the candidate number is valid
    if(candidate_num <= 0 || candidate_num > MAX_CANDIDATES){
      printf("Invalid candidate number.\n");
      continue;
    }

    // Add the vote to the candidate
    candidates[candidate_num-1].votes++;

    // Add the vote to the vote list
    vote_list[num_voters++] = candidate_num;
  }

  // Print the results
  printf("Voting has ended. Here are the results:\n");
  for(int i = 0; i < MAX_CANDIDATES; i++){
    printf("%s: %d\n", candidates[i].name, candidates[i].votes);
  }

  // Find the winner
  int max_votes = 0;
  int winner_num = 0;
  for(int i = 0; i < MAX_CANDIDATES; i++){
    if(candidates[i].votes > max_votes){
      max_votes = candidates[i].votes;
      winner_num = i;
    }
  }
  printf("The winner is %s with %d votes.\n", candidates[winner_num].name, max_votes);

  // Display the vote list
  printf("Here is the vote list:\n");
  for(int i = 0; i < num_voters; i++){
    printf("Voter #%d voted for %s.\n", i+1, candidates[vote_list[i]-1].name);
  }

  return 0;
}