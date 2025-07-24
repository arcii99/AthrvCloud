//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h> 

// function declarations 
void explorePlanet(int planetID, int explorationTime); 

// async function to start exploring new planet 
void asyncExplorePlanet(void *args) { 
    int *planetDetails = (int *) args; 
    int planetID = planetDetails[0]; 
    int explorationTime = planetDetails[1]; 

    // delay to simulate exploration time 
    sleep(explorationTime); 
    // calling the exploration function 
    explorePlanet(planetID, explorationTime); 
} 

// function to explore a planet 
void explorePlanet(int planetID, int explorationTime) { 
    printf("Exploring planet %d for %d seconds\n", planetID, explorationTime); 
    // generating a random number to determine the presence of aliens 
    srand(time(NULL)); 
    int aliens = rand() % 2; 
    if (aliens == 1) { 
        printf("Aliens detected on planet %d!\n", planetID); 
    } else { 
        printf("No aliens detected on planet %d\n", planetID); 
    } 
} 

int main() { 
    // array of planets to explore 
    int planets[5][2] = {{1, 5}, {2, 3}, {3, 7}, {4, 2}, {5, 4}}; 

    // starting exploration of planets asynchronously 
    for (int i = 0; i < 5; i++) { 
        int *planetDetails = planets[i]; 
        pthread_t threadID; 
        pthread_create(&threadID, NULL, asyncExplorePlanet, planetDetails); 
        // delay to simulate traveling time to next planet 
        sleep(2); 
    } 
    return 0; 
}