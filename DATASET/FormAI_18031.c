//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define maxVertices 100

int numOfPlayers, playerScore[maxVertices]; // to keep track of scores of each player
int scores[maxVertices][maxVertices]; // to keep track of scores of each node by each player
int graph[maxVertices][maxVertices]; // to represent the graph
int numOfVertices, numOfEdges; // to keep track of number of vertices and edges in the graph
int numOfColors; // to keep track of the number of colors available

//Function prototypes
void initialize();
void generateGraph();
void shufflePlayers();
void assignColorToVertex(int vertex, int color, int player);
void printGraph();
void printScores();
int isSafe(int vertex, int color, int player);
int fillColors(int vertex, int player, int availableColors[]);

//Function to initialize variables and generate graph randomly
void initialize(){
    int i, j;
    for(i=0; i<maxVertices; i++){
        playerScore[i] = 0;
        for(j=0; j<maxVertices; j++){
            graph[i][j] = 0;
            scores[i][j] = 0;
        }
    }
    numOfVertices = rand() % maxVertices + 1;
    numOfEdges = rand() % (numOfVertices * (numOfVertices-1) / 2) + 1;
    numOfColors = rand() % numOfVertices + 1;
    generateGraph();
    shufflePlayers();
    printf("\n\nGenerated graph:\n\n");
    printGraph();
    printf("\n\nScores matrix:\n\n");
    printScores();
}

//Function to generate random graph having given number of vertices and edges
void generateGraph(){
    int i, j, x, y;
    for(i=0; i<numOfEdges; i++){
        do{
            x = rand() % numOfVertices;
            y = rand() % numOfVertices;
        }while(x==y || graph[x][y] != 0);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
}

//Function to shuffle players
void shufflePlayers(){
    int i, j, k, tempScore, tempNum, randomNumber;
    numOfPlayers = rand() % maxVertices + 1;
    printf("\n\nNumber of players: %d\n\n", numOfPlayers);
    for(i=0; i<numOfPlayers; i++){
        playerScore[i] = 0;
        for(j=0; j<numOfVertices; j++){
            for(k=0; k<numOfPlayers; k++){
                scores[j][k] = 0;
            }
        }
    }
    for(i=0; i<numOfVertices; i++){
        for(j=0; j<numOfPlayers; j++){
            for(k=0; k<numOfPlayers; k++){
                scores[i][j] = rand() % maxVertices + 1;
            }
        }
    }
    for(i=0; i<numOfPlayers; i++){
        randomNumber = rand() % numOfPlayers;
        tempScore = playerScore[i];
        playerScore[i] = playerScore[randomNumber];
        playerScore[randomNumber] = tempScore;
        for(j=0; j<numOfVertices; j++){
            tempNum = scores[j][i];
            scores[j][i] = scores[j][randomNumber];
            scores[j][randomNumber] = tempNum;
        }
    }
}

//Function to print the graph
void printGraph(){
    int i, j;
    for(i=0; i<numOfVertices; i++){
        for(j=0; j<numOfVertices; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

//Function to print scores matrix
void printScores(){
    int i, j;
    for(i=0; i<numOfVertices; i++){
        for(j=0; j<numOfPlayers; j++){
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }
}

//Function to check if it is safe to color the vertex with given color by given player
int isSafe(int vertex, int color, int player){
    int i;
    for(i=0; i < numOfVertices; i++){
        if(graph[vertex][i] && scores[vertex][player] == scores[i][player] && color == playerScore[i]){
            return 0;
        }
    }
    return 1;
}

//Function to assign color to vertex by given player
void assignColorToVertex(int vertex, int color, int player){
    playerScore[vertex] = color;
}

//Function to fill colors available for given vertex and player
int fillColors(int vertex, int player, int availableColors[]){
    int i, j=0;
    for(i=1; i<=numOfColors; i++){
        if(isSafe(vertex, i, player)){
            availableColors[j++] = i;
        }
    }
    return j;
}

//Main function
int main(){
    srand(time(NULL));
    initialize();
    int i, j, flag=1;
    int availableColors[maxVertices], numOfAvailableColors, currentPlayer=0;
    printf("\n\nColoring started:\n\n");
    while(flag){
        flag = 0;
        for(i=0; i<numOfVertices; i++){
            if(playerScore[i] == 0){
                numOfAvailableColors = fillColors(i, currentPlayer, availableColors);
                if(numOfAvailableColors == 0){
                    flag = 1;
                    continue;
                }
                assignColorToVertex(i, availableColors[rand() % numOfAvailableColors], currentPlayer);
            }
        }
        currentPlayer = (currentPlayer + 1) % numOfPlayers;
    }
    printf("\n\nFinal scores:\n\n");
    for(i=0; i<numOfPlayers; i++){
        printf("Player %d: %d\n", i+1, playerScore[i]);
    }
    return 0;
}