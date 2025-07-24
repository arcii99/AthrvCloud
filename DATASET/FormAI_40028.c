//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: cheerful
// Welcome to the world of pathfinding algorithms!
// Today, we'll be implementing a unique algorithm that will guarantee to bring a smile on your face.
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

//Our custom pathfinding algorithm that takes a cheerful approach
int* cheerful_pathfinding(int graph[ROWS][COLS], int startRow, int startCol, int targetRow, int targetCol) {

   // Initializing visited array to keep track of visited nodes
   bool visited[ROWS][COLS];
   for (int row = 0; row < ROWS; row++) {
      for (int col = 0; col < COLS; col++) {
         visited[row][col] = false;
      }
   }

   // Initializing queue for BFS
   int queue[ROWS * COLS][2]; 
   int front = 0;
   int rear = 0;
   queue[rear][0] = startRow;
   queue[rear][1] = startCol;
   front = rear = 0;
   visited[startRow][startCol] = true;

   // Let's start the cheerful BFS algorithm
   while (front <= rear) { 
      
      // Let's get the current front element and move to next element
      int row = queue[front][0];
      int col = queue[front][1];
      front++;

      //Stopping condition: if we have reached the target row and column
      if (row == targetRow && col == targetCol) {
         // Here's the cheerful part where we print our success message
         printf("Hooray! We have found the target row = %d and column = %d\n", targetRow, targetCol);
         //We'll now return the shortest path as an array of integers
         int* shortestPath = malloc(sizeof(int) * ROWS * COLS);
         shortestPath[0] = graph[targetRow][targetCol];
         shortestPath[1] = row;
         shortestPath[2] = col;
         return shortestPath;
      }

      // Let's move in all 4 directions possible
      //Firstly, let's move right
      if (col + 1 < COLS && !visited[row][col + 1]) {
         visited[row][col + 1] = true;
         graph[row][col + 1] = graph[row][col] + 1; //We'll update our graph here with the latest shortest distance
         queue[++rear][0] = row;
         queue[rear][1] = col + 1;
      }

      //Let's move Left
      if (col - 1 >= 0 && !visited[row][col - 1]) {
         visited[row][col - 1] = true;
         graph[row][col - 1] = graph[row][col] + 1;
         queue[++rear][0] = row;
         queue[rear][1] = col - 1;
      }

      //Let's move Up
      if (row - 1 >= 0 && !visited[row - 1][col]) {
         visited[row - 1][col] = true;
         graph[row - 1][col] = graph[row][col] + 1;
         queue[++rear][0] = row - 1;
         queue[rear][1] = col;
      }

      //Let's move Down
      if (row + 1 < ROWS && !visited[row + 1][col]) {
         visited[row + 1][col] = true;
         graph[row + 1][col] = graph[row][col] + 1;
         queue[++rear][0] = row + 1;
         queue[rear][1] = col;
      }
   }
}

//Driver program to test our cheerful pathfinding algorithm
int main() {

   int graph[ROWS][COLS] = { {1, 1, 1, 1, 1},
                             {1, 0, 0, 1, 0},
                             {1, 1, 1, 1, 0},
                             {0, 0, 0, 1, 0},
                             {1, 1, 1, 1, 1} };

   //Let's try to find shortest path from (0, 0) to (ROW-1, COL-1)
   int* shortestPath = cheerful_pathfinding(graph, 0, 0, ROWS - 1, COLS - 1);
   printf("\nShortest path: ");
   for (int i = 0; shortestPath[i]; ++i) {
      printf("%d ", shortestPath[i]);
   }
   
   //Let's free our dynamically allocated memory
   free(shortestPath);

   return 0;
}