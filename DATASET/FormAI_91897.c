//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10 // 10x10 grid
#define PERCENTAGE 50 // percentage of sites initially filled

int grid[SIZE][SIZE]; // initialize grid 

// function to print the grid
void printGrid() {
   printf("\n");

   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         if (grid[i][j] == 1) printf("# "); // filled site
         else printf("- "); // empty site
      }
      printf("\n");
   }
   printf("\n");
}

// function to check if the site is filled or not
bool isFilled(int x, int y) {
   if (x < 0 || y < 0 || x >= SIZE || y >= SIZE) return false; // out of bounds
   return (grid[x][y] == 1);
}

// function to check if the site is open or not
bool isOpen(int x, int y) {
   if (x < 0 || y < 0 || x >= SIZE || y >= SIZE) return false; // out of bounds
   return (grid[x][y] == 0);
}

// function to check if the top is open
bool isTopOpen(int x, int y) {
   return isOpen(x-1, y);
}

// function to check if the bottom is open
bool isBottomOpen(int x, int y) {
   return isOpen(x+1, y);
}

// function to check if the left is open
bool isLeftOpen(int x, int y) {
   return isOpen(x, y-1);
}

// function to check if the right is open
bool isRightOpen(int x, int y) {
   return isOpen(x, y+1);
}

// function to check if the site is connected to the top
bool isConnectedToTop(int x, int y) {
   if (x == 0) return true; // top row
   if (isTopOpen(x, y)) return isConnectedToTop(x-1, y); // recursively check the top row
   return false; // not connected
}

// function to check if the site is connected to the bottom
bool isConnectedToBottom(int x, int y) {
   if (x == SIZE-1) return true; // bottom row
   if (isBottomOpen(x, y)) return isConnectedToBottom(x+1, y); // recursively check the bottom row
   return false; // not connected
}

// function to check if the site is connected to the left
bool isConnectedToLeft(int x, int y) {
   if (y == 0) return true; // left column
   if (isLeftOpen(x, y)) return isConnectedToLeft(x, y-1); // recursively check the left column
   return false; // not connected
}

// function to check if the site is connected to the right
bool isConnectedToRight(int x, int y) {
   if (y == SIZE-1) return true; // right column
   if (isRightOpen(x, y)) return isConnectedToRight(x, y+1); // recursively check the right column
   return false; // not connected
}

int main() {
   srand(time(NULL)); // initialize random number generator
   
   // initialize grid
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         if ((rand() % 100) < PERCENTAGE) grid[i][j] = 1; // fill sites randomly
      }
   }

   printGrid(); // print initial grid
   
   // check if any site is connected to both top and bottom
   bool percolates = false;
   for (int i = 0; i < SIZE; i++) {
      if (isConnectedToTop(SIZE-1, i) && isConnectedToBottom(0, i)) {
         percolates = true;
         break;
      }
   }

   if (percolates) printf("The system percolates!\n");
   else printf("The system does not percolate.\n");

   return 0;
}