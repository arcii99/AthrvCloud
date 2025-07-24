//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printStarMap(int stars[10][10], int visited[10][10], int currentX, int currentY);
void printShipStatus(int fuel, int food, int health);
void printGameEnd();

int main(){
    srand(time(NULL)); //initialize random seed
    
    //initialize game variables
    int stars[10][10]; //stars array, 0 indicates unvisited, 1 indicates visited
    int visited[10][10]; //visited array, 0 indicates unvisited, 1 indicates visited
    int fuel = 100;
    int food = 100;
    int health = 100;
    int currentX = rand() % 10; //random starting position
    int currentY = rand() % 10;
    
    //initialize star map
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            stars[i][j] = rand() % 2; //randomly assign stars
            visited[i][j] = 0; //initialize all as unvisited
        }
    }
    
    //game loop
    while(1){
        printStarMap(stars, visited, currentX, currentY);
        printShipStatus(fuel, food, health);
        printf("Choose your move (WASD): ");
        char move = getchar();
        getchar(); //remove the newline character
        
        switch(move){
            case 'W':
                currentX--;
                break;
            case 'A':
                currentY--;
                break;
            case 'S':
                currentX++;
                break;
            case 'D':
                currentY++;
                break;
            default:
                printf("Invalid move!\n");
                continue;
        }
        
        //check for out of bounds
        if(currentX < 0 || currentX > 9 || currentY < 0 || currentY > 9){
            printf("Out of bounds!\n");
            if(currentX < 0) currentX++;
            else if(currentX > 9) currentX--;
            else if(currentY < 0) currentY++;
            else if(currentY > 9) currentY--;
            continue;
        }
        
        //check for visited star
        if(stars[currentX][currentY] && !visited[currentX][currentY]){
            printf("Visited star!\n");
            visited[currentX][currentY] = 1;
            fuel += rand() % 21 + 10; //randomly refill fuel (10-30 units)
            food += rand() % 21 + 10; //randomly refill food (10-30 units)
            health += rand() % 11; //randomly heal (0-10 health)
        }
        
        //resource depletion
        fuel--;
        food--;
        health--;
        
        //check for game over
        if(fuel <= 0 || food <= 0 || health <= 0){
            printGameEnd();
            break;
        }
    }
    
    return 0;
}

void printStarMap(int stars[10][10], int visited[10][10], int currentX, int currentY){
    printf("\n");
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(currentX == i && currentY == j) printf("X"); //current position
            else if(visited[i][j]) printf("$"); //visited star
            else printf("%d", stars[i][j]); //unvisited star
            printf(" ");
        }
        printf("\n");
    }
}

void printShipStatus(int fuel, int food, int health){
    printf("Fuel: %d, Food: %d, Health: %d\n", fuel, food, health);
}

void printGameEnd(){
    printf("\nGame over!\n");
    printf("You died in the vacuum of space.\n");
}