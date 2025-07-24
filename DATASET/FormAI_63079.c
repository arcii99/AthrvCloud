//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: excited
#include<stdio.h>

int main(){
    
    printf("Welcome to the exciting world of Pathfinding!\n");
    printf("Today, we are going to implement a unique Pathfinding algorithm\n");
    printf("Are you ready? Let's get started!\n\n");
    
    //Initializing the grid
    int grid[10][10];
    
    //Setting all values to 0
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            grid[i][j]=0;
        }
    }
    
    //Setting the start and end points
    grid[0][0]=1;
    grid[9][9]=2;
    
    //Printing the initial state of the grid
    printf("The initial state of the grid is:\n");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    
    printf("\nNow comes the exciting part - the Pathfinding!\n");
    printf("We are going to use a unique Pathfinding algorithm which we call 'Zig-Zag'.\n");
    printf("It's a combination of the well-known 'A*' algorithm and some creative thinking.\n\n");
    
    //Implementing the Pathfinding algorithm
    int currentX = 0;
    int currentY = 0;

    while(grid[currentX][currentY] != 2){
        int newX, newY;
        if(currentX > 8 && currentY < 9){
            newX = currentX;
            newY = currentY+1;
        }else if(currentY > 8 && currentX < 9){
            newX = currentX+1;
            newY = currentY;
        }else if((currentX+currentY)%2 == 0 && currentY!=9){
            newX = currentX;
            newY = currentY+1;
        }else if((currentX+currentY)%2 == 0 && currentY==9){
            newX = currentX+1;
            newY = currentY;
        }else if((currentX+currentY)%2 != 0 && currentX!=9){
            newX = currentX+1;
            newY = currentY;
        }else if((currentX+currentY)%2 != 0 && currentX==9){
            newX = currentX;
            newY = currentY+1;
        }
        currentX = newX;
        currentY = newY;
    }
    
    //Printing the final state of the grid
    printf("The final state of the grid is:\n");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    
    printf("\nWoo-hoo! We found the path using our unique 'Zig-Zag' algorithm.\n");
    printf("I hope you enjoyed this exciting journey through the world of Pathfinding!\n");
    printf("See you soon with more exciting stuff!\n");
    
    return 0;
}