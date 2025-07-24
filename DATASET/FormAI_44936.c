//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS] = { // example grid
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

typedef struct Point { // Point data structure for a single point on the grid
   int x;
   int y;
} Point;

typedef struct Node { // Node data structure for A* algorithm
   Point point; // point coordinates
   int gScore; // G score for A* algorithm
   int fScore; // F score for A* algorithm
   struct Node* cameFrom; // previous node on optimal path
   struct Node* next; // next node (dependent on open or closed list)
} Node;

Node* createNode(Point point, int gScore, int fScore, Node* cameFrom); // function declaration

Node* aStarAlgorithm(Point start, Point end); // function declaration

int main() { // example usage
   Point start = {1, 1}; // start position
   Point end = {8, 8}; // end position

   Node* optimalPath = aStarAlgorithm(start, end);

   Node* current = optimalPath;
   while(current != NULL) {
      printf("(%d,%d) ", current->point.x, current->point.y);
      current = current->cameFrom; // traverse optimal path backwards from end node
   }

   return 0;
}

Node* createNode(Point point, int gScore, int fScore, Node* cameFrom) {
   Node* node = malloc(sizeof(Node));
   node->point = point;
   node->gScore = gScore;
   node->fScore = fScore;
   node->cameFrom = cameFrom;
   node->next = NULL;

   return node;
}

Node* aStarAlgorithm(Point start, Point end) {
   Node* openList = createNode(start, 0, fmin(abs(start.x - end.x), abs(start.y - end.y)), NULL); // initial node added to open list
   Node* closedList = NULL;

   while(openList != NULL) { // while open list is not empty
      Node* current = openList; // current node is first in open list
      Node* previous = NULL;
      Node* next = current->next;

      while(next != NULL) { // iterate through open list to find node with lowest F score
         if(next->fScore < current->fScore) { // found new current node with lower F score
            current = next;
            previous = (previous == NULL) ? openList : previous->next;
         }

         next = next->next; // move to next node in open list
      }

      if(current->point.x == end.x && current->point.y == end.y) { // end node reached
         return current; // return end node
      }

      if(previous == NULL) { // current node is first in open list
         openList = openList->next;
      } else {
         previous->next = current->next; // remove current node from open list
      }

      current->next = closedList; // add current node to closed list
      closedList = current;

      for(int dx = -1; dx <= 1; dx++) { // iterate through adjacent nodes
         for(int dy = -1; dy <= 1; dy++) {
            if(dx == 0 && dy == 0) { // skip current node
               continue;
            }

            int x = current->point.x + dx;
            int y = current->point.y + dy;

            if(x < 0 || x >= ROWS || y < 0 || y >= COLS) { // check if point is within grid boundaries
               continue;
            }

            if(grid[x][y] == 1) { // check if point is a wall
               continue;
            }

            Node* adjacent = createNode((Point) {x, y}, current->gScore + abs(dx) + abs(dy), fmin(abs(x - end.x), abs(y - end.y)), current); // create new adjacent node

            Node* node = closedList;

            while(node != NULL) { // check if adjacent node is already in closed list
               if(node->point.x == adjacent->point.x && node->point.y == adjacent->point.y) {
                  free(adjacent); // skip adjacent node if already in closed list
                  adjacent = NULL;
                  break;
               }

               node = node->next;
            }

            if(adjacent == NULL) {
               continue;
            }

            node = openList;

            while(node != NULL) { // check if adjacent node is already in open list
               if(node->point.x == adjacent->point.x && node->point.y == adjacent->point.y) {
                  free(adjacent); // skip adjacent node if already in open list
                  adjacent = NULL;

                  if(node->gScore > adjacent->gScore) { // update G score if it is lower in adjacent node
                     node->gScore = adjacent->gScore;
                     node->cameFrom = adjacent->cameFrom;
                  }

                  break;
               }

               node = node->next;
            }

            if(adjacent == NULL) {
               continue;
            }

            node = openList;
            previous = NULL;
            next = openList;

            while(next != NULL && next->fScore < adjacent->fScore) { // insert adjacent node into open list
               previous = next;
               next = next->next;
            }

            if(previous == NULL) { // adjacent node is first in open list
               adjacent->next = openList;
               openList = adjacent;
            } else {
               previous->next = adjacent;
               adjacent->next = next;
            }
         }
      }
   }

   return NULL; // no path exists
}