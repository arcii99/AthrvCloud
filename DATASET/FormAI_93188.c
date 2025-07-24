//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: realistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_CANDIDATES 10
#define NAME_LENGTH 20
#define MAX_VOTERS 1000

typedef struct candidate {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

typedef struct voter {
    char name[NAME_LENGTH];
    int id;
    int has_voted;
} Voter;

void initialize_candidates(Candidate *);
void initialize_voters(Voter *);
int authenticate_voter(Voter *, int);
void display_candidates(Candidate *);
void cast_vote(Voter *, Candidate *, int);
void display_results(Candidate *);

int main(void)
{
    int num_voters, i, j;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    initialize_candidates(candidates);
    initialize_voters(voters);

    printf("Welcome to the electronic voting system.\n");
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Let's authenticate the voters.\n");
    for(i=0; i<num_voters; i++)
    {
        printf("\nEnter name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        printf("Enter id of voter %d: ", i+1);
        scanf("%d", &voters[i].id);

        if(authenticate_voter(voters, i))
        {
            printf("\nWelcome %s, your id has been authenticated.\n", voters[i].name);
        }
        else
        {
            printf("\nInvalid id or duplicate voter. Please try again.\n");
            i--;
        }
    }

    printf("\nLet's begin the voting process.\n");
    for(i=0; i<num_voters; i++)
    {
        if(!voters[i].has_voted)
        {
            printf("\n%s, please cast your vote.\n", voters[i].name);
            display_candidates(candidates);

            int choice;
            printf("Enter your choice (1-%d): ", MAX_CANDIDATES);
            scanf("%d", &choice);

            if(choice > 0 && choice <= MAX_CANDIDATES)
            {
                cast_vote(&voters[i], &candidates[choice-1], num_voters);
                printf("\nThank you, %s. Your vote has been cast successfully.\n", voters[i].name);
            }
            else
            {
                printf("\nInvalid choice. Please try again.\n");
                i--;
            }
        }
    }

    printf("\nAll voters have cast their votes. Displaying the results.\n");
    display_results(candidates);

    return 0;
}

// Initializes the candidates array with dummy values
void initialize_candidates(Candidate *candidates)
{
    int i;
    for(i=0; i<MAX_CANDIDATES; i++)
    {
        candidates[i].votes = 0;
        sprintf(candidates[i].name, "Candidate %d", i+1);
    }
}

// Initializes the voters array with dummy values
void initialize_voters(Voter *voters)
{
    int i;
    for(i=0; i<MAX_VOTERS; i++)
    {
        voters[i].has_voted = 0;
        sprintf(voters[i].name, "Voter %d", i+1);
        voters[i].id = rand() % 10000 + 1; // generates a random id between 1 and 10000
    }
}

// Authenticates the voter based on their id
int authenticate_voter(Voter *voters, int index)
{
    int i;
    for(i=0; i<index; i++)
    {
        if(voters[i].id == voters[index].id || strlen(voters[index].name) == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Displays the list of candidates
void display_candidates(Candidate *candidates)
{
    int i;
    for(i=0; i<MAX_CANDIDATES; i++)
    {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// Casts the vote for the chosen candidate
void cast_vote(Voter *voter, Candidate *candidate, int num_voters)
{
    candidate->votes++;
    voter->has_voted = 1;
}

// Displays the results of the election
void display_results(Candidate *candidates)
{
    int total_votes = 0, i;
    for(i=0; i<MAX_CANDIDATES; i++)
    {
        total_votes += candidates[i].votes;
    }

    printf("\n");
    printf("Results:\n");
    printf("--------\n");

    for(i=0; i<MAX_CANDIDATES; i++)
    {
        printf("%d. %s - %d votes (%.2f%%)\n", i+1, candidates[i].name, candidates[i].votes, (float)candidates[i].votes/total_votes * 100);
    }
    printf("\n");
}