//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: random
#include<stdio.h>

//Structure to hold information of each node 
struct node {
   int x, y;   //coordinates of the node
   int g;      //cost to reach the node from start
   int h;      //heuristic cost to reach the goal from the node
   int f;      //total estimated cost of the path
   struct node* parent; //parent of the current node
};

//Function to calculate the Manhattan distance between two nodes
int manhattan_dist(struct node a, struct node b) {
   return abs(a.x - b.x) + abs(a.y - b.y);
}

//Function to check if the given coordinates are within the bounds of the map
int is_valid(int x, int y, int rows, int cols) {
   return (x >= 0 && x < rows && y >= 0 && y < cols);
}

//Function to check if the given node is in the open list
int is_in_open_list(struct node* node, struct node** open_list, int open_list_size) {
   for (int i = 0; i < open_list_size; i++) {
      if (node == open_list[i]) {
         return 1;
      }
   }
   return 0;
}

//Main function to implement A* Pathfinding Algorithm
void a_star_pathfinding(int** map, int rows, int cols, struct node start, struct node goal) {

   //Create an empty open list and a closed list
   struct node* open_list[rows*cols];
   int open_list_size = 0;
   int closed_list[rows][cols];
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         closed_list[i][j] = 0;
      }
   }

   //Initialize the start node 
   start.g = 0;
   start.h = manhattan_dist(start, goal);
   start.f = start.g + start.h;
   open_list[open_list_size] = &start; //push the start node to the open list
   open_list_size++;

   //Loop until the goal is found or the map is fully searched
   while (open_list_size > 0) {

      //Find the node with lowest f value in the open list (tie-breaker: choose the one with lowest h value)
      int min_f_index = 0;
      for (int i = 0; i < open_list_size; i++) {
         if (open_list[i]->f < open_list[min_f_index]->f) {
            min_f_index = i;
         }
         else if (open_list[i]->f == open_list[min_f_index]->f && open_list[i]->h < open_list[min_f_index]->h) {
            min_f_index = i;
         }
      }
      struct node* current = open_list[min_f_index];

      //Remove the current node from the open list and add it to the closed list
      open_list[min_f_index] = open_list[open_list_size - 1];
      open_list_size--;
      closed_list[current->x][current->y] = 1;

      //If the goal is found, reconstruct the path
      if (current->x == goal.x && current->y == goal.y) {
         printf("Path found!\n");
         while (current != NULL) {
            printf("(%d,%d) -> ", current->x, current->y);
            current = current->parent;
         }
         printf("\n");
         return;
      }

      //Generate the neighbors of the current node
      struct node neighbors[4];
      neighbors[0].x = current->x - 1; neighbors[0].y = current->y;
      neighbors[1].x = current->x; neighbors[1].y = current->y - 1;
      neighbors[2].x = current->x + 1; neighbors[2].y = current->y;
      neighbors[3].x = current->x; neighbors[3].y = current->y + 1;
      for (int i = 0; i < 4; i++) {
         //If the neighbor is not traversable or it is in the closed list, skip it
         if (!is_valid(neighbors[i].x, neighbors[i].y, rows, cols) || map[neighbors[i].x][neighbors[i].y] == 1 || closed_list[neighbors[i].x][neighbors[i].y] == 1) {
            continue;
         }

         //Calculate the cost to reach the neighbor from the start and the total estimated cost of the path
         int new_g = current->g + 1; //assuming uniform cost
         int new_h = manhattan_dist(neighbors[i], goal);
         int new_f = new_g + new_h;

         //If the neighbor is already in the open list, update its information if the new path is cheaper
         if (is_in_open_list(&neighbors[i], open_list, open_list_size)) {
            for (int j = 0; j < open_list_size; j++) {
               if (open_list[j] == &neighbors[i]) {
                  if (new_g < neighbors[i].g) {
                     neighbors[i].g = new_g;
                     neighbors[i].f = new_f;
                     neighbors[i].parent = current;
                  }
                  break;
               }
            }
         }
         //Otherwise, add the neighbor to the open list
         else {
            neighbors[i].g = new_g;
            neighbors[i].h = new_h;
            neighbors[i].f = new_f;
            neighbors[i].parent = current;
            open_list[open_list_size] = &neighbors[i];
            open_list_size++;
         }
      }
   }

   //If the goal is not found, print an appropriate message
   printf("Goal not found!\n");
}

int main() {
   //Create a sample map (0 denotes traversable, 1 denotes non-traversable)
   int rows = 5, cols = 6;
   int map[5][6] = {
      {0,0,0,1,0,1},
      {0,0,0,1,0,0},
      {1,1,0,0,1,0},
      {1,1,0,0,1,0},
      {0,0,0,0,0,0}
   };

   //Start node
   struct node start = { 0, 0, 0, 0, 0, NULL };

   //Goal node
   struct node goal = { 4, 5, 0, 0, 0, NULL };

   //Run A* Pathfinding Algorithm
   a_star_pathfinding((int**)map, rows, cols, start, goal);

   return 0;
}