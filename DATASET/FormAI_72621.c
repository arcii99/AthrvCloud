//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PLAYERS 5

typedef struct player{
    int id;
    float x;
    float y;
    float z;
}Player;

Player players[MAX_PLAYERS];

void generateRandomPositions(){
    srand(time(NULL));
    for(int i=0; i<MAX_PLAYERS; i++){
        Player p;
        p.id = i+1;
        p.x = (float)rand()/RAND_MAX * 100; // random x coordinate between 0 and 100
        p.y = (float)rand()/RAND_MAX * 100; // random y coordinate between 0 and 100
        p.z = (float)rand()/RAND_MAX * 100; // random z coordinate between 0 and 100
        players[i] = p;
    }
}

float calculateDistance(Player p1, Player p2){
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    float dz = p1.z - p2.z;
    return sqrt( dx*dx + dy*dy + dz*dz ); // euclidean distance formula
}

void clusterPlayers(int clusterCount){
    printf("Clustering players into %d clusters..\n", clusterCount);
    int cluster[MAX_PLAYERS];
    float distances[MAX_PLAYERS][MAX_PLAYERS]; // to store distances between players
    for(int i=0; i<MAX_PLAYERS; i++){
        cluster[i] = 0; // initially all players belong to cluster 0
        for(int j=i; j<MAX_PLAYERS; j++){
            if(i == j) distances[i][j] = 0; // same player
            else {
                distances[i][j] = calculateDistance(players[i], players[j]); // calculate distance between players
                distances[j][i] = distances[i][j]; // distances array is symmetric
            }
        }
    }
    for(int c=1; c<=clusterCount; c++){ // iterate over all clusters
        // initialize cluster center with a randomly chosen player
        int centerIndex = rand() % MAX_PLAYERS;
        printf("Cluster %d center : Player %d (%.2f, %.2f, %.2f)\n", c,
                players[centerIndex].id, players[centerIndex].x, players[centerIndex].y, players[centerIndex].z);
        for(int i=0; i<MAX_PLAYERS; i++){
            if(i == centerIndex) cluster[i] = c;
            else if (cluster[i] == c){ // already in cluster c
                if(distances[i][centerIndex] > 10){ // if distance to center is greater than threshold
                    // find the nearest center among all centers
                    int nearestCenter = 0;
                    float minDistance = distances[i][0];
                    for(int j=1; j<=c; j++){
                        float d = distances[i][players[j-1].id-1];
                        if(d < minDistance){
                            minDistance = d;
                            nearestCenter = j;
                        }
                    }
                    printf("Player %d moving from Cluster %d to %d\n", players[i].id, cluster[i], nearestCenter);
                    cluster[i] = nearestCenter;
                }
            }
        }
    }
    // print final clustering results
    for(int c=1; c<=clusterCount; c++){
        printf("Cluster %d : ", c);
        for(int i=0; i<MAX_PLAYERS; i++){
            if(cluster[i] == c) printf("Player %d ", players[i].id);
        }
        printf("\n");
    }
}

int main(){
    generateRandomPositions();
    clusterPlayers(3);
    return 0;
}