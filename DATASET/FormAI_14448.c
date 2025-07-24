//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define P 0.6

int grid[MAX][MAX], opened[MAX][MAX];

void initialize(){
	//initialize all cells to be not opened
	for(int i=1; i<=MAX; i++){
		for(int j=1; j<=MAX; j++){
			opened[i][j] = 0;
		}
	}

	//initialize border cells to be opened
	for(int i=0; i<=MAX+1; i++){
		opened[i][0] = 1;
		opened[0][i] = 1;
		opened[i][MAX+1] = 1;
		opened[MAX+1][i] = 1;
	}
}

void show(){
	//print grid
	for(int i=1; i<=MAX; i++){
		for(int j=1; j<=MAX; j++){
			if(opened[i][j]){
				printf("1 ");
			}
			else{
				printf("%d ", grid[i][j]);
			}
		}
		printf("\n");
	}
}

int percolate(){
	//check if there is a path from top to bottom
	for(int j=1; j<=MAX; j++){
		if(opened[MAX][j]){
			return 1;
		}
	}
	return 0;
}

void openSite(int row, int col){
	//open a cell and connect it to neighboring cells if they are already open
	opened[row][col] = 1;

	if(opened[row+1][col]){
		grid[row][col] = 1;
		grid[row+1][col] = 1;
	}
	if(opened[row-1][col]){
		grid[row][col] = 1;
		grid[row-1][col] = 1;
	}
	if(opened[row][col+1]){
		grid[row][col] = 1;
		grid[row][col+1] = 1;
	}
	if(opened[row][col-1]){
		grid[row][col] = 1;
		grid[row][col-1] = 1;
	}
}

int main(){
	//seed random number generator
	srand(time(0));

	//initialize grid
	for(int i=1; i<=MAX; i++){
		for(int j=1; j<=MAX; j++){
			if((float)rand()/(float)RAND_MAX < P){
				grid[i][j] = 1;
			}
			else{
				grid[i][j] = 0;
			}
		}
	}

	//initialize percolation
	initialize();

	//open top row
	for(int j=1; j<=MAX; j++){
		openSite(1,j);
	}

	//percolation
	while(!percolate()){
		//choose random cell
		int i = rand() % MAX + 1;
		int j = rand() % MAX + 1;

		//if closed, open it
		if(!opened[i][j]){
			openSite(i,j);
		}
	}

	//show final grid
	show();

	return 0;
}