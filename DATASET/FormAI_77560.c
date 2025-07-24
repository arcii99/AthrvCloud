//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The total number of voters allowed to vote in the election
#define MAX_VOTERS 1000

// The total number of parties participating in the election
#define MAX_PARTIES 10

// A structure to hold information about a particular party
struct Party{
    char name[50];     // Name of the party
    int votes;         // Number of votes casted for this party
};

// A structure to hold information about a particular voter
struct Voter{
    int id;            // Unique ID of the voter
    char name[50];     // Name of the voter
    int voted;         // Whether or not the voter has voted
    int party;         // Party that the voter has voted for
};

// A global array of parties containing name and vote counts
struct Party parties[MAX_PARTIES];

// A global array of voters containing their name, ID, and voting status
struct Voter voters[MAX_VOTERS];

// Function to initialize the parties
void init_parties(){
    strcpy(parties[0].name, "Party A");
    strcpy(parties[1].name, "Party B");
    strcpy(parties[2].name, "Party C");
    strcpy(parties[3].name, "Party D");
    strcpy(parties[4].name, "Party E");
    strcpy(parties[5].name, "Party F");
    strcpy(parties[6].name, "Party G");
    strcpy(parties[7].name, "Party H");
    strcpy(parties[8].name, "Party I");
    strcpy(parties[9].name, "Party J");
}

// Function to initialize the voters
void init_voters(){
    for(int i = 0; i < MAX_VOTERS; i++){
        voters[i].id = i;
        sprintf(voters[i].name, "Voter %d", i);
        voters[i].voted = 0;
        voters[i].party = -1;
    }
}

// Function to display the menu and take input from the user
int display_menu(){
    printf("\n\n1. Cast your vote");
    printf("\n2. Display polling results");
    printf("\n3. Exit");
    printf("\n\nEnter your choice: ");

    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function to display the list of parties in the election
void display_parties(){
    printf("\n\nThe following parties are participating in the election:\n\n");
    for(int i = 0; i < MAX_PARTIES; i++){
        printf("%d. %s\n", i+1, parties[i].name);
    }
    printf("\n");
}

// Function to cast a vote
void cast_vote(){
    int id, party;

    printf("\n\nEnter your voter ID: ");
    scanf("%d", &id);

    if(id < 0 || id >= MAX_VOTERS){
        printf("\n\nInvalid voter ID");
        return;
    }

    if(voters[id].voted){
        printf("\n\nYou have already voted!");
        return;
    }

    display_parties();

    printf("\n\nEnter the party number you wish to vote for: ");
    scanf("%d", &party);

    if(party < 1 || party > MAX_PARTIES){
        printf("\n\nInvalid party choice!");
        return;
    }

    printf("\n\nYou have casted your vote for %s\n\n", parties[party-1].name);

    // Update the vote counts for this party
    parties[party-1].votes++;

    // Update the voter's status
    voters[id].voted = 1;
    voters[id].party = party-1;
}

// Function to display polling results
void display_results(){
    printf("\n\n\t\tElection Results\n\n");

    for(int i = 0; i < MAX_PARTIES; i++){
        printf("%s : %d votes\n", parties[i].name, parties[i].votes);
    }
}

int main(){
    init_parties();
    init_voters();

    while(1){
        int choice = display_menu();

        switch(choice){
            case 1:
                cast_vote();
                break;

            case 2:
                display_results();
                break;

            case 3:
                printf("\n\nThank you for using the electronic voting system!\n\n");
                exit(0);

            default:
                printf("\n\nInvalid choice!");
        }
    }

    return 0;
}