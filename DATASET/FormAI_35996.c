//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rows, cols; //Variable for map size

//Function to create and initialize map with random walls and floors
void create_map(int map[rows][cols]){
    srand(time(NULL)); //Seed for random number generation
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(i==0 || i==rows-1 || j==0 || j==cols-1){ //Border walls
                map[i][j] = 1;
            }else{
                map[i][j] = rand() % 2; //Random wall or floor
            }
        }
    }
}

//Function to print map to console
void print_map(int map[rows][cols]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(map[i][j] == 1){ //Wall
                printf("#");
            }else{ //Floor
                printf(".");
            }
        }
        printf("\n");
    }
}

int main(){
    //User input for map size
    printf("Enter number of rows for map: ");
    scanf("%d", &rows);
    printf("Enter number of columns for map: ");
    scanf("%d", &cols);

    int map[rows][cols];

    create_map(map);

    print_map(map);

    return 0;
}