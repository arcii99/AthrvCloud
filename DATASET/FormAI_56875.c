//FormAI DATASET v1.0 Category: Graph representation ; Style: medieval
#include<stdio.h>
#define ROW 10
#define COL 10

int graph[ROW][COL] = {
	{0,1,0,1,0,0,0,0,0,0},
	{1,0,1,1,0,0,0,0,0,0},
	{0,1,0,0,1,0,0,0,0,0},
	{1,1,0,0,1,1,0,0,0,0},
	{0,0,1,1,0,1,1,0,0,0},
	{0,0,0,1,1,0,0,1,0,0},
	{0,0,0,0,1,0,0,1,1,0},
	{0,0,0,0,0,1,1,0,1,1},
	{0,0,0,0,0,0,1,1,0,1},
	{0,0,0,0,0,0,0,1,1,0}
};

void printGraph(){
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			if(graph[i][j] == 0){
				printf(" - ");
			}else{
				printf(" | ");
			}
		}
		printf("\n");
	}
}

int main(){
	printf("Medieval Graph Representation Example\n");
	printf("------------------------------------\n\n");

	//Printing the Graph
	printGraph();

	return 0;
}