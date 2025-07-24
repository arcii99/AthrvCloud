//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multiplayer
#include<stdio.h>

//Structure for each player in the game
struct player{
    int id;
    int points;
};

//Function to check for intrusion detection
int detect_intrusion(struct player p[], int num_players){
    int i, j, intrusion=0;
    //Nested loop to compare the points of each player with all other players
    for(i=0; i<num_players; i++){
        for(j=i+1; j<num_players; j++){
            if(p[i].points==p[j].points){ //If two players have the same points
                printf("Intrusion Detected! Players %d and %d have the same points.\n", p[i].id, p[j].id);
                intrusion = 1; //Set intrusion flag to true
            }
        }
    }
    return intrusion; //Returns whether intrusion was detected or not
}

int main(){
    int num_players, i, max_points=0, winner_id;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    struct player players[num_players];
    //Loop to accept player information
    for(i=0; i<num_players; i++){
        printf("Enter the ID for Player %d: ", i+1);
        scanf("%d", &players[i].id);
        printf("Enter the points for Player %d: ", i+1);
        scanf("%d", &players[i].points);
        //If a player has a higher score  update the max_points and winner_id
        if(players[i].points > max_points){
            max_points = players[i].points;
            winner_id = players[i].id;
        }
    }
    if(detect_intrusion(players, num_players)==0){ //If no intrusion detected
        printf("No intrusion detected. Player %d is the winner with %d points.\n", winner_id, max_points);
    }
    return 0; //End of program
}