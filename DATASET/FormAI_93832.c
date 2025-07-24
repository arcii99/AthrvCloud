//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random numbers between 0 and 100
int generateRandomNumber() {
    srand(time(NULL));
    int randomNum = rand() % 101;
    return randomNum;
}

int main() {
    //Initializing variables
    int numOfPlayers, numOfCities, numOfAttempts, playerTurn, winner, maxDistance;
    printf("Welcome to the GPS Navigation Simulation! \n\n");
    printf("How many players will be playing today? (2-4): ");
    scanf("%d", &numOfPlayers);
    printf("How many cities will be in this game? (3-10): ");
    scanf("%d", &numOfCities);
    printf("How many attempts will each player get to reach the final destination? (3-5): ");
    scanf("%d", &numOfAttempts);
    printf("\n");

    //Creating arrays to hold information
    char cityNames[numOfCities][50];
    int cityDistances[numOfCities][numOfCities];
    int playerPositions[numOfPlayers][numOfCities];
    for(int i = 0; i < numOfPlayers; i++) {
        for(int j = 0; j < numOfCities; j++) {
            playerPositions[i][j] = -1;
        }
    }

    //Getting city names from user
    for(int i = 0; i < numOfCities; i++) {
        printf("Enter name of city %d: ", i+1);
        scanf("%s", &cityNames[i]);
    }

    //Generating city distances randomly and displaying them
    printf("\nCity Distances:\n");
    for(int i = 0; i < numOfCities; i++) {
        for(int j = 0; j < numOfCities; j++) {
            int distance;
            if(i == j) {
                distance = 0;
            } else {
                distance = generateRandomNumber();
            }
            cityDistances[i][j] = distance;
            printf("%d ", distance);
        }
        printf("\n");
    }

    //Getting starting positions from user
    printf("\nStarting Positions:\n");
    for(int i = 0; i < numOfPlayers; i++) {
        for(int j = 0; j < numOfCities; j++) {
            printf("Enter %s position for player %d (0-%d): ", cityNames[j], i+1, numOfCities-1);
            int position;
            scanf("%d", &position);
            playerPositions[i][j] = position;
        }
        printf("\n");
    }

    //Starting game
    winner = -1;
    maxDistance = -1;
    for(int i = 0; i < numOfAttempts; i++) {
        for(int j = 0; j < numOfPlayers; j++) {
            playerTurn = j+1;
            printf("It's player %d's turn! \n", playerTurn);
            for(int k = 0; k < numOfCities-1; k++) {
                int currentPosition = playerPositions[j][k];
                int nextCity = -1;
                int nextCityDistance = -1;
                for(int l = 0; l < numOfCities; l++) {
                    if(cityDistances[currentPosition][l] > nextCityDistance && playerPositions[j][l] == -1) {
                        nextCityDistance = cityDistances[currentPosition][l];
                        nextCity = l;
                    }
                }
                playerPositions[j][nextCity] = nextCity;
                printf("Player %d has moved to %s (Distance: %d) \n", playerTurn, cityNames[nextCity], nextCityDistance);
                if(nextCity == numOfCities-1) {
                    winner = playerTurn;
                    break;
                }
            }
            if(winner != -1) {
                printf("Player %d has won the game! \n", winner);
                break;
            }
        } 
        if(winner != -1) {
            break;
        }
    }
    if(winner == -1) {
        printf("No one has won the game :( \n");
    }
    return 0;
}