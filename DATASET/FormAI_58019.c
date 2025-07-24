//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAMELEN 10
#define MAXPLAYERS 4
#define MAXRANK 100

typedef struct Player {
    char name[NAMELEN];
    int rank;
}Player;

int main() {
    Player players[MAXPLAYERS];
    char tempName[NAMELEN];
    int i,j,numPlayers;
    printf("Enter the number of players(1-4):");
    scanf("%d",&numPlayers);
    while(numPlayers < 1 || numPlayers > 4) {
        printf("Please enter a valid number of players(1-4):");
        scanf("%d",&numPlayers);
    }
    printf("Enter the names and ranks of the players:\n");
    for(i=0;i<numPlayers;i++) {
        printf("Enter name of player %d:",i+1);
        scanf("%s",tempName);
        for(j=0;j<strlen(tempName);j++) {
            if(tempName[j] >= 'A' && tempName[j] <= 'Z') {
                tempName[j] += 32; //converting uppercase to lowercase
            }
        }
        strncpy(players[i].name,tempName,NAMELEN); //copying the sanitized name to player struct
        printf("Enter rank of player %d:",i+1);
        scanf("%d",&players[i].rank);
        while(players[i].rank < 0 || players[i].rank > MAXRANK) {
            printf("Please enter a valid rank between 0 and 100:");
            scanf("%d",&players[i].rank);
        }
    }
    printf("The entered player data is:\n");
    for(i=0;i<numPlayers;i++) {
        printf("%s : %d\n",players[i].name,players[i].rank);
    }
    return 0;
}